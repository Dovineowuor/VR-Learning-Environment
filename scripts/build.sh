#!/bin/bash

# AUTHOR: [Dovine K.]
# CONTACT: [owuordove@gmail.com]
# DESCRIPTION: This script builds the project, checks if the build was successful, sets up a virtual environment, installs dependencies,
# and creates necessary AI-related scripts. It also provides instructions on how to run the program.
# USAGE: Run this script to build the project and verify the build status.
# EXAMPLE: ./build.sh
# NOTES: Replace {option either -cli or -gui} with the appropriate argument to run the program with GUI or CLI.

# Enable strict mode
set -euo pipefail

# Define the output binary name
OUTPUT="VRLearning"
VENV_DIR="pendulum_venv"
AI_SCRIPT="scripts/ai.sh"
LLM_SCRIPT="scripts/pendulum_simulation.py"

# Compilation command
build_project() {
    echo "Building the project..."
    gcc -I src/core -I src/systems -I src/ui \
        -o "$OUTPUT" \
        src/main.c src/core/*.c src/systems/*.c src/ui/*.c \
        -lGL -lGLEW -lglfw -lm -ljson-c -lglut -lcurl
}

# Check if the build was successful
check_build_status() {
    if [[ $? -eq 0 ]]; then
        echo -e "\e[1;32mBuild successful!\e[0m Binary: $OUTPUT"
        setup_virtualenv_and_ai_script
        print_script_info
    else
        echo -e "\e[1;31mBuild failed!\e[0m" >&2
        exit 1
    fi
}

# Set up virtual environment and install dependencies
setup_virtualenv_and_ai_script() {
    # Check if virtual environment exists, if not, create it
    if [ ! -d "$VENV_DIR" ]; then
        echo "Creating a new virtual environment..."
        python3 -m venv "$VENV_DIR"
    else
        echo "Virtual environment already exists."
    fi

    # Activate the virtual environment
    source "$VENV_DIR/bin/activate"

    # Install required dependencies
    echo "Installing required Python dependencies..."
    pip install --upgrade pip
    pip install transformers huggingface_hub  numpyrequests python-dotenv torch  

    # Verify the installation
    python3 -c "import transformers; import torch; import numpy; print('Dependencies installed successfully!')"

    # Create the AI script dynamically
    echo "Creating AI-related scripts..."

    ./scripts/ai.sh > "$AI_SCRIPT"
    chmod +x "$AI_SCRIPT"
}

# Echo script information
print_script_info() {
    echo -e "\e[1;33mScript Information:\e[0m"
    echo -e "\e[1;33mAUTHOR: [Dovine K.]\e[0m"
    echo -e "\e[1;33mCONTACT: [owuordove@gmail.com]\e[0m"
    echo -e "\e[1;33mDESCRIPTION: This script builds the project, checks if the build was successful, and provides instructions on how to run the program.\e[0m"
    echo -e "\e[1;33mUSAGE: Run this script to build the project and verify the build status.\e[0m"
    echo -e "\e[1;33mEXAMPLE: ./scripts/build.sh\e[0m"
    echo -e "\e[1;33mNOTES: Replace {option either -cli or -gui} with the appropriate argument to run the program with GUI or CLI.\e[0m"
    echo -e "\e[1;34mTo run and test the program, use the following command:\e[0m"
    echo -e "\e[1;34m./$OUTPUT -gui\e[0m - to run the program with the GUI/Window"
    echo -e "\e[1;34m./$OUTPUT -cli\e[0m - to run the program in the terminal command line."
    echo -e "\e[1;34mTo run the program from anywhere, simply type: ./$OUTPUT {option} and press Enter in your terminal.\e[0m"
    echo -e "\e[1;33mEND OF SCRIPT\e[0m"
}

# Main script execution
build_project
check_build_status
