#include <curl/curl.h>
#include <cstring>
#include <string>

std::string request(std::string url);
static size_t write(void *contents, size_t size, size_t nmemb, void *userp);
