#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<sstream>
using namespace std;

int Is_Palindrome(string& str)//判断是否回文
{
	string str1;
	str1 = str;
	std::reverse(str.begin(), str.end());
	if (str1 == str)
	{
		return true;
	}
	return false;

}

void Find_times()//计算方法的次数
{
	string str1;
	string str2;
	
	getline(cin,str1);
	getline(cin, str2);
	string tmp = str1;
	string tmp2 = str2;
	int count = 0;

	//str2插入在str1前面的情况
	str2 += str1;
	int ret = Is_Palindrome(str2);
	if (ret)
	{
		count++;
		
	}
	str2 = tmp2;

	
	//其它的所有情况
		for (int i = 0; i < str1.size(); i++)
		{
			str1.insert(i, str2);
			int ret = Is_Palindrome(str1);
			if (ret)
			{
				count++;
			}
			str1 = tmp;
		}
	

	cout << count << endl;

	

}


void Find_Maxadd()
{
	vector<int> arr;
	string str;
	int n;
	int ret = 0;
	cin >> n;

	getline(cin, str);
	
	stringstream ss(str);
	for (int i = 0; i < str.size(); i++)
	{
		ss >> arr[i];
	}
	for (int j = 0; j < arr.size(); j++)
	{
		if (arr[j] > 0)
		{
			ret += arr[j];
		}
	}
	cout << ret;

}

void test()
{


	int n, curSum = 0, maxSum = -1e5;
	cin >> n;
	int arr[n];
	for (int i = 0; i<n; i++){
		cin >> arr[i];
		curSum += arr[i];
		if (curSum>maxSum){
			maxSum = curSum;
		}
		if (curSum<0){
			curSum = 0;
		}
	}
	cout << maxSum << endl;
}



int main()
{
	//Find_times();
	Find_Maxadd();
	return 0;
}