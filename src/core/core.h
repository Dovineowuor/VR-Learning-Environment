#ifndef CORE_H
#define CORE_H

void initialize_renderer();
void render_frame();
void cleanup_renderer();
void load_scene(const char *scene_path);
void log_message(const char *message);

#endif
