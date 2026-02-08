.PHONY: clean tidy

CC=gcc
LFLAGS=-lm
CFLAGS=-Wall -Werror -std=c99
HDR=$(wildcard *.h)
SRC=$(wildcard *.c)
OBJ=$(SRC:.c=.o)

CFLAGS_TEST=$(CFLAGS)
OBJ_TEST=$(SRC_TEST:.c=.o)

main: $(OBJ)
	$(CC) $(CFLAGS) -o main $(OBJ) $(LFLAGS)

%.o: %.c
	$(CC) -c $(CFLAGS) -o $@ $< $(LFLAGS)

clean:
	rm -rf *.o main
