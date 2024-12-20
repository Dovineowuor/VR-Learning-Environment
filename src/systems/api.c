#include <curl/curl.h>
#include "systems.h"
#include "api.h"

void send_data_to_server(const char *url, const char *data) {
    CURL *curl = curl_easy_init();
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, data);
        curl_easy_perform(curl);
        curl_easy_cleanup(curl);
    }
}
