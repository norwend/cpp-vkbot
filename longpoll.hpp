#include <iostream>
#include "simdjson.h"

#include "methods.hpp"

class LongPoll {
public:
	LongPoll();   
private:
	void get_server();
	simdjson::dom::parser parser_;
	std::string key_, server_, ts_;
};
