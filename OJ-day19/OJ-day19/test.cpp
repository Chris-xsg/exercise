#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<string>
using namespace std;

//����ˮ��������һƿ��ʣ����ƿ�ӿ���������һƿ
void Drink_Soda()
{
	vector<int > out;
	int drink = 0;
	for (int i = 0; i < 10; i++)
	{
		int empty = 0;
		cin >> empty;
		if (empty == 0)
			break;
		while (empty)
		{
			if (empty > 2)
			{
				int flag = 0;
				flag = empty / 3;
				empty = empty % 3 + flag;
				drink += flag;
			}
			else if (empty == 2)
			{
				empty = 1;
				drink++;
			}
			else
			{
				empty = 0;
			}
		}
		out.push_back(drink);
		drink = 0;
	}
	
	for (auto e : out)
	{
		cout << e << endl;

	}

}

//���������ַ����е�������Ӵ�
string Find_TheMaxPublicStr()
{
	string a, b;
	while (getline(cin, a) && getline(cin, b))
	{
		if (a.empty() || b.empty())
		{
			return NULL;
		}
		int len1 = a.size();
		int len2 = b.size();
		string max = "",tmp = "";
		if (len1 > len2)
		{
			for (int i = 0; i < len2; i++)
			{
				for (int j = 0; j < len1; j++)
				{
					if (b[i] == a[j])
					{
						while (b[i]  == a[j] && b[i] != '\0')
						{
							tmp += b[i];
							i++;
							j++;
						}
						if (tmp.size() > max.size())
						{
							max = tmp;
						}
						tmp = "";
					}
				}
			}
		}
		else
		{
			for (int i = 0; i < len1; i++)
			{
				for (int j = 0; j < len2; j++)
				{
					if (a[i] == b[j])
					{
						while (a[i] == b[j] && a[i] != '\0')
						{
							tmp += a[i];
							i++;
							j++;
						}
						if (tmp.size() > max.size())
						{
							max = tmp;
						}
						tmp = "";
					}
				}
			}
		}
		return max;

	}
}


void findMaxCommonStr(string s1, string s2)//��̬�滮
{
	if (s1.length()>s2.length())
		swap(s1, s2);//s1���ڱ���϶̵��Ӵ�
	int len1 = s1.length(), len2 = s2.length();
	int maxLen = 0, start = 0;
	vector<vector<int> >dp(len1 + 1, vector<int>(len2 + 1, 0));
	for (int i = 1; i <= len1; ++i)
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
	cout << s1.substr(start, maxLen) << endl;
}

int main()
{
	//Drink_Soda();
	//cout << Find_TheMaxPublicStr() << endl;
	string s1, s2;
	while (cin >> s1 >> s2)
	{
		findMaxCommonStr(s1, s2);
	}

	return 0;
}