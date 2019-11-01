#include <stdlib.h>

#include "pack.h"

struct pack {
	struct vector * cards;
};

struct pack *
pack_ctor(void) {

	struct pack *p = malloc(sizeof(struct pack));
	p->cards = vector_ctor();

	return p;
}

size_t
pack_size(struct pack *p) {
	return vector_size(p->cards);
}

void
pack_add_card(struct pack *p, struct card *c) {
	vector_push_back(p->cards, c);
}

// TODO: size check?
struct card *
pack_card_at(struct pack *p, size_t i) {
	return vector_at(p->cards, i);
}

void 
pack_dtor(struct pack *p) {

	vector_dtor(p->cards);
	free(p);
}
