#!/bin/bash

# Base directory
BASE_DIR="VR-Learning-Environment"

# Directory structure
declare -A DIRS=(
    ["$BASE_DIR/src/core"]="renderer.c input.c physics.c scene_loader.c utilities.c core.h"
    ["$BASE_DIR/src/systems"]="api.c task_manager.c event_handler.c plugin_loader.c systems.h"
    ["$BASE_DIR/src/assets/textures"]=""
    ["$BASE_DIR/src/assets/models"]=""
    ["$BASE_DIR/src/assets/scenes"]=""
    ["$BASE_DIR/src/assets/shaders"]=""
    ["$BASE_DIR/src/ui"]="vr_menu.c hud.c settings_menu.c ui.h"
    ["$BASE_DIR/include"]="renderer.h input.h physics.h scene_loader.h utilities.h"
    ["$BASE_DIR/tests"]="core_tests.c scene_loader_tests.c api_tests.c task_manager_tests.c"
    ["$BASE_DIR/docs"]="README.md API.md CONTRIBUTING.md"
    ["$BASE_DIR/scripts"]="build.sh test.sh format_code.sh deploy.sh"
    ["$BASE_DIR/third_party/cglm"]=""
    ["$BASE_DIR/third_party/glfw"]=""
    ["$BASE_DIR/third_party/libcurl"]=""
    ["$BASE_DIR/third_party/assimp"]=""
    ["$BASE_DIR/third_party/bullet"]=""
    ["$BASE_DIR/build/wasm"]=""
    ["$BASE_DIR/build/native"]=""
)

# Files in the base directory
BASE_FILES=("Makefile" "LICENSE" ".gitignore" "$BASE_DIR/src/main.c" "$BASE_DIR/src/config.h")

# Create directories and files
echo "Setting up project structure..."
for dir in "${!DIRS[@]}"; do
    mkdir -p "$dir"
    for file in ${DIRS[$dir]}; do
        touch "$dir/$file"
    done
done

for file in "${BASE_FILES[@]}"; do
    touch "$file"
done

echo "Project structure created successfully in $BASE_DIR."
