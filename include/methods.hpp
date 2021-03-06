#ifndef METHODS
#define METHODS

#include <cstring>
#include <vector>

#include "api.hpp"
#include "utils.hpp"

class Method {
public:
	Method (std::string mn) : method_name_(mn) {
		method_link_ = api::vkurl + method_name_+ '?'; // question mark for method parameters
	}
	std::string execute(std::vector<std::pair<std::string, std::string>> params) {
		return request(method_link_ + params_append(params));
	}
private:
	std::string method_name_; 
	std::string method_link_;
};



namespace groups {
	inline Method get_longpoll_server ("groups.getLongPollServer");
}
namespace messages {
	inline Method send ("messages.send");
}
namespace photos {
	inline Method search ("photos.search");
}

#endif
