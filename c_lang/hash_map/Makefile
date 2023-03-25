
CC=gcc
CFLAGS=-g -Wall

all: hash_map

%.o: %.c %.h
	$(CC) $(CFLAGS) -c $^

hash_map: main.c
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm *.o hash_map
