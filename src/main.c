#include "core.h"
#include "systems.h"
#include "config.h"

int main() {
    initialize_systems();
    load_scene("assets/scenes/default_scene.json");
    start_render_loop();

    cleanup_systems();
    return 0;
}
