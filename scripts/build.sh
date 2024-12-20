#!/bin/bash
gcc -I src/core -I src/systems -I src/ui -o VRLearning src/main.c src/core/*.c src/systems/*.c src/ui/*.c -lGL -lGLEW -lglfw -lcurl -lm -ljson-c