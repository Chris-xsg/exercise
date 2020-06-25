#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<string>
using namespace std;

//字符串翻转
void Reverse()
{
	string str;
	while (getline(cin, str))
	{
		string::iterator begin = str.begin();
		string::iterator end = str.end() - 1;
		while (begin < end)
		{
			swap(*begin, *end);
			begin++;
			end--;
		}
		cout << str << endl;
	}

}


//公共子串计算
string findMaxCommonStr(string s1, string s2)//动态规划
{
	if (s1.length()>s2.length())
		swap(s1, s2);//s1用于保存较短的子串
	int len1 = s1.length(), len2 = s2.length();
	int maxLen = 0, start = 0;
	vector<vector<int> >dp(len1 + 1, vector<int>(len2 + 1, 0));
	for (int i = 1; i <= len1; ++i)
	{
		for (int j = 1; j <= len2; ++j)
		{
			if (s1[i - 1] == s2[j - 1])
			{
				dp[i][j] = dp[i - 1][j - 1] + 1;
				if (dp[i][j]>maxLen)
				{
					maxLen = dp[i][j];
					start = i - maxLen;//记录最长公共子串的起始位置
				}
			}
		}
	}
	string ret = s1.substr(start, maxLen);
	return ret;
}

void Len()
{
	string First, Second;
	while (getline(cin, First) && getline(cin, Second))
	{
		string str = findMaxCommonStr(First,Second);
		cout << str.size() << endl;
	}
	
}


int main()
{
	//Reverse();
	Len();
	return 0;
}

