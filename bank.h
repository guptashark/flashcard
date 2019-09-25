#ifndef __BANK_H__
#define __BANK_H__

#include "card.h"

struct bank {

	struct card **cards;
	unsigned int num_cards;
	unsigned int capacity;
};

struct bank *
bank_ctor(void);

unsigned int
bank_get_num_cards(struct bank *b);

void
bank_add_card(struct bank *b, struct card *c);

void
bank_dtor(struct bank *b);

#endif
