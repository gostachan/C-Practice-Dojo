#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "word_manage.h"
#include "word_manage_p.h"


static char *my_strdup(char *src)
{
	char *dest;

	dest = malloc(sizeof(char) * (strlen(src) + 1));
	strcpy(dest, src);

	return dest;
}

static Word *create_word(char *name)
{
	Word *new_word;

	new_word = malloc(sizeof(Word));
	new_word->name = my_strdup(name);
	new_word->count = 1;

	return new_word;
}

void add_word(char *word)
{
	Word *pre;
	Word *pos;
	Word *new_word;
	int diff;

	for (pos = word_header; pos != NULL; pos = pos->next) {
		diff = strcmp(pos->name, word);
		if (diff >= 0) break;
		pre = pos;
	}


	if (pos == word_header && diff != 0) {
		new_word = create_word(word);
		new_word->next = word_header;
		word_header = new_word;
	} else if (diff == 0) {
		pos->count++;
	} else {
		new_word = create_word(word);
		pre->next = new_word;
		new_word->next = pos;
	}
}

// #include <stdio.h>
// void dump_word(FILE *fp);
// Word *word_header;
// int main()
// {
// 	add_word("c");
// 	add_word("b");
// 	add_word("a");
// 	add_word("a");
// 	add_word("c");
// 	add_word("b");
// 	add_word("yoi");
// 	add_word("code");
// 	add_word("kaketa");
// 	dump_word(stdout);
// 	printf("word_header->name = %s\n", word_header->name);
// }
