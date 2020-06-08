#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<stdio.h>
#include<stack>
using namespace std;

////定义Fibonacci数的函数
//int Fibonacci(int N)
//{
//	if (N == 0)
//		return 0;
//	else if (N == 1)
//		return 1;
//	else
//		return Fibonacci(N - 1) + Fibonacci(N - 2);
//}
//
//int main()
//{
//	int N;
//	cin >> N;
//	int num = 0;
//	//这里i的值设置大一点没关系，因为Fibonacci函数必然在一个点大于N
//	for (int i = 0; i < 100000; i++)
//	{
//		if (Fibonacci(i) - N > 0)
//		{
//			num = i;
//			break;
//		}
//	}
//	//看前一个还是后一个Fibonacci数距离N近一些
//	if (Fibonacci(num) - N < N - Fibonacci(num - 1))
//		cout << Fibonacci(num) - N;
//	else
//		cout << N - Fibonacci(num - 1);
//	return 0;
//}


//合法括号序列判断
class Parenthesis {
public:
	bool chkParenthesis(string A, int n) {
		
		if (A.empty() || n % 2 == 1)
		{ //为空，长度为奇数都返回false
			return false;
		}

		stack<char> s1;
		for (int i = 0; i<A.size(); i++)
		{
			if (A[i] == '(') //为'(' 入栈
				s1.push(A[i]);
			else if (A[i] == ')')//为')' 出栈
			{
				if (s1.empty())//若栈为空则返回false
					return false;
				s1.top();
			}
			else //为其它字符直接返回false
				return false;
		}
		if (s1.empty())//最后栈为空表示为合法，返回true
			return true;
	}
};