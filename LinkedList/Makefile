# read again

EXEC_PATH = ../bin
OBJ_PATH = obj/LinkedList
INCLUDE_PATH = include
LIB_PATH = ../lib/core
SRC_PATH = src
CC = gcc
OPTIONS = -Wall -fms-extensions


EXEC = $(EXEC_PATH)/LinkedList
OBJS = $(OBJ_PATH)/linkedlist.o $(OBJ_PATH)/linkedlist_iterator.o $(OBJ_PATH)/main.o


all: dir build

dir:
	mkdir -p $(OBJ_PATH)
	mkdir -p $(EXEC_PATH)

build: $(OBJS) $(EXEC)

$(EXEC): $(OBJS)
	$(CC) -g -o $@ $(OBJS)

$(OBJ_PATH)/linkedlist.o: $(SRC_PATH)/linkedlist.c
	$(CC) -g -c $< -I $(LIB_PATH) -I $(INCLUDE_PATH) -o $@ $(OPTIONS)

$(OBJ_PATH)/linkedlist_iterator.o: $(SRC_PATH)/linkedlist_iterator.c
	$(CC) -g -c $< -I $(LIB_PATH) -I $(INCLUDE_PATH) -o $@ $(OPTIONS)

$(OBJ_PATH)/main.o: $(SRC_PATH)/main.c
	$(CC) -g -c $< -I $(LIB_PATH) -I $(INCLUDE_PATH) -o $@ $(OPTIONS)

clean:
	-rm -rf $(EXEC) $(OBJS)
