#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;

//力扣209-长度最小的子数组 --双指针
int minSubArrayLen(int s, vector<int>& nums)
{
	if (nums.empty())
	{//为空返回0
		return 0;
	}

	int ret = INT_MAX;//返回值，初始化为整形最大
	int start = 0, end = 0;//双指针
	int sum = 0;
	while (end < nums.size())
	{
		sum += nums[end];//sum<s时将end到start之间的加给sum
		while (sum >= s)
		{//sum>=s之后计算出start到end的长度与ret比较，取小的给ret
			ret = min(ret, end - start +1);
			sum -= nums[start];//吧start从sum中减掉
			start++;//start向右移
		}
		end++;
	}
	return ret == INT_MAX ? 0 : ret;
}

//牛客OR174-实现字通配符
int Core(string &str1, string &str2, int left, int right, int start, int len)
{
	int res = false;
	if (str1[left] == '\0')
	{
		cout << start << " " << len << endl;
		return true;
	}
	if (str1[left] != '\0' && str2[right] == '\0') return false;
	//当通配字符不是*时候，判断两个个字符是否相等
	if (str1[left] != '*')
	{
		if (str1[left] != str2[right]) return false;
		else
		{
			res = Core(str1, str2, left + 1, right + 1, start, len + 1);
		}
	}
	//当通配字符是*时候，通配字符向后移动或者查找字符向后移动
	else
	{
		//这里要注意不能用||因为一旦第一个条件成立第二个条件不会被执行
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