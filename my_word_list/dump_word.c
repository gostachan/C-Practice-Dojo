#include <stdio.h>
#include "word_manage_p.h"

void dump_word(FILE *fp)
{
	Word *cp_word_header = word_header;
	while (cp_word_header != NULL) {
		printf("%d : %s\n", cp_word_header->count, cp_word_header->name);
		cp_word_header = cp_word_header->next;
	}
}
