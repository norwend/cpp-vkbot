all:
  g++ ./src/*.cpp -I./include/ -lcurl
  mv a.out bot
