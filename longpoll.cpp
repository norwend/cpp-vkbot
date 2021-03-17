#include "longpoll.hpp"

LongPoll::LongPoll () { get_server(); }

void LongPoll::get_server() {
	std::string lp_data = groups::get_longpoll_server.execute ({
			{"group_id", 		std::to_string(api::id)},
			{"access_token",	std::string(api::token)},
			{"v",				"5.130"}
		});
	key_= parser_.parse(lp_data)["response"]["key"];
	server_ = parser_.parse(lp_data)["response"]["server"];
	ts_ = parser_.parse(lp_data)["response"]["ts"];
//	std::cout << "key: " << key_ << '\n' << "server: " << server_ << '\n'<< "ts: " << ts_ << '\n'; 
}
