#include <stdio.h>
#include <string.h>
#include <assert.h>

#include "card.h"


void card_test(void);

int main(int argc, char *argv[]) {

	(void)argc;
	(void)argv;

	printf("flashcard: (Version Number)\n");

	card_test();
	return 0;
}

void card_test(void) {

	char *q1 = "Simple Question";
	char *a1 = "Simple Answer";
	struct card *c1 = card_ctor(q1, strlen(q1), a1, strlen(a1));

	assert(0 == strcmp(q1, card_get_question(c1)));
	assert(0 == strcmp(a1, card_get_answer(c1)));

	card_dtor(c1);

}
