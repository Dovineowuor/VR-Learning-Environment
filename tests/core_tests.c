#include "../src/core.h" // Update the path to the correct location of core.h
#include <assert.h>

void test_scene_loader() {
    load_scene("assets/scenes/test_scene.json");
    assert(1); // Replace with real assertions
}

int main() {
    test_scene_loader();
    return 0;
}
