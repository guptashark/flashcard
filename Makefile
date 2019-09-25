CC = gcc
CFLAGS = -Wall -Werror -Wextra -std=c11

SRC = main.c card.c bank.c

all: 
	$(CC) $(CFLAGS) $(SRC) -o flashcard.out
	./flashcard.out
