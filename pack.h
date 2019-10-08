#ifndef __PACK_H__
#define __PACK_H__

#include "vector.h"

#include "card.h"

struct pack;


struct pack *
pack_ctor
(void);

size_t
pack_get_num_cards
(struct pack *b);

void
pack_add_card
(struct pack *b, struct card *c);

void
pack_dtor(struct pack *b);

#endif
