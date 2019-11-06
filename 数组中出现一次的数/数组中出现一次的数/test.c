#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<assert.h>

void print_once_num(int* a, int n)
{
	assert(a);
	int ret = 0;
	for (int i = 0; i < n; ++i)
	{
		ret ^= a[i];
	}

	// ret就是只出现一次的那两个异或的结果
	int pos = 0;
	for (; pos < 32; ++pos)
	{
		if (ret & (1<<pos))
		{
			break;
		}
	}

	// ret的第pos位为1
	int ret0 = 0, ret1 = 0;
	for (int i = 0; i < n; ++i)
	{
		if (a[i] & (1 << pos)) // pos位1
		{
			ret1 ^= a[i];
		}
		else // pos位0
		{
			ret0 ^= a[i];
		}
	}

	printf("%d, %d\n", ret0, ret1);
}

int main()
{
	int a[] = { 2, 3, 4, 2, 5, 4, 5, 6, 8, 8, 6 ,1, 6, 6};
	print_once_num(a, sizeof(a) / sizeof(int));

	return 0;
}