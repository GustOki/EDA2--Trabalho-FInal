CC     = gcc
CFLAGS = -std=c99 -Wall -Wextra -Isrc -Itests

test_grafo: tests/test_grafo.c src/grafo.c src/grafo.h
	$(CC) $(CFLAGS) -fsanitize=address -o tests/test_grafo tests/test_grafo.c src/grafo.c -lm

test: test_grafo
	./tests/test_grafo

clean:
	rm -f tests/test_grafo

.PHONY: test clean
