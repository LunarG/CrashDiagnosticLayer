#!/bin/bash
set -e

# Verify execution platform is Linux
if [ "$(uname -s)" != "Linux" ]; then
  echo "Error: This script is only supported on Linux."
  exit 1
fi

# Verify execution directory
if [ "$(basename "$PWD")" != "scripts" ]; then
  echo "Error: This script must be run from inside the 'scripts/' directory."
  exit 1
fi

# Create a temporary directory to alias clang-format-18 as clang-format for Python
TMP_BIN_DIR=$(mktemp -d)
trap 'rm -rf "$TMP_BIN_DIR"' EXIT

if command -v clang-format-18 &>/dev/null; then
  ln -s "$(command -v clang-format-18)" "$TMP_BIN_DIR/clang-format"
  export PATH="$TMP_BIN_DIR:$PATH"
elif ! command -v clang-format &>/dev/null; then
  echo "Error: Neither clang-format-18 nor clang-format was found in PATH."
  exit 1
fi

# Ensure required Python packages are available
if ! python3 -c "import jsonschema, pyparsing" &>/dev/null; then
  echo "Missing required Python packages (jsonschema, pyparsing). Attempting install..."
  if python3 -m pip --version &>/dev/null; then
    python3 -m pip install --user --quiet jsonschema pyparsing 2>/dev/null || \
    python3 -m pip install --user --quiet --break-system-packages jsonschema pyparsing
  else
    echo "Error: 'pip' is not installed."
    echo "Please run: sudo dnf install python3-pip python3-jsonschema python3-pyparsing"
    exit 1
  fi
fi

# Fetch external dependencies into build/ext
python3 ./update_deps.py --dir ../build/ext --no-build

# Run generator (generate_source.py will now detect clang-format-18 and apply formatting)
python3 ./generate_source.py ../build/ext/Vulkan-Headers/registry/ ../build/ext/SPIRV-Headers/include/spirv/unified1/

# Clean up temporary external directory
rm -rf ../build/ext
