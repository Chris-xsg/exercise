#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
using namespace std;


//输入日期，计算是这一年的第几天
//int GetMonthDays(int year, int month)//获取每个月的day
//{
//	static int monthDays[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
//	int days = monthDays[month];
//	if (month == 2 && (year % 4 == 0 && year % 100 != 0 || year % 400 == 0))
//	{
//		days = 29;
//	}
//	return days;
//}
//
//int GetOutDay(int year,int month,int day)//获取天数
//{
//	int outdays = 0;
//	int isday = GetMonthDays(year, month);//存下输入month的天数，用来判断day是否合法
//	if (month <= 0 || month > 12)//判断month是否合法
//	{
//		return -1;
//	}
//	else if (day > isday)//判断day是否合法
//	{
//		return -1;
//	}
//	else
//	{
//		for (int i = 1; i < month; i++)
//		{
//			outdays += GetMonthDays(year, i);
//		}
//		return outdays + day;
//	}
//	return -1;
//
//}
//
//int main()
//{
//	int year, month, day;
//	while (cin >> year >> month >> day)
//	{
//		int ret = GetOutDay(year, month, day);
//		cout << ret << endl;
//	}
//	
//
//
//	return 0;
//}



//幸运的袋子
int n;
int nums[1000];

int cmp(const void * a, const void * b) {
	return *(int*)a - *(int*)b;
}

// DFS生成全组合，同时注意剪枝、避免重复组合
int findall(int nums[], int index, long sum, long multi) {
	int count = 0;
	for (int i = index; i<n; i++) {
		sum += nums[i];
		multi *= nums[i];
		if (sum > multi)
			count += 1 + findall(nums, i + 1, sum, multi);
		else if (nums[i] == 1)
			count += findall(nums, i + 1, sum, multi);
		else
			break;
		sum -= nums[i];
		multi /= nums[i];
		// 跳过相等的元素，避免重复组合
		while (i<n - 1 && nums[i] == nums[i + 1])
			i++;
	}
	return count;
}

int main(int argc, char* argv[])
{
	while (cin >> n) {
		for (int i = 0; i<n; i++)
			cin >> nums[i];

		// 从小到大排序
		qsort(nums, n, sizeof(int), cmp);
		cout << findall(nums, 0, 0, 1) << endl;
	}

	return 0;
}