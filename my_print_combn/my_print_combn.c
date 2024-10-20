#include <stdio.h>
#include <unistd.h>

void my_print_combn(int n);

void my_print_combn(int n)
{
	int i;
	if (!(0 <= n && n <= 10))
		return;
	char nums[10];
	for (i = 0; i < 10; ++i)
		nums[i] = i + '0';

	while (1) {
		write(1, nums, n);
		if (nums[0] == '0' + 10 - n && nums[n - 1] == '9')
			break;
		write(1, ", ", 2);
		i = n - 1;
		while (i >= 0 && nums[i] == (10 - n + i) + '0')
			--i;
		if (i < 0)
			break;
		nums[i]++;
		while (++i < n) {
			nums[i] = nums[i - 1] + 1;
		}
	}
}

int main()
{
	my_print_combn(5);
}
