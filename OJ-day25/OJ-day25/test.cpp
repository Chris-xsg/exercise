#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<string>
using namespace std;

//星际密码 -- 斐波那契数列
int Fun()
{
	vector<int> v = { 1, 1 };
	for (int i = 2; i < 10001; ++i){
		v.push_back((v[i - 2] + v[i - 1]) % 10000);
	}
	int n, x;
	while (cin >> n){
		for (int i = 0; i < n; ++i){
			cin >> x;
			printf("%04d", v[x]);
		}
		printf("\n");
	}
	return 0;
}


//数根
int NumRoot(long long n)
{
	vector<long long >temp;
	temp.resize(0);
	int tmp = 0;
	if (n > 0 && n <= 9)
	{
		return n;
	}
	while (n > 9)
	{
		tmp = n % 10;
		n = n / 10;
		temp.push_back(tmp);
		if (n > 0 && n <= 9)
		{
			temp.push_back(n);
		}
	}
	long long add = 0;
	for (auto e : temp)
	{
		add += e;
	}
	n = add;
	return NumRoot(n);
}

//int main()
//{
//	long long n = 0;
//	while (cin >> n)
//	{
//		cout << NumRoot(n) << endl;
//	}
//	return 0;
//}

int main()
{
	string str;
	while (getline(cin,str))
	{
		int num = 0;
		//先将每一位进行相加得到总和，防止数字过大
		for (int i = 0; i < str.size(); ++i){
			num += str[i] - '0';
		}
		int sum = 0;
		while (num){
			sum += num % 10;
			num /= 10;
			if (num == 0 && sum / 10 != 0){
				num = sum;
				sum = 0;
			}
		}
		cout << sum << endl;
	}
	return 0;
}
