#include <stdio.h>
#include <string.h>
#include "core.h"
#include "systems.h"
#include "config.h"
#include "scene_loader.h"

int main(int argc, char *argv[]) {
    // Ensure we have at least one argument
    if (argc < 2) {
        fprintf(stderr, "Usage: %s [-cli | -gui]\n", argv[0]);
        return 1;
    }

    const char *mode = argv[1];

    if (strcmp(mode, "-gui") == 0) {
        printf("Loading scene in GUI mode...\n");
        load_scene("assets/scenes/default_scene.json");
        printf("Starting GUI render loop...\n");
        // Simulate rendering in GUI environment
        printf("Processing tasks...\n");
        printf("Sending data to server...\n");
        printf("Rendering VR menu...\n");
        printf("Initializing renderer...\n");
        printf("Rendering frame...\n");
        printf("Cleaning up tasks...\n");
        printf("Cleaning up renderer...\n");
    } else if (strcmp(mode, "-cli") == 0) {
        printf("Loading scene in CLI mode...\n");
        load_scene("assets/scenes/default_scene.json");
        printf("Starting text-based render loop...\n");
        // Simulate rendering in CLI environment
        printf("Processing tasks...\n");
        printf("Sending data to server...\n");
        printf("Rendering VR menu...\n");
        printf("Initializing renderer...\n");
        printf("Rendering frame...\n");
        printf("Cleaning up tasks...\n");
        printf("Cleaning up renderer...\n");
    } else {
        fprintf(stderr, "Invalid argument: %s. Usage: %s [-cli | -gui]\n", mode, argv[0]);
        return 1;
    }

    cleanup_tasks();
    return 0;
}
