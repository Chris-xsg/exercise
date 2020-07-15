#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
#include<vector>
#include<math.h>
using namespace std;


//字符串计数
void Str_Count()
{
	string s1, s2;
	int len1, len2;
	while (cin >> s1 >> s2 >> len1 >> len2)
	{
		//将长度补全成len2
		if (s1.length() < len2)
		{
			s1.append(len2 - s1.length(), 'a' - 1);
		}
		if (s2.length() < len2)
		{
			s2.append(len2 - s2.length(), 'z' + 1);
		}
		long long sum = 0;
		int k = 0;
		while (s1[k] == s2[k])
		{//找第一个相对位置不相等的位置下标
			k++;
		}
		
		if (s1[k] < s2[k] && len1 <= len2)
		{//计算位于当前下标的情况
			for (int i = len1 - 1; i < len2; i++)
			{
				if (i == k)
				{
					if (k == len1 - 1 && k == len2 - 1)
						sum += s2[k] - s1[k] - 1;
					else
						sum += s2[k] - s1[k];
				}
				else
					sum += (s2[k] - s1[k] - 1)*pow(26, i - k);
			}
			k++;
			for (int i = len1; i <= len2; i++)
			{
				for (int j = k; j<i; j++)
					sum += ('z' - s1[j])*pow(26, i - j - 1);
				for (int j = k; j<i; j++)
					sum += (s2[j] - 'a')*pow(26, i - j - 1);
			}
		}
		cout << sum << endl;
	}

}


//最长公共子序列-->动态规划  dp矩阵
void Find_PublicStr()
{
	string s1, s2;
	while (cin >> s1 >> s2)
	{
		vector<vector<int>> dp(s1.size() + 1, vector<int>(s2.size() + 1, 0));
		for (int i = 1; i <= s1.size(); i++)
		for (int j = 1; j <= s2.size(); j++)
		{
			if (s1[i - 1] == s2[j - 1])
				dp[i][j] = dp[i - 1][j - 1] + 1;
			else
				dp[i][j] = dp[i - 1][j] > dp[i][j - 1] ? dp[i - 1][j] : dp[i][j - 1];
		}
		cout << dp[s1.size()][s2.size()] << endl;
	}
}



int main()
{
	//Str_Count();
	Find_PublicStr();
	return 0;
}
