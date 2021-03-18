#include <iostream>
#include <future>

#include "simdjson.h"
#include "commands.hpp"
#include "longpoll.hpp"

void handle(LongPoll* lp) {
	simdjson::dom::parser parser;
	simdjson::dom::element json = parser.parse(lp->listen());

	if (json["updates"].get_array().size() == 0) return;
	if (std::string(json["updates"].at(0)["type"]) == "message_new") {
		std::async(std::launch::async, pososi, json);
		std::async(std::launch::async, ping, json);
	}
}

int main () {
	LongPoll lp;
	while (true) {
		std::async(std::launch::async, handle, &lp);
	//	handle(lp);
	}
	return 0;
}
