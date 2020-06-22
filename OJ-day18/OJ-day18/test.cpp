#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
#include<vector>
using namespace std;


//ͳ��ÿ�������ӵ�����
//int main()
//{
//	int month, counts;
//	while (cin >> month)
//	{
//		int one = 1;//һ���µ�������
//		int two = 0;//�����µ�������
//		int three = 0;//�����µ�������
//
//		while (--month)
//		{
//			three += two;
//			two = one;
//			one = three;
//		}
//		counts = one + two + three;
//		cout << counts << endl;
//	}
//	return 0;
//}


//�ַ���ͨ���
int match_string(string m_str, string w_str) //match wildcard ͨ���
{
	int m_len = m_str.size();
	int w_len = w_str.size();
	vector<vector<int> > b_dp(w_len + 1, vector<int>(m_len + 1, 0));
	//���һ��һ����Ϊ��ʼ��ֵ����
	b_dp[0][0] = 1;
	for (int i = 1; i <= w_len; i++)
	{
		char ch = w_str[i - 1];
		////����ÿ��ѭ���ĳ�ֵ�������ǺŲ���������λʱ��ƥ���ַ����ĳ�ֵ��Ϊfalse
		b_dp[i][0] = b_dp[i - 1][0] && (ch == '*');
		for (int j = 1; j <= m_len; j++)
		{
			char ch2 = m_str[j - 1];
			if (ch == '*')
				b_dp[i][j] = b_dp[i - 1][j] || b_dp[i][j - 1]; //��ƥ���ַ�Ϊ*��ʱ��״̬ȡ��������״̬�����״̬��ֵ
			else
				b_dp[i][j] = b_dp[i - 1][j - 1] && (ch == '?' || ch2 == ch);
		}
	}
	return b_dp[w_len][m_len];



}

int main()
{
	string str1, str2;
	while (cin >> str1 >> str2)
	{
		int rst = match_string(str2, str1);
		if (rst == 1)
			cout << "true" << endl;
		else
			cout << "false" << endl;
	}

}