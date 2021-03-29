#include "utils.hpp"

static const std::locale utf8 ("ru_RU.UTF-8");

std::string to_lower(std::string_view data) {
	auto ss = string_conversion::to_wstring_(data.data());
	for (auto& c : ss) {
		c = std::tolower(c, utf8);
	}
	return string_conversion::to_string_(ss);
}

std::string params_append (const std::vector<std::pair<std::string, std::string>>& params) {
	std::string appended = "";
	for (const auto& [key, value] : params)
		appended += key + '=' + value + '&';
	return appended;
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
