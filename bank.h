#ifndef __PACK_H__
#define __PACK_H__

#include "card.h"

struct pack {

	struct card **cards;
	unsigned int num_cards;
	unsigned int capacity;
};

struct pack *
pack_ctor(void);

unsigned int
pack_get_num_cards(struct pack *b);

void
pack_add_card(struct pack *b, struct card *c);

void
pack_dtor(struct pack *b);

#endif
