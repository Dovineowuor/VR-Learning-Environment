#!/bin/bash
gcc -o tests/tests tests/core_tests.c src/core/*.c -lGL -lGLEW -lglfw -lcurl -lm && ./tests/tests
