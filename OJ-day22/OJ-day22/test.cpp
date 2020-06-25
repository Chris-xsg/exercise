#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<string>
using namespace std;

//升级		
int Max_ComDiv(int a, int b)//求最大公约数
{
	int temp;
	if (a < b)
		swap(a, b);
	if (a % b == 0)
	{
		return b;
	}
	else
	{
		temp = a % b;
		a = b;
		b = temp;
		return Max_ComDiv(a, b);
	}
	

}
void Level()//升级
{
	int n, a;
	while (cin >> n >> a)
	{
		vector<int > arr(n, 0);

		for (int i = 0; i < n; i++)
		{
			cin >> arr[i];
		}

		for (int i = 0; i < n; i++)
		{
			if (a < arr[i])
			{
				a += Max_ComDiv(a, arr[i]);
			}
			else
			{
				a += arr[i];
			}
		}
		cout << a << endl;
	}

}


//找出字符串中第一次只出现一次的字符
string Find_TheFirstChar(string str)
{
	
	string temp = "",ret;
	for (int i = 0; i < str.size(); i++)
	{
		int counts = 0;
		if (temp.find(str[i]) == string::npos)
		{
			for (int j = i + 1; j < str.size(); j++)
			{
				if (str[i] == str[j])
				{
					counts++;
					temp += str[i];
				}
			}
			if (counts == 0)
			{
				ret = str[i];
				return ret;
			}
		}
		
	}
	ret = "-1";
	return ret;
	

}

//int main() //映射
//{
//	string str;
//	while (cin >> str)
//	{
//		int CountArray[26] = { 0 };
//		int count = 1;
//		for (int i = 0; i < str.size(); i++)
//		{
//			CountArray[str[i] - 'a']++;
//		}
//		for (int i = 0; i < str.size(); i++)
//		{
//			if (CountArray[str[i] - 'a'] == 1)
//			{
//				cout << str[i] << endl;
//				count = 0;
//				break;
//			}
//
//		}
//		if (count)
//		{
//			cout << -1 << endl;
//		}
//	}
//	return 0;
//
//}


int main()
{
	//Level();
	string str;
	while (getline(cin, str))
	{
		cout << Find_TheFirstChar(str) << endl;

	}

	return 0;
}