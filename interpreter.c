#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "interpreter.h"

#include "fc_shell.h"

struct interpreter {

	int var;
};

struct interpreter *
interpreter_ctor(void) {

	struct interpreter *inptr = NULL;
	inptr = malloc(sizeof(struct interpreter));

	return inptr;
}

void
interpreter_run
(struct interpreter *inptr) {
	(void)inptr;

	// check to see if the config file exists in user home. 
	char * home_val = getenv("HOME");
	char config_path [128];

	strcpy(config_path, home_val);
	strcat(config_path, "/.flashcardrc");

	FILE *config = fopen(config_path, "r");
	if (NULL == config) {
		printf("No config found\n");
	} else {
		printf("Opened the config file!\n");
	}

	printf("finished running\n");
}

void
interpreter_dtor
(struct interpreter *inptr) {
	free(inptr);
}
