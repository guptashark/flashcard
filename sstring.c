#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#include "sstring.h"

void
string_init
(struct string *s) {
	s->size = 0;
	s->capacity = 32;
	s->arr = malloc(sizeof(char) * s->capacity);
}

void
string_init_literal
(struct string *s, const char *str) {

	s->size = strlen(str);
	s->capacity = (2 + (s->size / 32)) * 32;
	s->arr = malloc(sizeof(char) * s->capacity);
	strcpy(s->arr, str);
}

// TODO - does strcpy copy the null terminator? 
void
string_init_copy
(struct string *s, const struct string *src) {

	s->size = src->size;
	s->capacity = src->capacity;
	s->arr = malloc(sizeof(char) * s->capacity);
	strcpy(s->arr, src->arr);
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

void 
string_uninitialize
(struct string *s) {
	
	s->size = 0;
	s->capacity = 0;
	free(s->arr);
}
