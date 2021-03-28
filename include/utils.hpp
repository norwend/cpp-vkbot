#ifndef UTILS
#define UTILS

#include <string>
#include <vector>
#include <curl/curl.h>
#include <cstring>

std::string params_append (const std::vector<std::pair<std::string, std::string>>& params);
std::string to_lower (std::string& data);

std::string request(std::string url);
static size_t write(void *contents, size_t size, size_t nmemb, void *userp);

#endif
