#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

int get_word(char *buf, int buf_size, FILE *fp)
{
	int ch;
	int index;

	while ((ch = getc(fp)) != EOF && !isalnum(ch))
		;

	index = 0;
	do {
		if (index >= buf_size) {
			fprintf(stderr, "Too long word size\n");
			exit(1);
		}
		buf[index++] = ch;
	} while ((ch = getc(fp)) != EOF && isalnum(ch));
	if (ch == EOF)
		return EOF;
	buf[index] = '\0';

	return 1;
}

// int main(void)
// {
//     char buf[256];

//     while (get_word(buf, 256, stdin) != EOF) {
//         printf("<<%s>>\n", buf);
//     }

//     return 0;
// }
