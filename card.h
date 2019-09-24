#ifndef __CARD_H__
#define __CARD_H__

struct card { 
	char *question;
	unsigned int q_len;

	char *answer;
	unsigned int a_len;
};

struct card *
card_ctor
(char *question, unsigned int q_len, char *answer, unsigned int a_len);

char *
card_get_question
(struct card *c);

char *
card_get_answer
(struct card *c);

#endif
