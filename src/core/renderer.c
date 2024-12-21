#include <stdio.h>
#include <stdlib.h>
#include <math.h> // Include this header for sin and cos
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <GL/glut.h>
#include "renderer.h"
#include "window.h"

GLFWwindow *window;

void initialize_window() {
    if (!glfwInit()) {
        fprintf(stderr, "Failed to initialize GLFW\n");
        exit(EXIT_FAILURE);
    }

    window = glfwCreateWindow(800, 600, "VR Learning Environment", NULL, NULL);
    if (!window) {
        fprintf(stderr, "Failed to create GLFW window\n");
        glfwTerminate();
        exit(EXIT_FAILURE);
    }

    glfwMakeContextCurrent(window);
    if (glewInit() != GLEW_OK) {
        fprintf(stderr, "Failed to initialize GLEW\n");
        exit(EXIT_FAILURE);
    }
}

void cleanup_renderer() {
    glfwDestroyWindow(window);
    glfwTerminate();
}

void render_pendulum(float angle, float length) {
    float x = length * sin(angle); // Convert polar to Cartesian
    float y = -length * cos(angle);

    glBegin(GL_LINES);
    glVertex2f(0.0f, 0.0f); // Anchor point
    glVertex2f(x, y);       // Bob position
    glEnd();

    glPointSize(10.0f);
    glBegin(GL_POINTS);
    glVertex2f(x, y); // Bob
    glEnd();
}

void render_scene() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glLoadIdentity();
    glTranslatef(0.0, 0.0, -2.0);

    render_ball();
    render_pendulum(0.5f, 1.0f); // Example values for angle and length
    // Other rendering code
}

void render_ball() {
    // Implementation of render_ball
}

void start_render_loop() {
    while (!glfwWindowShouldClose(window)) {
        render_scene();
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
}
