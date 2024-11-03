#ifndef LEXER_H
#define LEXER_H

#include <stdint.h>
#include "oeuf.h"

typedef struct {
	u32 line;
	char type;
	union {
		u64 i;
		double f;
		char *s;
		u16 sy;
	}value;
} token_t;

token_t *lexe(char *text, char *path, int *len);

enum token_types {
	token_null_t,
	token_int_t
};

#endif