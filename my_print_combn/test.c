void my_print_combn(int n);

#include <stdio.h>
#include <unistd.h>

void print_nums(int *nums, int n) {
	for (int i = 0; i < n; i++) {
		write(1, &"0123456789"[nums[i]], 1);
	}
}

void rec(int *nums, int n, int index, int first)
{
}

void my_print_combn(int n)
{
	int nums[11];
	for (int i = 0; i < 11; i++) {
		nums[i] = i;
	}
	rec(nums, n, 0, 1);
}

int main()
{
	my_print_combn(3);
}
