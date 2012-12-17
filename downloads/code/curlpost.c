#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <curl/curl.h>

int main(int argc, char ** argv) {
    CURLcode res;
    CURL * curl_handle;
    char oauth_header_string[BUFSIZ];
    struct curl_slist * headers = NULL;

    // handle initialize, error handling is missing for example.
    res = curl_global_init(CURL_GLOBAL_DEFAULT);
    curl_handle = curl_easy_init();

    curl_easy_setopt(curl_handle, CURLOPT_URL, "https://example.com/post");
    curl_easy_setopt(curl_handle, CURLOPT_POST, 1);

    oauth_header_string[0] = '\0';
    strcat(oauth_header_string, "Authorization: OAuth ");
    strcat(oauth_header_string, "oauth_version=\"1.0\", ");
    // ... oauth header code ...

    headers = curl_slist_append(headers, oauth_header_string);
    curl_easy_setopt(curl_handle, CURLOPT_HTTPHEADER, headers);

    res = curl_easy_perform(curl_handle);

    curl_easy_cleanup(curl_handle);
    curl_global_cleanup();

    return 0;
}

