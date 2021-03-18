#include "commands.hpp"
#include "simdjson.h"

void ping(const simdjson::dom::element& json) {
	for (const simdjson::dom::element& upd : json["updates"])
		if (std::string(upd["object"]["message"]["text"]) == "ping"
			|| std::string(upd["object"]["message"]["text"]) == "Ping") { 
			uint64_t peer_id = upd["object"]["message"]["peer_id"];
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
	for (const simdjson::dom::element& upd : json["updates"])
		if (std::string(upd["object"]["message"]["text"]) == "Пососи"
			|| std::string(upd["object"]["message"]["text"]) == "пососи" 
			|| std::string(upd["object"]["message"]["text"]) == "ПОСОСИ") { 
			uint64_t peer_id = upd["object"]["message"]["peer_id"];
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
