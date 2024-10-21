#include <stdio.h>
#include <stdlib.h>

int is_charset(char ch, char *charset);
int word_cnt(char *str, char *charset);
char *inline_cpy(char **dest, const char *src, int begin, int end);
char **ft_split(char *str, char *charset);


int is_charset(char ch, char *charset)
{
	int index;
	index = 0;
	while (charset[index]) {
		if (ch == charset[index])
			return 1;
		index++;
	}
	return 0;
}


int word_cnt(char *str, char *charset)
{
	int res;
	int index;

	index = 0;
	res = 1;
	while (str[index] && is_charset(str[index], charset))
		index++;

	while (str[index + 1]) {
		index++;
		if (is_charset(str[index - 1], charset) && !is_charset(str[index], charset))
		{
			res++;
		}
	}

	return res;
}

char *inline_cpy(char **dest, const char *src, int begin, int end)
{
	int index;

	if (begin == end)
		return NULL;
	*dest = malloc(sizeof(char) * (end - begin + 1));
	(*dest)[end - begin] = '\0';
	index = 0;

	while (begin + index != end) {
		(*dest)[index] = src[begin + index];
		index++;
	}

	return *dest;
}

char **ft_split(char *str, char *charset)
{

	char **res;
	int wc;
	int begin;
	int end;
	wc = word_cnt(str, charset);

	res = malloc(sizeof(res[0]) * (wc + 1));
	res[wc] = NULL;

	// printf("wc = %d\n", wc);

	begin = 0;
	int index = 0;
	while (str[begin] && is_charset(str[begin], charset))
		begin++;
	while (str[begin] && str[end]) {
		while (str[begin] && is_charset(str[begin], charset))
			begin++;
		end = begin;
		while (str[end] && !is_charset(str[end], charset))
			end++;
		// printf("%d: begin = %d, end = %d, diff = %d\n", ++index, begin, end, end - begin);
		inline_cpy(&res[index++], str, begin, end);
		begin = end;
	}


	return res;
}

int main(void)
{

	int wc;
	int i;
	char str[100] = " hello, i'm misaki nice to meet you!    ";
	char **splited_array;
	wc = word_cnt(str, " ");


	splited_array = ft_split(str, " ");
	i = 0;
	while (splited_array[i] != NULL) {
		printf("%s\n", splited_array[i++]);
	}

	i = 0;
	while (splited_array[i] != NULL)
		free(splited_array[i++]);
	free(splited_array[i]);
	free(splited_array);
}
