#include "../include/lexer.h"
#include <string.h>
#define elif else if

/*
int :
	0x... / decimal / 0b...

*/
void append_token(token_t **toks, int *len, token_t t) {
	(*len) += 1;
	(*toks) = realloc(*toks, sizeof(token_t) * (*len));
	(*toks)[*len - 1] = t;
}

int is_space(char c) {
	switch {
		case '\n':
		case '\r':
		case ' ':
		case '\v':
		case '\t':
			return 1;
		default:
			return 0;
	}
}

token_t *lexe(char *text, char *path) {
	int line = 0;
	int len = strlen(text);
	int p = 0;
	token_t *toks = NULL;
	int tok_len = 0;
	while (p < len) {
		if (text[p] == '\n') {
			line++;
			continue;
		}
		if (is_space(text[p])) {
			p++;
			continue;
		}
		if (text[p] == '\'') {
			if (text[p + 1] == '\'') {
				printf("ERROR lexing on line %d character literal cannot be empty\n", line);
			}
			if (text[p + 1] == '\\') {
				
			}
		}
		if (text[p] == '0' && text[p + 1] == 'x') {
			// parse hex 
			uint32_t res = 0;
			p += 2;
			while (text[p] != '\0') {
				if ('A' <= text[p] && text[p] <= 'F') {
					res <<= 4;
					res += text[p] - 'A' + 0b1010;
					p++;
				}
				elif ('a' <= text[p] && text[p] <= 'f') {
					res <<= 4;
					res += text[p] - 'a' + 0b1010;
					p++;
				}
				elif ('0' <= text[p] && text[p] <= '9') {
					res <<= 4;
					res += text[p] - '0';
					p++;
				}
				else
					break;
			}
			append_token(&toks, &tok_len, (token_t){ .line = line,
				.type = token_int_t, .value.i = res}
			);
		}
	}
}