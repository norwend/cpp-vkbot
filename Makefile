all:
	curl-config --cflags
	g++ ./src/*.cpp -I./include/ -L/usr/include -lcurl
	mv a.out bot
