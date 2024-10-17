#include <stdio.h>
#include <stdlib.h>
#include "word_manage_p.h"

void word_finalize(void)
{
	Word *tmp;

	while (word_header != NULL) {
		tmp = word_header->next;
		free(word_header->name);
		free(word_header);
		word_header = tmp;
	}
}
