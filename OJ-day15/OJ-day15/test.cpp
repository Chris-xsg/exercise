#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


//求输入整数二进制中1的个数
void Find_Numberof1()
{
	int num;
	while (cin >> num)
	{
		int count = 0;
		while (num > 0)
		{
			if (num & 1)
			{
				count++;
			}
			num >>= 1;
		}
		cout << count << endl;

	}

}


//手套
class Gloves {
public:
	int findMinimum(int n, vector<int> left, vector<int> right) {
		// write code here
		int left_sum = 0, left_min = INT_MAX;
		int right_sum = 0, right_min = INT_MAX;
		int sum = 0;
		for (int i = 0; i < n; i++)
		{
			// 左边或者右边没有的时候需要全部拿走(最差结果)
			if (left[i] * right[i] == 0)
			{
				sum += left[i] + right[i];
			}
			// 找到左边和右边分别最少的颜色的数量并计算总和
			else{
				left_sum += left[i];
				right_sum += right[i];
				left_min = min(left[i], left_min);
				right_min = min(right[i], right_min);
			}
		}
		// 找到左边和右边中较小的值，在另一边直接拿一个就可以
		return sum + min(left_sum - left_min + 1, right_sum - right_min + 1) + 1;
	}
};

int main()
{

	Find_Numberof1();

	return 0;
}