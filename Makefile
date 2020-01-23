CC=g++
CFLAGS=-I.
SRC=$(wildcard *.cpp)
OBJ=$(patsubst %.cpp,%.o,$(SRC))

%.o: $(SRC)
	$(CC) -c $^ $(CFLAGS)

build: $(OBJ) 
	$(CC) -shared -o libkarnuz.so $(OBJ) 
