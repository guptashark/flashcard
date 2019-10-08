#ifndef __CARD_H__
#define __CARD_H__

#include <stdio.h>

#include "sstring.h"

struct card *
card_ctor
(struct string *question, struct string *answer);

struct string *
card_get_question
(struct card *c);

struct string *
card_get_answer
(struct card *c);

void
card_dtor
(struct card *c);

#endif
