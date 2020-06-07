#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<string>
using namespace std;


//排序子序列
//int main()
//{
//	int n;
//	cin >> n;
//	vector<int> array;
//	array.resize(n);
//	//读入数组
//	int i = 0;
//	for (i = 0; i<n; ++i)
//		cin >> array[i];
//	i = 0;
//	int k = 0;
//	int count = 0;
//	while (i<n)
//	{
//		if (array[i]<array[i + 1])
//		{
//			while (array[i] <= array[i + 1])
//			{
//				i++;
//			}
//			k++;
//			i++;
//		}
//		else if (array[i] == array[i + 1])
//			i++;
//		else
//		{
//			while (array[i] >= array[i + 1])
//			{
//				i++;
//			}
//			k++;
//			i++;
//		}
//	}
//	cout << k;
//	return 0;
//
//}


int main()
{
	string str;
	getline(cin, str);
	string tmp, res;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == ' ') {
			res = ' ' + tmp + res;
			tmp = "";
		}
		else {
			tmp += str[i];
		}

	}
	if (tmp.size()) {
		res = tmp + res;
	}
	cout << res << endl;
	return 0;

}