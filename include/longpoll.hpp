#ifndef LONGPOLL
#define LONGPOLL

#include <iostream>
#include "simdjson.h"
#include "methods.hpp"

class LongPoll {
public:
	LongPoll(); 
	std::string listen();
private:
	void get_server();
	simdjson::dom::parser parser_;
	std::string key_, server_, ts_;
	const int timeout_ = 25;
};

#endif
