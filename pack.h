#ifndef __PACK_H__
#define __PACK_H__
// needed stl 
#include "vector.h"

// needed project structures
#include "card.h"

struct pack {

	// design decision: use the vector itself, 
	// vs a pointer to a vector. 
	struct vector cards;
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
