#include <unistd.h>

void my_putstr_non_printable(char *str);
int is_printable(char c);

int is_printable(char c)
{
	if (32 <= c && c <= 126)
		return 1;
	return 0;
}

void my_putstr_non_printable(char *str)
{
	int index;
	index = 0;

	while (str[index]) {
		if (is_printable(str[index])) {
			write(1, &str[index], 1);
		} else {
			write(1, "\\", 1);
			write(1, &"0123456789abcdef"[str[index] / 16], 1);
			write(1, &"0123456789abcdef"[str[index] % 16], 1);
		}
		index++;
	}
}


int main(void)
{
	my_putstr_non_printable("Coucou\ntu vas bien ?");
}
