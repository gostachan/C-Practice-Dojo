#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "word_manage_p.h"

static void shift_array(int i);
static char *my_strdup(const char *src);
void add_word(char *word);


static void shift_array(int index)
{
	for (int i = num_of_word; i >= index; --i) {
		word_array[i + 1] = word_array[i];
	}
	num_of_word++;
}

static char *my_strdup(const char *src)
{
	char *dest;

	dest = malloc(sizeof(char) * (strlen(src) + 1));
	strcpy(dest, src);

	return dest;
}

void add_word(char *word)
{
	int i;
	int result;

	if (num_of_word >= WORD_NUM_MAX) {
		fprintf(stderr, "too many words.\n");
		exit(1);
	}
	for (i = 0; i < num_of_word; ++i) {
		result = strcmp(word_array[i].name, word);
		if (result >= 0)
			break;
	}
	if (num_of_word != 0 && result == 0) {
		word_array[i].count++;
	} else {
		shift_array(i);
		word_array[i].name = my_strdup(word);
		word_array[i].count = 1;
	}
}
