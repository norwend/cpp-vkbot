all:
	sudo apt install libcurl-dev
	g++ ./src/*.cpp -I./include/ -L/usr/include -lcurl
	mv a.out bot
