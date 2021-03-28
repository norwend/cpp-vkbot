all:
	sudo apt install libcurl4-openssl-dev
	g++ ./src/*.cpp -I./include/ -L/usr/include -lcurl
	mv a.out bot
