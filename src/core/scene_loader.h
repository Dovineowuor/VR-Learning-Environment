#ifndef SCENE_LOADER_H
#define SCENE_LOADER_H

void load_scene(const char *scene_path);
void send_data_to_server(const char *url, const char *data);
void render_vr_menu();

#endif // SCENE_LOADER_H