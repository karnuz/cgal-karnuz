CC=g++
CFLAGS=-I.
SRC=$(wildcard src/*.cpp)
# SRC=$(addprefix src/,$(SRCF))
OBJF=$(patsubst %.cpp,%.o,$(SRC))
OBJ=$(patsubst src/%,bin/%,$(OBJF))
OBJDIR=bin

$(OBJDIR)/%.o: $(SRC)
	$(CC) -c -o $@ $< $(CFLAGS)

build: $(OBJ) 
	$(CC) -Wall -Isrc -shared -o $(OBJDIR)/libkarnuz.so $(OBJ)
