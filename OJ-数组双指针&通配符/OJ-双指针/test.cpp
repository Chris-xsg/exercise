#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;

//����209-������С�������� --˫ָ��
int minSubArrayLen(int s, vector<int>& nums)
{
	if (nums.empty())
	{//Ϊ�շ���0
		return 0;
	}

	int ret = INT_MAX;//����ֵ����ʼ��Ϊ�������
	int start = 0, end = 0;//˫ָ��
	int sum = 0;
	while (end < nums.size())
	{
		sum += nums[end];//sum<sʱ��end��start֮��ļӸ�sum
		while (sum >= s)
		{//sum>=s֮������start��end�ĳ�����ret�Ƚϣ�ȡС�ĸ�ret
			ret = min(ret, end - start +1);
			sum -= nums[start];//��start��sum�м���
			start++;//start������
		}
		end++;
	}
	return ret == INT_MAX ? 0 : ret;
}

//ţ��OR174-ʵ����ͨ���
int Core(string &str1, string &str2, int left, int right, int start, int len)
{
	int res = false;
	if (str1[left] == '\0')
	{
		cout << start << " " << len << endl;
		return true;
	}
	if (str1[left] != '\0' && str2[right] == '\0') return false;
	//��ͨ���ַ�����*ʱ���ж��������ַ��Ƿ����
	if (str1[left] != '*')
	{
		if (str1[left] != str2[right]) return false;
		else
		{
			res = Core(str1, str2, left + 1, right + 1, start, len + 1);
		}
	}
	//��ͨ���ַ���*ʱ��ͨ���ַ�����ƶ����߲����ַ�����ƶ�
	else
	{
		//����Ҫע�ⲻ����||��Ϊһ����һ�����������ڶ����������ᱻִ��
		bool tem1 = Core(str1, str2, left + 1, right, start, len);
		bool tem2 = Core(str1, str2, left, right + 1, start, len + 1);
		res = tem1 || tem2;

	}
	return res;
}
int main()
{

	string str1;
	string str2;
	cin >> str1 >> str2;
	if (str1 == "*")
	{
		for (int i = 0; i < str2.size(); i++)
		{
			for (int j = 1; j + i <= str2.size(); j++)
			{
				cout << i << " " << j << endl;
			}
		}
		return 0;
	}
	bool res = false;
	for (int i = 0; i < str2.size(); i++)
	{
		if (Core(str1, str2, 0, i, i, 0)) res = true;
	}
	if (!res) cout << -1 << " " << 0 << endl;
	return 0;
}