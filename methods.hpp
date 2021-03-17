#include <map>
#include <string>

#include "net.hpp"
#include "api.hpp"

class Method {
public:
	std::map<std::string, std::string> params;
	void method_link_init() {
		method_link_ = api::vkurl + api::param_append + method_name_;
		for (const auto& [key, value] : params) {
			method_link_ += key + '=' + value + '&';
		}
	}
	Method (std::map<std::string, std::string> p) : params(p) {
		method_link_init();
		request(method_link_);
	}
protected:
	const std::string method_name_; 
	std::string method_link_;
};


