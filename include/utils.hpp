#ifndef UTILS
#define UTILS

// #include <algorithm>
#include <string>
#include <vector>
#include <locale>
#include <codecvt>
#include <string_view>
//#include <cctype>
#include <cstring>
#include <curl/curl.h>

struct string_conversion {
private:
	static std::wstring to_wstring_(const std::string& s) {
	   std::wstring_convert<std::codecvt_utf8<wchar_t>> conv;
	   return conv.from_bytes(s);
	}
	
	static std::string to_string_(const std::wstring& s) {
	   std::wstring_convert<std::codecvt_utf8<wchar_t>> conv;
	   return conv.to_bytes(s);
	}
	friend std::string to_lower(std::string_view data);
};

std::string params_append (const std::vector<std::pair<std::string, std::string>>& params);
std::string to_lower (std::string_view data);

std::string request(std::string url);
static size_t write(void *contents, size_t size, size_t nmemb, void *userp);

#endif
