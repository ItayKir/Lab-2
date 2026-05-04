CC = gcc
CFLAGS = -Wall -g -m32

all: myshell looper

#LineParser: LineParser.c
#	$(CC) $(CFLAGS) -o LineParser LineParser.c

myshell: myshell.c
	$(CC) $(CFLAGS) -o myshell myshell.c LineParser.c

looper: looper.c
	$(CC) $(CFLAGS) -o looper looper.c

clean:
	rm -f myshell looper