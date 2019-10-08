#include <stdio.h>
#include <string.h>
#include <assert.h>

#include "sstring.h"
#include "pack.h"
#include "card.h"

void fc_shell_test(void);
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
	struct string *q1_s = string_ctor_literal(q1);
	struct string *a1_s = string_ctor_literal(a1);

	struct card *c1 = card_ctor(q1_s, a1_s);

	assert(0 == string_compare_literal(card_get_question(c1), q1));
	assert(0 == string_compare_literal(card_get_answer(c1), a1));

	card_dtor(c1);
	string_dtor(q1_s);
	string_dtor(a1_s);
}

void pack_test(void) {

	struct pack *p = pack_ctor();

	char *q = "q";
	char *a = "a";

	struct string *q1_s = string_ctor_literal(q);
	struct string *a1_s = string_ctor_literal(a);

	for(unsigned int i = 0; i < 20; i++) {
		struct card *c = card_ctor(q1_s, a1_s);
		pack_add_card(p, c);
	}

	assert(pack_get_num_cards(p) == 20);

	pack_dtor(p);
	string_dtor(q1_s);
	string_dtor(a1_s);
}

void string_test(void) {

	// empty construction 
	struct string *s1 = string_ctor_default();
	string_printf(s1);

	struct string *s2 = string_ctor_literal("string_2");
	string_printf(s2);
	puts("\n");

}


void fc_shell_test(void) {
	// TODO the test itself.
}
