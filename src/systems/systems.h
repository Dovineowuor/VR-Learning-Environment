#ifndef SYSTEMS_H
#define SYSTEMS_H

void send_data_to_server(const char *url, const char *data);
void initialize_tasks();
void process_tasks();
void cleanup_tasks();

#endif
