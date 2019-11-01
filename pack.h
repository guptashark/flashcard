#ifndef __PACK_H__
#define __PACK_H__

#include "vector.h"

#include "card.h"

struct pack;


struct pack *
pack_ctor
(void);

size_t
pack_size
(struct pack *b);

void
pack_add_card
(struct pack *b, struct card *c);

struct card *
pack_card_at(struct pack *p, size_t i);

void
pack_dtor(struct pack *b);

#endif
