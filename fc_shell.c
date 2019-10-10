#include <stdlib.h>
#include "fc_shell.h"

struct fc_shell {

	FILE *input;
	FILE *output;
};

struct fc_shell *
fc_shell_ctor
(FILE *input, FILE *output) {

	struct fc_shell *fcs = malloc(sizeof(struct fc_shell));
	fcs->input = input;
	fcs->output = output;
	return fcs;
}

int
fc_shell_insert
(struct fc_shell *fcs, struct string* s) {

	return string_fprintf(fcs->output, s);
}

// TODO: this is just a sample function for now.
int
fc_shell_extract
(struct fc_shell *fcs, struct vector ** data) {

	(void)fcs;

	struct vector *v = vector_ctor();
	struct string *s1 = string_ctor_literal("Hello");
	struct string *s2 = string_ctor_literal("World!");

	vector_push_back(v, s1);
	vector_push_back(v, s2);

	*data = v;
	return 0;
}

void
fc_shell_extraction_dtor
(struct fc_shell *fcs, struct vector *data) {

	(void)fcs;

	for(size_t i = 0; i < vector_size(data); i++) {
		string_dtor(vector_at(data, i));
	}

	vector_dtor(data);
}

void
fc_shell_dtor
(struct fc_shell *fcs) {
	free(fcs);
}
