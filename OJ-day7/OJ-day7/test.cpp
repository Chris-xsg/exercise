#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<stdio.h>
#include<stack>
using namespace std;

////����Fibonacci���ĺ���
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
//	//����i��ֵ���ô�һ��û��ϵ����ΪFibonacci������Ȼ��һ�������N
//	for (int i = 0; i < 100000; i++)
//	{
//		if (Fibonacci(i) - N > 0)
//		{
//			num = i;
//			break;
//		}
//	}
//	//��ǰһ�����Ǻ�һ��Fibonacci������N��һЩ
//	if (Fibonacci(num) - N < N - Fibonacci(num - 1))
//		cout << Fibonacci(num) - N;
//	else
//		cout << N - Fibonacci(num - 1);
//	return 0;
//}


//�Ϸ����������ж�
class Parenthesis {
public:
	bool chkParenthesis(string A, int n) {
		
		if (A.empty() || n % 2 == 1)
		{ //Ϊ�գ�����Ϊ����������false
			return false;
		}

		stack<char> s1;
		for (int i = 0; i<A.size(); i++)
		{
			if (A[i] == '(') //Ϊ'(' ��ջ
				s1.push(A[i]);
			else if (A[i] == ')')//Ϊ')' ��ջ
			{
				if (s1.empty())//��ջΪ���򷵻�false
					return false;
				s1.top();
			}
			else //Ϊ�����ַ�ֱ�ӷ���false
				return false;
		}
		if (s1.empty())//���ջΪ�ձ�ʾΪ�Ϸ�������true
			return true;
	}
};