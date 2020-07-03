#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;


/**
*	正数数组中的最小不可组成和
*	输入：正数数组arr
*	返回：正数数组中的最小不可组成和
*/
//01背包问题---动态规划
int getFirstUnFormedNum(vector<int> arr, int len) 
{
	int min = arr[0]; int sum = 0;
	for (int i = 0; i < len; i++)
	{
		sum += arr[i];//求得和--总重量
		if (arr[i] < min)
		{
			min = arr[i];//最小的数---重量最小
		}
	}
	vector<int> dp(sum + 1, 0);
	for (int i = 0; i < len; i++)
	{//将所有可能的重量放入dp中
		for (int j = sum; j >= arr[i]; j--)
		{
			if (dp[j - arr[i]] + arr[i] > dp[j])
			{
				dp[j] = dp[j - arr[i]] + arr[i];
			}

		}
	}
	for (int i = min; i <= sum; i++)
	{//在dp中找没有出现的i
		if (i != dp[i])
			return i;
	}
	return sum + 1;//没有则返回sum+1

}


//有假币
int Find_FalseMoney(int n)
{//分成三份，两份一样，一份可一样可不一样，先称前两份
//一样的话就再分剩下一份，不一样的话再称两份中轻的一份，如此循环
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