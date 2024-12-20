#include "core.h"
#include <stdio.h>
#include <json-c/json.h>
#include "utilities.h"
#include "task_manager.h"
#include "systems.h"
#include "scene_loader.h"
#include "api.h"
#include <GLFW/glfw3.h>

GLFWwindow *window;

void initialize_window() {
    if (!glfwInit()) {
        fprintf(stderr, "Failed to initialize GLFW\n");
        return;
    }

    window = glfwCreateWindow(800, 600, "VR Environment", NULL, NULL);
    if (!window) {
        fprintf(stderr, "Failed to create GLFW window\n");
        glfwTerminate();
        return;
    }

    glfwMakeContextCurrent(window);
}

void load_scene(const char *scene_path) {
    // Function implementation to load the scene from the provided path
    printf("Loading scene from: %s\n", scene_path);

    // Attempt to parse the scene file as JSON
    struct json_object *parsed_json = json_object_from_file(scene_path);
    if (parsed_json) {
        printf("Scene loaded successfully.\n");

        // Process the scene data (custom logic depends on scene structure)
        // Example: Extract data, objects, and configurations from the JSON
        struct json_object *scene_data;
        if (json_object_object_get_ex(parsed_json, "data", &scene_data)) {
            // Use scene_data to initialize objects and settings
            printf("Scene data processed.\n");
        } else {
            printf("Error: No 'data' field found in the scene.\n");
        }

        // Conditional rendering based on the environment
        #ifdef _WIN32 // Windows
        // GUI environment rendering
        initialize_window();
        render_gui_menu();
        initialize_renderer();
        while (!glfwWindowShouldClose(window)) {
            render_frame();
            glfwSwapBuffers(window);
            glfwPollEvents();
        }
        cleanup_renderer();
        glfwDestroyWindow(window);
        glfwTerminate();
        #else // CLI or other environments (Linux, macOS, etc.)
        // Text-based environment rendering
        printf("Processing tasks...\n");
        printf("Sending data to server: http://example.com/api\n");
        printf("Rendering VR menu...\n");
        printf("Initializing renderer...\n");
        printf("Rendering frame...\n");
        printf("Cleaning up tasks...\n");
        printf("Cleaning up renderer...\n");
        #endif

    } else {
        printf("Failed to load scene.\n");
    }
}

void start_render_loop() {
    // Main rendering loop
    while (!glfwWindowShouldClose(window)) {
        render_frame();
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
}

void initialize_tasks() {
    // Task initialization logic

    // Register tasks with the task manager

}

void process_tasks() {
    // Task processing logic

}

void cleanup_tasks() {
    // Cleanup tasks
    cleanup_renderer();
}
