#include "utils.hpp"

std::string params_append (std::vector<std::pair<std::string, std::string>> params) {
	std::string appended = "";
	for (const auto& [key, value] : params)
		appended += key + '=' + value + '&';
	return appended;
}
