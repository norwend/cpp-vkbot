#include <iostream>

#include "simdjson.h"

#include "net.hpp"
#include "api.hpp"

class LongPoll {
public:
	LongPoll(int id) { // todo: заменить api::token на std::string token 
		std::string lp_contents = request(std::string(api::vkurl) 
				+ "groups.getLongPollServer?group_id=" 
				+ std::to_string(id) + '&' + "access_token=" + std::string(api::token) + '&' + "v=5.130");
		key = parser.parse(lp_contents)["response"]["key"];
		server = parser.parse(lp_contents)["response"]["server"];
		ts = parser.parse(lp_contents)["response"]["ts"];
		std::cout << "key: " << key << '\n' << "server: " << server << '\n'<< "ts: " << ts << '\n'; 
	}
private:
	simdjson::dom::parser parser;
	std::string key, server, ts;
};
