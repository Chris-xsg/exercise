#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
using namespace std;


//�������ڣ���������һ��ĵڼ���
//int GetMonthDays(int year, int month)//��ȡÿ���µ�day
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
//int GetOutDay(int year,int month,int day)//��ȡ����
//{
//	int outdays = 0;
//	int isday = GetMonthDays(year, month);//��������month�������������ж�day�Ƿ�Ϸ�
//	if (month <= 0 || month > 12)//�ж�month�Ƿ�Ϸ�
//	{
//		return -1;
//	}
//	else if (day > isday)//�ж�day�Ƿ�Ϸ�
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



//���˵Ĵ���
int n;
int nums[1000];

int cmp(const void * a, const void * b) {
	return *(int*)a - *(int*)b;
}

// DFS����ȫ��ϣ�ͬʱע���֦�������ظ����
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
		// ������ȵ�Ԫ�أ������ظ����
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

		// ��С��������
		qsort(nums, n, sizeof(int), cmp);
		cout << findall(nums, 0, 0, 1) << endl;
	}

	return 0;
}