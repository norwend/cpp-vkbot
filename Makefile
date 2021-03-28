all:
	curl --version
	g++ ./src/*.cpp -I./include/ -L/usr/include -lcurl
	mv a.out bot
