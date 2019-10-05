#include <stdio.h>
#include <string.h>
#include <assert.h>

#include "sstring.h"
#include "pack.h"
#include "card.h"

void card_test(void);
void pack_test(void);
void string_test(void);

int main(int argc, char *argv[]) {

	(void)argc;
	(void)argv;

	printf("flashcard: (Version Number)\n");

	card_test();
	pack_test();
	string_test();
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

void pack_test(void) {

	struct pack *b = pack_ctor();
	char *q = "q";
	char *a = "a";
	unsigned int q_len = strlen(q);
	unsigned int a_len = strlen(a);

	for(unsigned int i = 0; i < 20; i++) {
		pack_add_card(b, card_ctor(q, q_len, a, a_len));
	}

	assert(pack_get_num_cards(b) == 20);
}

void string_test(void) {

	// empty construction 
	struct string s1;
	string_init(&s1);
	string_printf(&s1);

	struct string s2;
	string_init_literal(&s2, "string_2");
	string_printf(&s2);
	puts("\n");

}
