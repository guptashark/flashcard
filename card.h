#ifndef __CARD_H__
#define __CARD_H__

struct card { 
	char *question;
	char *answer;
};

struct card *
card_ctor
(char *question, char *answer);

char *
card_get_question
(struct card *c);

char *
card_get_answer
(struct card *c);

#endif
