all: compile
	mv a.out bot

libinstall:
	sudo apt install libcurl4-openssl-dev

compile:
	g++ ./src/*.cpp -I./include/ -lcurl -lpthread -std=c++17 -Wunused-result

github: libinstall compile
