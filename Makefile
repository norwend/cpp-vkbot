all:
	sudo apt install libcurl4-openssl-dev
	g++ ./src/*.cpp -I./include/ -lcurl -std=c++17
	mv a.out bot
