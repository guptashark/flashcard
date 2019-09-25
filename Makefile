CC = gcc
CFLAGS = -Wall -Werror -Wextra -std=c11

SRC = main.c card.c pack.c

all: 
	$(CC) $(CFLAGS) $(SRC) -o flashcard.out
	./flashcard.out
