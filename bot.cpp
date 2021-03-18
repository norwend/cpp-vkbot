#include <iostream>
#include <string>
#include "simdjson.h"
#include "longpoll.hpp"

void ping(const simdjson::dom::element& json) {
		if (std::string(json["updates"].at(0)["object"]["message"]["text"]) == "ping"
			|| std::string(json["updates"].at(0)["object"]["message"]["text"]) == "Ping") { 
		uint64_t peer_id = json["updates"].at(0)["object"]["message"]["peer_id"];
		messages::send.execute({
			{ "peer_id",		std::to_string(peer_id) }, 
			{ "message",		"pong" },
			{ "random_id",		"0" },
			{ "group_id", 		std::to_string(api::id) },
			{ "access_token",	std::string(api::token) },
			{ "v",				"5.130" }
		});	
	}
}

void pososi (const simdjson::dom::element& json) {
			if (std::string(json["updates"].at(0)["object"]["message"]["text"]) == "Пососи"
			|| std::string(json["updates"].at(0)["object"]["message"]["text"]) == "пососи" 
			|| std::string(json["updates"].at(0)["object"]["message"]["text"]) == "ПОСОСИ") { 
		uint64_t peer_id = json["updates"].at(0)["object"]["message"]["peer_id"];
		messages::send.execute({
			{ "peer_id",		std::to_string(peer_id) }, 
			{ "attachment",		"audio-2001823365_67823365" },
			{ "message",		"" },
			{ "random_id",		"0" },
			{ "group_id", 		std::to_string(api::id) },
			{ "access_token",	std::string(api::token) },
			{ "v",				"5.130" }
		});	
	}
}

void handle(LongPoll& lp) {
	simdjson::dom::parser parser;
	simdjson::dom::element json = parser.parse(lp.listen());
	
	if (json["updates"].get_array().size() == 0) return;
	if (std::string(json["updates"].at(0)["type"]) == "message_new") { 
		pososi(json);
		ping(json);
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
