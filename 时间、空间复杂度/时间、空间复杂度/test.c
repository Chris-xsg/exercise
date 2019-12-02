#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

/*时间复杂度*/
// 请计算一下Func1基本操作执行了多少次？
void Func1(int N) 
{
	int count = 0;
	for (int i = 0; i < N; ++i)      //N^2次
	{
		for (int j = 0; j < N; ++j)
		{
			++count;
		}
	}
	for (int k = 0; k < 2 * N; ++k)  //2*N次
	{
		++count;
	}
	int M = 10;
	while (M--)  //10次
	{
		++count;
	}
	printf("%d\n", count); //执行次数为：F(N)=N^2+2*N+10
}//Func1的时间复杂度最终为：O(N^2),去掉了对结果影响不大的项


/*空间复杂度*/
// 计算BubbleSort的空间复杂度？冒泡排序
void BubbleSort(int* a, int n) 
{
	assert(a);
	for (size_t end = n; end > 0; --end)
	{
		int exchange = 0;
		for (size_t i = 1; i < end; ++i)
		{
			if (a[i - 1] > a[i])
			{
				Swap(&a[i - 1], &a[i]);
				exchange = 1;
			}
		}
		if (exchange == 0)
			break;
	}
}//使用了常数个额外空间，所以空间复杂度为 O(1)

// 计算Fibonacci的空间复杂度？ 斐波那契数
long long* Fibonacci(size_t n)
{
	if (n == 0)
		return NULL;
	long long * fibArray = new long long[n + 1];
	fibArray[0] = 0;
	fibArray[1] = 1; for (int i = 2; i <= n; ++i)
	{
		fibArray[i] = fibArray[i - 1] + fibArray[i - 2];
	}
	return fibArray;
}//动态开辟了N个空间，空间复杂度为 O(N)

// 计算阶乘递归Factorial的时间复杂度？
long long Factorial(size_t N) 
{
	return N < 2 ? N : Factorial(N - 1)*N;
}//递归调用了N次，开辟了N个栈帧，每个栈帧使用了常数个空间。空间复杂度为O(N)