#include "utils.hpp"

std::string params_append (const std::vector<std::pair<std::string, std::string>>& params) {
	std::string appended = "";
	for (const auto& [key, value] : params)
		appended += key + '=' + value + '&';
	return appended;
}

std::string to_lower (std::string&& data) {
	std::transform(data.begin(), data.end(), data.begin(), 
	  [](unsigned char c){ return std::tolower(c); });
	return data;
}

static size_t write(void *contents, size_t size, size_t nmemb, void *userp)
{
    ((std::string*)userp)->append((char*)contents, size * nmemb);
    return size * nmemb;
}

std::string request(std::string url) {
	CURL* curl;
	std::string answer;
	curl = curl_easy_init();
	if (curl) {
		curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
		curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write);
		curl_easy_setopt(curl, CURLOPT_WRITEDATA, &answer);
		curl_easy_perform(curl);
		curl_easy_cleanup(curl); 
	}
	return answer;
}
