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

void
fc_shell_dtor
(struct fc_shell *fcs) {
	free(fcs);
}
