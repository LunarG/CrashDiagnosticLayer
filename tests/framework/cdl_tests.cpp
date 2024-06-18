/*
 * Copyright (c) 2015-2024 The Khronos Group Inc.
 * Copyright (c) 2015-2024 Valve Corporation
 * Copyright (c) 2015-2024 LunarG, Inc.
 * Copyright (c) 2015-2023 Google, Inc.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 */
#include <gtest/gtest.h>
#include <glslang/Public/ShaderLang.h>
#include <filesystem>

#if defined(_WIN32)
#include <windows.h>
#elif defined(VK_USE_PLATFORM_ANDROID_KHR)
#include <android/log.h>
#include <android_native_app_glue.h>
#include <sys/system_properties.h>
#include <unistd.h>
#else
#include <unistd.h>
#endif

#include <filesystem>

#include "config.h"
#include "test_fixtures.h"

std::string GetEnvironment(const char *variable) {
#if !defined(__ANDROID__) && !defined(_WIN32)
    const char *output = getenv(variable);
    return output == NULL ? "" : output;
#elif defined(_WIN32)
    int size = GetEnvironmentVariable(variable, NULL, 0);
    if (size == 0) {
        return "";
    }
    char *buffer = new char[size];
    GetEnvironmentVariable(variable, buffer, size);
    std::string output = buffer;
    delete[] buffer;
    return output;
#elif defined(__ANDROID__)
    std::string var = "debug.cdl." + variable;

    const prop_info *prop_info = __system_property_find(var.data());

    if (prop_info) {
        std::string property;
        __system_property_read_callback(prop_info, PropCallback, &property);
        return property;
    } else {
        return "";
    }
#else
    return "";
#endif
}

void SetEnvironment(const char *variable, const char *value) {
#if !defined(__ANDROID__) && !defined(_WIN32)
    setenv(variable, value, 1);
#elif defined(_WIN32)
    SetEnvironmentVariable(variable, value);
#elif defined(__ANDROID__)
    (void)variable;
    (void)value;
    assert(false && "Not supported on android");
#endif
}

#if !defined(VK_USE_PLATFORM_ANDROID_KHR)
// NOTE: Android doesn't use environment variables like desktop does!
//
// Certain VK_* environment variables accept lists.
// Return a vector of std::string containing each member in the list.
//
// EX input:
//  export VK_DRIVER_FILES=/intel.json:/amd.json
//  set VK_DRIVER_FILES=\nvidia.json;\mesa.json
static std::vector<std::string> GetVkEnvironmentVariable(const char *env_var) {
    const std::string str = GetEnvironment(env_var);
    if (str.empty()) {
        return {};
    }

    // Loader uses standard OS path separators per platform
    constexpr char delimiter =
#ifdef _WIN32
        ';';
#else
        ':';
#endif

    std::vector<std::string> items;
    std::string::size_type start = 0;

    std::string::size_type pos = str.find_first_of(delimiter, start);
    std::string::size_type length = pos;
    while (pos != std::string::npos) {
        // emplace uses std::substr which takes length from start
        items.emplace_back(str, start, length);

        start = pos + 1;

        pos = str.find_first_of(delimiter, start);

        length = pos - start;
    }
    items.emplace_back(str, start);

    return items;
}

static void CheckAndSetEnvironmentVariables() {
    if (!CDLTestBase::no_mock_icd_) {
        std::filesystem::path icd_path{kMockICDBuildPath};
        icd_path /= "CDL_Test_ICD.json";
        std::string path_str = icd_path.string();
        SetEnvironment("VK_ICD_FILENAMES", path_str.c_str());
    }
    for (const char *env_var : {"VK_DRIVER_FILES", "VK_ICD_FILENAMES"}) {
        const std::vector<std::string> driver_files = GetVkEnvironmentVariable(env_var);
        for (const std::string &driver_file : driver_files) {
            const std::filesystem::path icd_file(driver_file);
            // TODO: Error check relative paths (platform dependent)
            if (icd_file.is_relative()) {
                continue;
            }
            std::string user_provided;
            user_provided += "\n\n";
            user_provided += env_var;
            user_provided += " = ";
            user_provided += driver_file;
            if (std::filesystem::is_directory(icd_file)) {
                if (!std::filesystem::exists(icd_file)) {
                    std::cerr << "Invalid " << env_var << "! Directory doesn't exist!" << user_provided << std::endl;
                    std::exit(EXIT_FAILURE);
                }
                bool contains_json = false;
                for (auto const &dir_entry : std::filesystem::directory_iterator{icd_file}) {
                    if (dir_entry.path().extension() == ".json") {
                        contains_json = true;
                    }
                }
                if (!contains_json) {
                    std::cerr << "Invalid " << env_var << "! " << env_var << " must contain a json file!"
                              << user_provided << std::endl;
                    std::exit(EXIT_FAILURE);
                }

            } else {
                if (!std::filesystem::exists(icd_file)) {
                    std::cerr << "Invalid " << env_var << "! File doesn't exist!" << user_provided << std::endl;
                    std::exit(EXIT_FAILURE);
                }

                if (icd_file.extension() != ".json") {
                    std::cerr << "Invalid " << env_var << "! " << env_var << " must be a json file!" << user_provided
                              << std::endl;
                    std::exit(EXIT_FAILURE);
                }
            }
        }
    }

    bool found_json = false;
    bool vk_layer_env_vars_present = false;
    std::stringstream error_log;  // Build up error log in case the CDL json cannot be found
    for (const char *env_var : {"VK_LAYER_PATH", "VK_ADD_LAYER_PATH"}) {
        const std::vector<std::string> vk_layer_paths = GetVkEnvironmentVariable(env_var);
        if (!vk_layer_paths.empty()) {
            vk_layer_env_vars_present = true;
        }
        for (const std::string &vk_layer_path : vk_layer_paths) {
            const std::filesystem::path layer_path(vk_layer_path);

            if (!std::filesystem::exists(layer_path)) {
                error_log << "Invalid " << env_var << "! " << layer_path << " doesn't exist." << std::endl;
                continue;
            }

            if (std::filesystem::is_directory(layer_path)) {
                for (auto const &dir_entry : std::filesystem::directory_iterator{layer_path}) {
                    if (dir_entry.path().filename() == kLayerJsonFile) {
                        if (std::filesystem::exists(dir_entry)) {
                            found_json = true;
                            break;
                        } else {
                            error_log << "Invalid " << env_var << "! " << dir_entry << " doen not exist!" << std::endl;
                        }
                    }
                }
                if (!found_json) {
                    error_log << "Invalid " << env_var << "! " << layer_path << " is a directory but doesn't contain a "
                              << kLayerJsonFile << " file!" << std::endl;
                }
            } else {
                if (layer_path.filename() == kLayerJsonFile) {
                    found_json = true;
                    break;
                } else {
                    error_log << "Invalid " << env_var << "! The filename of path" << layer_path << " is not "
                              << kLayerJsonFile << "!" << std::endl;
                }
            }
            if (found_json) {
                break;
            }
        }
    }

    if (!found_json) {
        if (vk_layer_env_vars_present) {
            std::cerr << error_log.str() << std::endl;
            std::cerr << "Automatically setting VK_LAYER_PATH to " << kLayerBuildPath << std::endl;
        }
        SetEnvironment("VK_LAYER_PATH", kLayerBuildPath);
    }
}
#endif

class TestEnvironment : public ::testing::Environment {
   public:
    void SetUp();
    void TearDown();
};

void TestEnvironment::SetUp() {
#if !defined(VK_USE_PLATFORM_ANDROID_KHR)
    // Helps ensure common developer environment variables are set correctly
    CheckAndSetEnvironmentVariables();
#endif
    glslang::InitializeProcess();

    std::filesystem::remove_all(kTestOutputBaseDir);
}
void TestEnvironment::TearDown() { glslang::FinalizeProcess(); }

void print_android(const char *c) {
#ifdef VK_USE_PLATFORM_ANDROID_KHR
    __android_log_print(ANDROID_LOG_INFO, "CrashDiagnosticLayerTests", "%s", c);
#endif  // VK_USE_PLATFORM_ANDROID_KHR
}

#if defined(VK_USE_PLATFORM_ANDROID_KHR)
const char *appTag = "CrashDiagnosticLayerTests";
static bool initialized = false;
static bool active = false;

// Convert Intents to argv
// Ported from Hologram sample, only difference is flexible key
std::vector<std::string> get_args(android_app &app, const char *intent_extra_data_key) {
    std::vector<std::string> args;
    JavaVM &vm = *app.activity->vm;
    JNIEnv *p_env;
    if (vm.AttachCurrentThread(&p_env, nullptr) != JNI_OK) return args;

    JNIEnv &env = *p_env;
    jobject activity = app.activity->clazz;
    jmethodID get_intent_method =
        env.GetMethodID(env.GetObjectClass(activity), "getIntent", "()Landroid/content/Intent;");
    jobject intent = env.CallObjectMethod(activity, get_intent_method);
    jmethodID get_string_extra_method =
        env.GetMethodID(env.GetObjectClass(intent), "getStringExtra", "(Ljava/lang/String;)Ljava/lang/String;");
    jvalue get_string_extra_args;
    get_string_extra_args.l = env.NewStringUTF(intent_extra_data_key);
    jstring extra_str =
        static_cast<jstring>(env.CallObjectMethodA(intent, get_string_extra_method, &get_string_extra_args));

    std::string args_str;
    if (extra_str) {
        const char *extra_utf = env.GetStringUTFChars(extra_str, nullptr);
        args_str = extra_utf;
        env.ReleaseStringUTFChars(extra_str, extra_utf);
        env.DeleteLocalRef(extra_str);
    }

    env.DeleteLocalRef(get_string_extra_args.l);
    env.DeleteLocalRef(intent);
    vm.DetachCurrentThread();

    // split args_str
    std::stringstream ss(args_str);
    std::string arg;
    while (std::getline(ss, arg, ' ')) {
        if (!arg.empty()) args.push_back(arg);
    }

    return args;
}

void addFullTestCommentIfPresent(const ::testing::TestInfo &test_info, std::string &error_message) {
    const char *const type_param = test_info.type_param();
    const char *const value_param = test_info.value_param();

    if (type_param != NULL || value_param != NULL) {
        error_message.append(", where ");
        if (type_param != NULL) {
            error_message.append("TypeParam = ").append(type_param);
            if (value_param != NULL) error_message.append(" and ");
        }
        if (value_param != NULL) {
            error_message.append("GetParam() = ").append(value_param);
        }
    }
}

class LogcatPrinter : public ::testing::EmptyTestEventListener {
    // Called before a test starts.
    virtual void OnTestStart(const ::testing::TestInfo &test_info) {
        __android_log_print(ANDROID_LOG_INFO, appTag, "[ RUN      ] %s.%s", test_info.test_case_name(),
                            test_info.name());
    }

    // Called after a failed assertion or a SUCCEED() invocation.
    virtual void OnTestPartResult(const ::testing::TestPartResult &result) {
        // If the test part succeeded, we don't need to do anything.
        if (result.type() == ::testing::TestPartResult::kSuccess) return;

        __android_log_print(ANDROID_LOG_INFO, appTag, "%s in %s:%d %s", result.failed() ? "*** Failure" : "Success",
                            result.file_name(), result.line_number(), result.summary());
    }

    // Called after a test ends.
    virtual void OnTestEnd(const ::testing::TestInfo &info) {
        std::string result;
        if (info.result()->Passed()) {
            result.append("[       OK ]");
        } else if (info.result()->Skipped()) {
            result.append("[  SKIPPED ]");
        } else {
            result.append("[  FAILED  ]");
        }
        result.append(info.test_case_name()).append(".").append(info.name());
        if (info.result()->Failed()) addFullTestCommentIfPresent(info, result);

        if (::testing::GTEST_FLAG(print_time)) {
            std::ostringstream os;
            os << info.result()->elapsed_time();
            result.append(" (").append(os.str()).append(" ms)");
        }

        __android_log_print(ANDROID_LOG_INFO, appTag, "%s", result.c_str());
    };
};

static int32_t processInput(struct android_app *app, AInputEvent *event) { return 0; }

static void processCommand(struct android_app *app, int32_t cmd) {
    switch (cmd) {
        case APP_CMD_INIT_WINDOW: {
            if (app->window) {
                initialized = true;
            }
            break;
        }
        case APP_CMD_GAINED_FOCUS: {
            active = true;
            break;
        }
        case APP_CMD_LOST_FOCUS: {
            active = false;
            break;
        }
    }
}

static void destroyActivity(struct android_app *app) {
    ANativeActivity_finish(app->activity);

    // Wait for APP_CMD_DESTROY
    while (app->destroyRequested == 0) {
        struct android_poll_source *source = nullptr;
        int events = 0;
        int result = ALooper_pollAll(-1, nullptr, &events, reinterpret_cast<void **>(&source));

        if ((result >= 0) && (source)) {
            source->process(app, source);
        } else {
            break;
        }
    }
}

void android_main(struct android_app *app) {
    app->onAppCmd = processCommand;
    app->onInputEvent = processInput;

    while (1) {
        int events;
        struct android_poll_source *source;
        while (ALooper_pollAll(active ? 0 : -1, NULL, &events, (void **)&source) >= 0) {
            if (source) {
                source->process(app, source);
            }

            if (app->destroyRequested != 0) {
                return;
            }
        }

        if (initialized && active) {
            // Use the following key to send arguments to gtest, i.e.
            // --es args "--gtest_filter=-VkLayerTest.foo"
            const char key[] = "args";
            std::vector<std::string> args = get_args(*app, key);

            std::string filter = "";
            if (args.size() > 0) {
                __android_log_print(ANDROID_LOG_INFO, appTag, "Intent args = %s", args[0].c_str());
                filter += args[0];
            } else {
                __android_log_print(ANDROID_LOG_INFO, appTag, "No Intent args detected");
            }

            int argc = 2;
            char *argv[] = {(char *)"foo", (char *)filter.c_str()};
            __android_log_print(ANDROID_LOG_DEBUG, appTag, "filter = %s", argv[1]);

            // Route output to files until we can override the gtest output
            freopen("/sdcard/Android/data/com.example.CrashDiagnosticLayerTests/files/out.txt", "w", stdout);
            freopen("/sdcard/Android/data/com.example.CrashDiagnosticLayerTests/files/err.txt", "w", stderr);

            ::testing::InitGoogleTest(&argc, argv);
            CDLTestBase::InitArgs(argc, argv);

            ::testing::TestEventListeners &listeners = ::testing::UnitTest::GetInstance()->listeners();
            listeners.Append(new LogcatPrinter);

            ::testing::AddGlobalTestEnvironment(new TestEnvironment);

            int result = RUN_ALL_TESTS();

            if (result != 0) {
                __android_log_print(ANDROID_LOG_INFO, appTag, "==== Tests FAILED ====");
            } else {
                __android_log_print(ANDROID_LOG_INFO, appTag, "==== Tests PASSED ====");
            }

            fclose(stdout);
            fclose(stderr);

            destroyActivity(app);
            raise(SIGTERM);
            return;
        }
    }
}
#endif

#if defined(_WIN32) && !defined(NDEBUG)
#include <crtdbg.h>
#endif

// Makes any failed assertion throw, allowing for graceful cleanup of resources instead of hard aborts
class ThrowListener : public testing::EmptyTestEventListener {
    void OnTestPartResult(const testing::TestPartResult &result) override {
        if (result.type() == testing::TestPartResult::kFatalFailure) {
            // We need to make sure an exception wasn't already thrown so we dont throw another exception at the same
            // time
            std::exception_ptr ex = std::current_exception();
            if (ex) {
                return;
            }
            throw testing::AssertionException(result);
        }
    }
};

int main(int argc, char **argv) {
    int result;

#if defined(_WIN32)
    // --gtest_break_on_failure disables gtest suppression of debug message boxes.
    // If this flag is set, then limit the test framework in how it configures CRT
    // in order not to change expected gtest behavior (with regard to --gtest_break_on_failure).
    bool break_on_failure = false;
    for (int i = 1; i < argc; i++) {
        if (std::string_view(argv[i]) == "--gtest_break_on_failure") {
            break_on_failure = true;
            break;
        }
    }
    if (!break_on_failure) {
        // Disable message box for: "Errors, unrecoverable problems, and issues that require immediate attention."
        // This does not include asserts. GTest does similar configuration for asserts.
        _CrtSetReportMode(_CRT_ERROR, _CRTDBG_MODE_FILE);
        _CrtSetReportFile(_CRT_ERROR, _CRTDBG_FILE_STDERR);
    }
#endif

    ::testing::InitGoogleTest(&argc, argv);
    CDLTestBase::InitArgs(argc, argv);

    ::testing::AddGlobalTestEnvironment(new TestEnvironment);
    ::testing::UnitTest::GetInstance()->listeners().Append(new ThrowListener);

    result = RUN_ALL_TESTS();

    return result;
}
