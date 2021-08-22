CC = gcc
CFLAGS = -lcurl -lpcre

# PREFIX is environment variable, but if it is not set, then set default value
ifeq ($(PREFIX),)
    PREFIX := /usr/local
endif

all: lidwoord

lidwoord:
	$(CC) *.c $(CFLAGS) -o bin/lidwoord

install:
	$(CC) *.c $(CFLAGS) -o bin/lidwoord
	mv bin/lidwoord /usr/local/bin/lidwoord

test:
	$(CC) *.c $(CFLAGS) -o bin/lidwoord
	./bin/lidwoord paard
