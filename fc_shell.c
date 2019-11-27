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

int
fc_shell_extract
(struct fc_shell *fcs, struct string * s) {

	const int buff_size = 1024;
	char buff[buff_size];

	char *ret = fgets(buff, buff_size, fcs->input);

	if(NULL == ret) {
		string_assign_literal(s, "EOF reached");
	} else {
		string_assign_literal(s, buff);
	}

	return 0;
}

int
fc_shell_getline
(struct fc_shell *fcs, struct string * s) {
	const int buff_size = 1024;
	char buff[buff_size];

	int i = 0;

	do {
		// todo - is this cast okay?
		// should we check for stuff...
		buff[i] = (char)(fgetc(fcs->input));
		i++;
	} while ( buff[i-1] != '\n');

	// null terminate the buffer.
	buff[i] = '\0';
	string_assign_literal(s, buff);

	return 0;
}

void
fc_shell_dtor
(struct fc_shell *fcs) {
	free(fcs);
}
