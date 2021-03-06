#include "commands.hpp"
#include "simdjson.h"

void ping(const simdjson::dom::element& json) {
	for (const simdjson::dom::element& upd : json["updates"])
		if (to_lower(std::string(upd["object"]["message"]["text"])) == "ping") { 
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
		if (to_lower(std::string(upd["object"]["message"]["text"])) == "пососи") { 
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


void avtomat (const simdjson::dom::element& json) {
	for (const simdjson::dom::element& upd : json["updates"])
		if (to_lower(std::string(upd["object"]["message"]["text"])) == "да сука") { 
			uint64_t peer_id = upd["object"]["message"]["peer_id"];
			messages::send.execute({
				{ "peer_id",		std::to_string(peer_id) }, 
				{ "attachment",		"audio-203327583_456239017" },
				{ "message",		"НОВЫЙ%20АВТОМАТ!" },
				{ "random_id",		"0" },
				{ "group_id", 		std::to_string(api::id) },
				{ "access_token",	std::string(api::token) },
				{ "v",				"5.130" }
			});	
		}
}

void fotka (const simdjson::dom::element& json) {
	for (const simdjson::dom::element& upd : json["updates"])
		if (to_lower(std::string(upd["object"]["message"]["text"])) == "морген скинь фотку") { 
			uint64_t peer_id = upd["object"]["message"]["peer_id"];
			messages::send.execute({
				{ "peer_id",		std::to_string(peer_id) }, 
				{ "attachment",		"photo-203327583_457239021" },
				{ "message",		"МОЛОДОЙ%20ХЕФНЕР!" },
				{ "random_id",		"0" },
				{ "group_id", 		std::to_string(api::id) },
				{ "access_token",	std::string(api::token) },
				{ "v",				"5.130" }
			});	
		}
}
