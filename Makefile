CC = gcc
CFLAGS = -lncurses -I./src/
SRC = ./src/*.c

all: rogue run

rogue: $(SRC)
	$(CC) $(SRC) $(CFLAGS) -o rogue

run: rogue
	./rogue
.PHONY: run

clean:
	rm rogue
.PHONY: clean
