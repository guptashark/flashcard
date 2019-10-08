#include <stdlib.h>
#include <string.h>

#include "card.h"

struct card {
	struct string * question;
	struct string * answer;
};

// TODO: How do we guarantee to the caller that we're
// not going to tamper with their strings?
// How do we guarantee that we're making our own copies?
struct card *
card_ctor
(struct string *question, struct string *answer) {

	struct card *c = malloc(sizeof(struct card));
	c->question = string_ctor_copy(question);
	c->answer = string_ctor_copy(answer);
	return c;
}

struct string *
card_get_question
(struct card *c)
{
	return c->question;
}

struct string *
card_get_answer
(struct card *c)
{
	return c->answer;
}

// Since we made our own copies, we're responsible for deleting them.
void
card_dtor
(struct card *c)
{
	string_dtor(c->question);
	string_dtor(c->answer);
	free(c);
}
