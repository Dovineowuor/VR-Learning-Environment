#include "ui.h"
#include <stdio.h>

// Placeholder for menu state
typedef struct {
    int selected_option;
    const char *options[3];
} VRMenu;

void render_vr_menu() {
    // Initialize the VR menu with options
    VRMenu menu = {
        .selected_option = 0,
        .options = {
            "Start Simulation",
            "Settings",
            "Exit"
        }
    };

    // Render VR menu options
    printf("==== VR MENU ====\n");
    for (int i = 0; i < 3; ++i) {
        if (i == menu.selected_option) {
            printf("-> %s\n", menu.options[i]); // Highlight selected option
        } else {
            printf("   %s\n", menu.options[i]);
        }
    }

    printf("=================\n");

    // Placeholder for handling user input
    // In a real implementation, this would interact with VR input devices
    printf("Press [Up/Down] to navigate, [Enter] to select.\n");
}
