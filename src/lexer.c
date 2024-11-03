#include "../include/lexer.h"
#include "oeuf.h"
#include <ctype.h>



token_t *lexe(char *text, char *path, int *len) {
	token_t *tokens = NULL;
	int token_len = 0;
	int p = 0;
	int line = 1;
	while (text[p] != '\0') {
		if (text[p] == '\n') {
			line++;
			p++;
			continue;
		}
		if (text[p] == '\r') {
			p++;
			continue;
		}
		if (isspace(text[p])) {
			p++;
			continue;
		}
	}
	*len = token_len;
	return tokens;
}