EXEC_PATH = ../bin
OBJ_PATH = obj/Any
INCLUDE_PATH = include
LIB_PATH = ../lib/core
SRC_PATH = src
CC = gcc
OPTIONS = -Wall -fms-extensions


EXEC = $(EXEC_PATH)/
OBJS = $(OBJ_PATH)/any.o $(OBJ_PATH)/main.o


all: dir build

dir:
	mkdir -p $(OBJ_PATH)
	mkdir -p $(EXEC_PATH)

build: $(OBJS) $(EXEC)

$(EXEC): $(OBJS)
	$(CC) -g -o $@ $(OBJS)

$(OBJ_PATH)/any.o: $(SRC_PATH)/any.c
	$(CC) -g -c $< -I $(LIB_PATH) -I $(INCLUDE_PATH) -o $@ $(OPTIONS)

$(OBJ_PATH)/main.o: $(SRC_PATH)/main.c
	$(CC) -g -c $< -I $(LIB_PATH) -I $(INCLUDE_PATH) -o $@ $(OPTIONS)

clean:
	-rm -rf $(EXEC) $(OBJS)
