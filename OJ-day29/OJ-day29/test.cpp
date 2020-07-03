#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;


/**
*	���������е���С������ɺ�
*	���룺��������arr
*	���أ����������е���С������ɺ�
*/
//01��������---��̬�滮
int getFirstUnFormedNum(vector<int> arr, int len) 
{
	int min = arr[0]; int sum = 0;
	for (int i = 0; i < len; i++)
	{
		sum += arr[i];//��ú�--������
		if (arr[i] < min)
		{
			min = arr[i];//��С����---������С
		}
	}
	vector<int> dp(sum + 1, 0);
	for (int i = 0; i < len; i++)
	{//�����п��ܵ���������dp��
		for (int j = sum; j >= arr[i]; j--)
		{
			if (dp[j - arr[i]] + arr[i] > dp[j])
			{
				dp[j] = dp[j - arr[i]] + arr[i];
			}

		}
	}
	for (int i = min; i <= sum; i++)
	{//��dp����û�г��ֵ�i
		if (i != dp[i])
			return i;
	}
	return sum + 1;//û���򷵻�sum+1

}


//�мٱ�
int Find_FalseMoney(int n)
{//�ֳ����ݣ�����һ����һ�ݿ�һ���ɲ�һ�����ȳ�ǰ����
//һ���Ļ����ٷ�ʣ��һ�ݣ���һ���Ļ��ٳ����������һ�ݣ����ѭ��
	int count;
	while (n)
	{
		if (n == 1)
			break;
		if (n % 3 == 0)
			n /= 3;
		else
			n = n / 3 + 1;
		count++;
	}
	return count;

}


int main()
{
	int n;
	while (cin >> n)
	{
		if (n == 0)
			break;
		cout << Find_FalseMoney(n) << endl;
	}

	return 0;

}