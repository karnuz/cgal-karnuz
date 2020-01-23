CC=g++
CFLAGS=-I.
SRC=$(wildcard src/*.cpp)
# SRC=$(addprefix src/,$(SRCF))
OBJF=$(patsubst %.cpp,%.o,$(SRC))
OBJ=$(patsubst src/%,bin/%,$(OBJF))
OBJDIR=bin

$(OBJ): bin/%.o : src/%.cpp
	$(CC) -c $^ $(CFLAGS) -o $@

build: $(OBJ) 
	$(CC) -Wall -Isrc -shared -o $(OBJDIR)/libkarnuz.so $(OBJ)
