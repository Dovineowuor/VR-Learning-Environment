#include <stdio.h>
#include <string.h>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <math.h>
#include "renderer.h"


#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

// Pendulum properties
float angle = M_PI / 4; // Initial angle in radians
float angular_velocity = 0.0f;
float angular_acceleration = 0.0f;
float length = 2.0f; // Length of the pendulum (meters)
float gravity = 9.8f; // Gravitational constant

// Timing
float deltaTime = 0.016f; // Approx. 60 FPS

// Window dimensions
const int WIDTH = 800;
const int HEIGHT = 600;

// Forward declarations
void render_pendulum(float angle, float length);
void update_pendulum();
void key_callback(GLFWwindow *window, int key, int scancode, int action, int mods);

// Function to run the GUI mode
void run_gui_mode() {
    if (!glfwInit()) {
        fprintf(stderr, "Failed to initialize GLFW\n");
        return;
    }

    GLFWwindow *window = glfwCreateWindow(WIDTH, HEIGHT, "2D Pendulum Simulation", NULL, NULL);
    if (!window) {
        fprintf(stderr, "Failed to create GLFW window\n");
        glfwTerminate();
        return;
    }

    glfwMakeContextCurrent(window);
    if (glewInit() != GLEW_OK) {
        fprintf(stderr, "Failed to initialize GLEW\n");
        return;
    }

    // Setup OpenGL viewport
    glViewport(0, 0, WIDTH, HEIGHT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-3.0f, 3.0f, -3.0f, 3.0f, -1.0f, 1.0f);

    // Set key callback
    glfwSetKeyCallback(window, key_callback);

    // Main loop
    while (!glfwWindowShouldClose(window)) {
        // Clear screen
        glClear(GL_COLOR_BUFFER_BIT);

        // Update and render pendulum
        update_pendulum();
        render_pendulum(angle, length);

        // Swap buffers and poll events
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwDestroyWindow(window);
    glfwTerminate();
}


// Update the pendulum's state
void update_pendulum() {
    angular_acceleration = -(gravity / length) * sin(angle);
    angular_velocity += angular_acceleration * deltaTime;
    angle += angular_velocity * deltaTime;

    // Apply damping
    angular_velocity *= 0.99f;
}

// Handle keyboard input
void key_callback(GLFWwindow *window, int key, int scancode, int action, int mods) {
    if (action == GLFW_PRESS) {
        if (key == GLFW_KEY_UP) length += 0.1f;        // Increase length
        if (key == GLFW_KEY_DOWN) length -= 0.1f;      // Decrease length
        if (key == GLFW_KEY_LEFT) gravity -= 0.1f;     // Decrease gravity
        if (key == GLFW_KEY_RIGHT) gravity += 0.1f;    // Increase gravity
    }
}

// Function to run the CLI mode
void run_cli_mode() {
    printf("Loading scene in CLI mode...\n");
    printf("Simulating pendulum motion in CLI mode...\n");

    for (int i = 0; i < 10; i++) {
        update_pendulum();
        printf("Time step %d: Angle = %.2f radians\n", i, angle);
    }
}

int main(int argc, char *argv[]) {
    // Ensure we have at least one argument
    if (argc < 2) {
        fprintf(stderr, "Usage: %s [-cli | -gui]\n", argv[0]);
        return 1;
    }

    const char *mode = argv[1];

    if (strcmp(mode, "-gui") == 0) {
        printf("Loading scene in GUI mode...\n");
        run_gui_mode();
    } else if (strcmp(mode, "-cli") == 0) {
        printf("Loading scene in CLI mode...\n");
        run_cli_mode();
    } else {
        fprintf(stderr, "Invalid argument: %s. Usage: %s [-cli | -gui]\n", mode, argv[0]);
        return 1;
    }

    return 0;
}
