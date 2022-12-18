# read again

EXEC_PATH = ../bin
OBJ_PATH = obj/Node
INCLUDE_PATH = include
# LIB_PATH = ../lib/include
SRC_PATH = src
CC = gcc
OPTIONS = -Wall -fms-extensions


EXE = $(EXEC_PATH)/node
OBJS = $(OBJ_PATH)/node.o $(OBJ_PATH)/main.o


all: dir build

dir:
	mkdir -p $(OBJ_PATH)
	mkdir -p $(EXEC_PATH)

build: $(OBJS) $(EXEC)

$(EXEC): $(OBJS)
	$(CC) -g -o $@ $(OBJS)

$(OBJ_PATH)/node.o: $(SRC_PATH)/node.c
	$(CC) -g -c $< -I $(INCLUDE_PATH) -o $@ $(OPTIONS)

$(OBJ_PATH)/main.o: $(SRC_PATH)/main.c
	$(CC) -g -c $< -I $(INCLUDE_PATH) -o $@ $(OPTIONS)

clean:
	-rm -rf $(EXE) $(OBJS)
