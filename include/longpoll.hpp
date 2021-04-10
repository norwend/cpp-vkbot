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
	std::string* lp_data_ = new std::string("");
	simdjson::dom::parser parser_;
	std::string key_, server_, ts_;
	const int timeout_ = 25;
	void get_server();
};

#endif
