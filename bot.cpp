#include <iostream>
#include <string>
#include "simdjson.h"
#include "longpoll.hpp"


void handle (LongPoll& lp) {
	simdjson::dom::parser parser;
	// std::string response = lp.listen();
	simdjson::dom::element json = parser.parse(lp.listen());
	
	if (json["updates"].get_array().size() == 0) return;

	if (std::string(json["updates"].at(0)["type"]) == "message_new") { //&& uint64_t(json["updates"].at(0)["object"]["message"]["from_id"]) == 267398968) { 
		uint64_t peer_id = json["updates"].at(0)["object"]["message"]["peer_id"];
		std::cout << peer_id << std::endl;
		messages::send.execute({
			{ "peer_id",		std::to_string(peer_id) }, 
			{ "message",		"Пососи" },
			{ "random_id",		"0" },
			{ "group_id", 		std::to_string(api::id) },
			{ "access_token",	std::string(api::token) },
			{ "v",				"5.130" }
		});	
	}
}

int main () {
	LongPoll lp;
	while (true)
	{
		handle(lp);
	}
	return 0;
}
