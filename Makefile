CC = gcc

CFLAGS = -Wall -gcc

all: LineParser

LineParser: LineParser.c
	$(CC) $(CFLAGS) -o LineParser LineParser.c

clean:
	rm -f LineParser