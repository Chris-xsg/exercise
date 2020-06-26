#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;

//΢�ź�����������г��ִ������������Сһ�����
int getValue(vector<int> gifts, int n) 
{
	if (n == 0)
		return 0;
	sort(gifts.begin(), gifts.end());
	int counts = 0;
	int temp = gifts[n / 2];
	for (int i = 0; i<n; i++)
	{
		if (gifts[i] == temp)
		{
			counts++;
		}
	}
	if (counts > n / 2)
	{
		return temp;
	}
	return 0;
}

//�����ַ����ľ��룺Levenshtein����-�༭����
int main()
{
	string s1, s2;
	while (cin >> s1 >> s2){
		int len1 = s1.size();
		int len2 = s2.size();
		vector<vector<int>>dp(len1 + 1, vector<int>(len2 + 1, 0));
		for (int i = 1; i <= len1; i++){
			dp[i][0] = i;
		}
		for (int j = 1; j <= len2; j++){
			dp[0][j] = j;
		}
		dp[0][0] = 0;
		for (int i = 1; i <= len1; i++){
			for (int j = 1; j <= len2; j++){
				if (s1[i - 1] == s2[j - 1])
					dp[i][j] = dp[i - 1][j - 1];
				else{
					int tem = min(dp[i - 1][j], dp[i][j - 1]);
					dp[i][j] = min(dp[i - 1][j - 1], tem) + 1;
				}
			}
		}
		cout << dp[len1][len2] << endl;
	}
	return 0;
}


int main()
{


	return 0;
}
