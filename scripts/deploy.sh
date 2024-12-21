#!/bin/bash

# Enable strict mode
set -euo pipefail

# Define the output binary name and target directory
BINARY="VRLearning"
DEPLOY_DIR="/usr/local/bin"

# Ensure the binary exists
if [[ ! -f "$BINARY" ]]; then
    echo "Error: Binary '$BINARY' not found. Did you run build.sh?" >&2
    exit 1
fi

# Deploy the binary
echo "Deploying $BINARY to $DEPLOY_DIR..."
sudo mv "$BINARY" "$DEPLOY_DIR/"

if [[ $? -eq 0 ]]; then
    echo "Deployment successful! You can now run the program using: $BINARY -gui or $BINARY -cli : for running on GUI or terminal respectively."
else
    echo "Deployment failed!" >&2
    exit 1
fi
