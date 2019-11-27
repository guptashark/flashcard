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
interpreter_load_config
(struct interpreter *inptr, FILE * config) {

	(void)inptr;
	(void)config;
	// get where a flashcard file is stored.
	// freshly loaded config file.
	// should hold only one line, which is the
	// absolute path of the flashcard file.
}

static
struct pack *
interpreter_load_pack
(struct interpreter *inptr, FILE *pack_path) {
	(void)inptr;

	if(pack_path == NULL) {
		printf("Null pack file!\n");
	}

	struct pack *p = pack_ctor();

	struct string *q = string_ctor_default();
	struct string *a = string_ctor_default();

	int num_items = 0;
	fscanf(pack_path, "%d\n", &num_items);

	struct fc_shell * fs = fc_shell_ctor(pack_path, NULL);

	for (int i = 0; i < num_items; i++) {
		fc_shell_getline(fs, q);
		fc_shell_getline(fs, a);

		struct card * c = card_ctor(q, a);
		pack_add_card(p, c);
	}
	
	fc_shell_dtor(fs);

	string_dtor(q);
	string_dtor(a);


	return p;
}

static
void
interpreter_use_pack
(struct interpreter *inptr, struct pack *p) {
	(void)inptr;

	struct card *c;

	for(size_t i = 0; i < pack_size(p); i++) {
		c = pack_card_at(p, i);

		string_printf(card_get_question(c));
		// fc_shell_insert(inptr->fcs, card_get_question(c));
		
		char a_buff[64];

		scanf("%s", a_buff);
		string_printf(card_get_answer(c));

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
		interpreter_load_config(inptr, config);
	}

	// TODO:
	// do this properly??

	// load the pack.
	FILE * bio_notes = fopen("bio_notes.txt", "r");

	struct pack * bio_cards = interpreter_load_pack(inptr, bio_notes);

	interpreter_use_pack(inptr, bio_cards);

	printf("finished running\n");
}

void
interpreter_dtor
(struct interpreter *inptr) {
	free(inptr);
}
