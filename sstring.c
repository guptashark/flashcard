#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#include "sstring.h"

struct string {

	size_t size;
	size_t capacity;
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
(size_t capacity) {

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
struct string *
string_ctor_literal
(const char *lit) {

	size_t len = strlen(lit);
	size_t capacity = (2 + (len / 32)) * 32;
	struct string *s = string_ctor_helper(capacity);
	s->size = len;
	strcpy(s->arr, lit);
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


//////////////////////
// capacity
//////////////////////

size_t
string_size
(struct string *s) {
	return s->size;
}

//////////////////////
// operations
//////////////////////

// compare
int
string_compare_string
(struct string *s, struct string *t) {
	return strcmp(s->arr, t->arr);
}

int
string_compare_literal
(struct string *s, const char *t) {
	return strcmp(s->arr, t);
}

int
string_fprintf
(FILE *f, struct string *s) {
	return fprintf(f, "%s", s->arr);
}

int
string_printf
(struct string *s) {
	return printf("%s", s->arr);
}
