#include <stdio.h>
#include "word_manage_p.h"

void dump_word(FILE *fp)
{
	while (word_header != NULL) {
		printf("%d : %s\n", word_header->count, word_header->name);
		word_header = word_header->next;
	}
}
