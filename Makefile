CC = gcc 
CFLAGS = -Wall -Werror -Wextra -std=c11 -pedantic -Wconversion

SRC = main.c card.c pack.c vector.c sstring.c fc_shell.c interpreter.c

all: 
	$(CC) $(CFLAGS) $(SRC) -o flashcard.out
	./flashcard.out
