#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;

//找出字符串中连续最长的数字串
void Find_LongNumstr()
{
	string str,tmp,Max;
	cin >> str;

	for (int i = 0; i < str.size(); i++)
	{
		if (isdigit(str[i]))
		{
			tmp += str[i];
		}
		if (!isdigit(str[i + 1]))
		{
			if (tmp.size() > Max.size())
			{
				Max = tmp;
				
			}
			tmp = "";
		}
	}
	cout << Max << endl;


}


//数组中出现次数超过一半的数字
class Solution {
public:
	
	int MoreThanHalfNum_Solution()
	{
		vector<int> numbers;
		if (numbers.empty()) return 0;

		sort(numbers.begin(), numbers.end()); // 排序，取数组中间那个数
		int middle = numbers[numbers.size() / 2];//只要有那个数，肯定在中间为middle

		int count = 0; // 出现次数
		for (int i = 0; i<numbers.size(); ++i)
		{
			if (numbers[i] == middle) ++count;
		}

		return (count>numbers.size() / 2) ? middle : 0;
	}
};


int main()
{
	//Find_LongNumstr();

	return 0;
}

