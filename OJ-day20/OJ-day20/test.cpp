#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<string>
using namespace std;

//�ַ�����ת
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


//�����Ӵ�����
string findMaxCommonStr(string s1, string s2)//��̬�滮
{
	if (s1.length()>s2.length())
		swap(s1, s2);//s1���ڱ���϶̵��Ӵ�
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
					start = i - maxLen;//��¼������Ӵ�����ʼλ��
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

