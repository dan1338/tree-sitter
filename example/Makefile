CC=gcc
CFLAGS=-Wall -I../lib/include -g

main: main.c
	$(CC) $(CFLAGS) $< -o $@ ../libtree-sitter.a ../../tree-sitter-c/src/parser.c

clean:
	rm main
	
