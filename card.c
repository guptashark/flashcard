#include <stdlib.h>
#include <string.h>

#include "card.h"

struct card *
card_ctor
(char *question, unsigned int q_len, char *answer, unsigned int a_len)
{
	struct card *c = malloc(sizeof(struct card));
	c->q_len = q_len + 1;
	c->a_len = a_len + 1;

	c->question = malloc(sizeof(char) * c->q_len);
	c->answer = malloc(sizeof(char) * c->a_len);

	strcpy(c->question, question);
	strcpy(c->answer, answer);

	return c;
}

char *
card_get_question
(struct card *c)
{
	return c->question;
}

char *
card_get_answer
(struct card *c)
{
	return c->answer;
}


