CC = gcc
INCLUDE = ./src
CFLAGS = -lncurses -I$(INCLUDE)
SRC = ./src/*.c

all: rogue run

rogue: $(SRC) $(INCLUDE)/*.h
	$(CC) $(SRC) $(CFLAGS) -o rogue

run: rogue
	./rogue
.PHONY: run

clean:
	rm rogue
.PHONY: clean
