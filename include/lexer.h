#ifndef LEXER_H
#define LEXER_H

#include <stdint.h>
#include "../oeuf/oeuf.h"

typedef struct {
	i32 line;
	char type;
	union {
		uint32_t i;
		double f;
		char *s;
		i16 sy;
	}value;
} token_t;

token_t *lexe(char *text, char *path);

enum token_types {
	token_null_t,
	token_int_t
};

#endif