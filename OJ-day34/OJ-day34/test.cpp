#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
#include<vector>
using namespace std;

//收件人列表
int main()
{
	int n;
	while (cin >> n)
	{
		getchar(); //刷新缓冲区
		while (n--)
		{
			string str;
			getline(cin, str);
			if (str.find(',') != -1 || str.find(' ') != -1)
			{
				str.insert(str.begin(), '"');
				str.insert(str.end(), '"');
			}
			if (n == 0)
				cout << str << endl;
			else
				cout << str << ", ";
		}
	}
	return 0;
}


//养兔子---》斐波那契数列

int main()
{
	int n = 0;
	long arr[91] = { 1, 1 };
	for (int i = 2; i<91; i++)
		arr[i] = arr[i - 1] + arr[i - 2];
	while (cin >> n)
	{
		cout << arr[n] << endl;
	}
	return 0;
}
