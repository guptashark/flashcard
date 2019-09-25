#include <stdlib.h>

#include "bank.h"

struct bank *
bank_ctor(void) {

	struct bank *b = malloc(sizeof(struct bank));

	// default initialization
	b->num_cards = 0;
	b->capacity = 8;
	b->cards = malloc(sizeof(struct card *) * b->capacity);

	return b;
}

unsigned int
bank_get_num_cards(struct bank *b) {
	return b->num_cards;
}

void
bank_add_card(struct bank *b, struct card *c) {
	
	if(b->num_cards == b->capacity) {
		b->capacity = b->capacity + 32;
		struct card ** old_cards_arr = b->cards;
		b->cards = malloc(sizeof(struct card *) * b->capacity);

		for(unsigned int i = 0; i < b->num_cards; i++) {
			b->cards[i] = old_cards_arr[i];
		}
	} 

	b->cards[b->num_cards] = c;
	b->num_cards++;
}

void 
bank_dtor(struct bank *b) {
	
	for(unsigned int i = 0; i < b->num_cards; i++) {
		card_dtor(b->cards[i]);
	}

	free(b);
}
