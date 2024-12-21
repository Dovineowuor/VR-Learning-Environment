#ifndef SCENE_LOADER_H
#define SCENE_LOADER_H

#include <stdio.h>
#include <string.h>
#include <json-c/json.h>
#include <GL/glew.h>     // GLEW for handling OpenGL extensions
#include <GLFW/glfw3.h>  // GLFW for creating and managing OpenGL windows
#include <GL/glut.h>     // GLUT for OpenGL utility toolkit functions
#include <math.h>        // Math library for geometric calculations

extern GLFWwindow *window;

// Function declarations
void initialize_window();
void setup_shaders();
void setup_vertex_data();
void render_ball();
void render_pendulum(float angle, float length);
void render_scene();
void start_render_loop();
void initialize_objects();
void initialize_tasks();
void process_tasks();
void cleanup_tasks();
void cleanup_renderer(); // Declaration for cleanup_renderer function
void load_scene(const char *scene_path);

#endif // SCENE_LOADER_H