#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "pack.h"
#include "interpreter.h"

#include "fc_shell.h"

struct interpreter {

	int var;
	struct fc_shell *fcs;
};

static
void
interpreter_create_config
(struct interpreter *inptr) {

	(void)inptr;
	// TODO make it possible to create a config wherever.
	char * home_val = getenv("HOME");
	char config_path [128];

	strcpy(config_path, home_val);
	strcat(config_path, "/.flashcardrc");

	FILE *config = fopen(config_path, "w+");

	// fill the file with some default values
	// TODO fill with useful information!
	fputs("# This is the flashcard config", config);
	fclose(config);
}

static
void
interpreter_load_pack
(struct interpreter *inptr, FILE *pack_path) {
	(void)inptr;
	(void)pack_path;
}

static
void
interpreter_use_pack
(struct interpreter *inptr, struct pack *p) {

	struct card *c;

	for(size_t i = 0; i < pack_size(p); i++) {
		c = pack_card_at(p, i);
		fc_shell_insert(inptr->fcs, card_get_question(c));
	}
}

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
		interpreter_create_config(inptr);
	} else {
		printf("Opened the config file!\n");
	}

	// create a pack!
	if(false) {
		interpreter_load_pack(NULL, NULL);
		interpreter_use_pack(NULL, NULL);
	}

	printf("finished running\n");
}

void
interpreter_dtor
(struct interpreter *inptr) {
	free(inptr);
}
