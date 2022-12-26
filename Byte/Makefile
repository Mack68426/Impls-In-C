EXEC_PATH = bin
OBJ_PATH = obj/Byte
INCLUDE_PATH = include
LIB_PATH = ../lib/core
SRC_PATH = src
CC = gcc
OPTIONS = -Wall -fms-extensions


EXEC = $(EXEC_PATH)/Byte
OBJS = $(OBJ_PATH)/byte.o $(OBJ_PATH)/main.o


all: dir build

dir:
	mkdir -p $(OBJ_PATH)
	mkdir -p $(EXEC_PATH)

build: $(OBJS) $(EXEC)

$(EXEC): $(OBJS)
	$(CC) -g -o $@ $(OBJS)

$(OBJ_PATH)/byte.o: $(SRC_PATH)/byte.c
	$(CC) -g -c $< -I $(LIB_PATH) -I $(INCLUDE_PATH) -o $@ $(OPTIONS)

$(OBJ_PATH)/main.o: $(SRC_PATH)/main.c
	$(CC) -g -c $< -I $(LIB_PATH) -I $(INCLUDE_PATH) -o $@ $(OPTIONS)

clean:
	-rm -rf $(EXEC) $(OBJS)
