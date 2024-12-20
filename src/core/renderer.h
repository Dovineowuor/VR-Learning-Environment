#ifndef RENDERER_H
#define RENDERER_H

#include <GL/glew.h>
#include <GLFW/glfw3.h>

void initialize_window();
void setup_shaders();
void setup_vertex_data();
void render_ball();
void render_pendulum();
void render_scene();
void cleanup_renderer();

extern GLFWwindow *window;

#endif // RENDERER_H