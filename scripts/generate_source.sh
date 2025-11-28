./update_deps.py --dir ../build/ext --no-build
./generate_source.py ../build/ext/Vulkan-Headers/registry/ ../build/ext/SPIRV-Headers/include/spirv/unified1/
cd ../src/generated
clang-format-18 -i -- **.cpp **.inc


