#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#include "sstring.h"

struct string {

	uint32_t size;
	uint32_t capacity;
	char *arr;
};

///////////////////////////////////
// constructors and destructors
///////////////////////////////////

// helper ctor
// isn't available to the user
// and is used internally by other ctors.
static
struct string *
string_ctor_helper
(uint32_t capacity) {

	struct string *s = malloc(sizeof(struct string));
	s->size = 0;
	s->capacity = capacity;
	s->arr = malloc(sizeof(char) * s->capacity);
	return s;
}

// 1: default ctor
struct string *
string_ctor_default
(void) {

	struct string *s = string_ctor_helper(32);
	return s;
}

// 5: literal constructor
// NOT FINISHED!!!
struct string *
string_ctor_literal
(const char *lit) {

	size_t len = strlen(lit);
	(void)len;
	struct string *s = string_ctor_helper(32);
	return s;
}

// 7: copy constructor
struct string *
string_ctor_copy
(const struct string *t) {

	struct string *s = string_ctor_helper(t->capacity);
	s->size = t->size;
	strcpy(s->arr, t->arr);
	return s;
}

void
string_dtor
(struct string *s) {
	free(s->arr);
	free(s);
}
int
string_fprintf
(struct string *s, FILE *f) {
	return fprintf(f, "%s", s->arr);
}

int
string_printf
(struct string *s) {
	return printf("%s", s->arr);
}
