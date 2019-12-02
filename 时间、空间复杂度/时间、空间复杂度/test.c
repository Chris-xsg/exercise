#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

/*ʱ�临�Ӷ�*/
// �����һ��Func1��������ִ���˶��ٴΣ�
void Func1(int N) 
{
	int count = 0;
	for (int i = 0; i < N; ++i)      //N^2��
	{
		for (int j = 0; j < N; ++j)
		{
			++count;
		}
	}
	for (int k = 0; k < 2 * N; ++k)  //2*N��
	{
		++count;
	}
	int M = 10;
	while (M--)  //10��
	{
		++count;
	}
	printf("%d\n", count); //ִ�д���Ϊ��F(N)=N^2+2*N+10
}//Func1��ʱ�临�Ӷ�����Ϊ��O(N^2),ȥ���˶Խ��Ӱ�첻�����


/*�ռ临�Ӷ�*/
// ����BubbleSort�Ŀռ临�Ӷȣ�ð������
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
}//ʹ���˳���������ռ䣬���Կռ临�Ӷ�Ϊ O(1)

// ����Fibonacci�Ŀռ临�Ӷȣ� 쳲�������
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
}//��̬������N���ռ䣬�ռ临�Ӷ�Ϊ O(N)

// ����׳˵ݹ�Factorial��ʱ�临�Ӷȣ�
long long Factorial(size_t N) 
{
	return N < 2 ? N : Factorial(N - 1)*N;
}//�ݹ������N�Σ�������N��ջ֡��ÿ��ջ֡ʹ���˳������ռ䡣�ռ临�Ӷ�ΪO(N)