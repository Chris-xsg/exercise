#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

//发邮件 递归
long int Recv_Mail(int n)
{
	if (n < 2)
		return 0;
	if (n == 2)
		return 1;
	if (n == 3)
		return 2;
	return (n - 1)*(Recv_Mail(n - 1) + Recv_Mail(n - 2));

}

int main()
{
	int n;
	while (cin >> n)
	{
		cout << Recv_Mail(n) << endl;
	}

	return 0;
}


//最长上升子序列
void Max_RaiseList()
{
	int n;
	while (cin >> n)
	{
		vector<int> group(n,0);
		for (int i = 0; i < n; i++)
		{
			cin >> group[i];
		}
		vector<int> tmp(n,1);
		int len = 1;
		for (int i = 1; i < n; i++)
		{
			for (int j = 0; j < i; j++)
			{
				
				if (group[i] > group[j])
				{
					tmp[i] = max(tmp[i], tmp[j] + 1);
				}
			}
			len = max(len, tmp[i]);
		}
		cout << len << endl;

	}

}

int main()
{
	Max_RaiseList();

	return 0;
}