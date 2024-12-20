#!/bin/bash
gcc -o VRLearning src/main.c src/core/*.c src/systems/*.c src/ui/*.c -lGL -lGLEW -lglfw -lcurl -lm
