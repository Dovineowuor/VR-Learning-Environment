#include <stdio.h>
#include <stdlib.h>
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

void render_pendulum() {
    printf("Rendering pendulum...\n");
    glPushMatrix();
    glTranslatef(0.5, 0.5, 0.0);
    glBegin(GL_LINES);
    glVertex2f(0.0, 0.0);
    glVertex2f(0.0, -0.3);
    glEnd();
    glTranslatef(0.0, -0.3, 0.0);
    glColor3f(1.0, 0.0, 0.0); // Red ball at the end of the pendulum
    glutWireSphere(0.05, 20, 20); // Use glutWireSphere instead of glutSolidSphere
    glPopMatrix();
}

void render_scene() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glLoadIdentity();
    glTranslatef(0.0, 0.0, -2.0);

    render_ball();
    render_pendulum();
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
