#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<string>
using namespace std;



//iNOC产品部-杨辉三角形变形
int Yanghui(int n)
{
	int m = 2 * n - 1;
	if (n == 0)
		return -1;
	vector<vector<int> >arr(n, vector<int>(m, 0));
	arr[0][1] = 1;
	for (int i = 1; i < n; i++)
	{
		for (int j = 1; j < m; j++)
		{
			if (j == 1)
			{
				arr[i][j] = arr[i - 1][j] + arr[i - 1][j - 1];
			}
			else
				arr[i][j] = arr[i - 1][j] + arr[i - 1][j - 1] + arr[i - 1][j - 2];
		}
	}
	for (int i = 1; i < m; i++)
	{
		if (arr[n - 1][i] % 2 == 0)
			return i;
	}
	return -1;

}


//超长正整数相加
void Add_intnum()
{
	string a, b;
	while (cin >> a >> b)
	{
		int temp = 0, carry = 0;
		while (a.size()<b.size())
			a = "0" + a;
		while (a.size()>b.size())
			b = "0" + b;
		for (int i = a.size() - 1; i >= 0; i--)
		{

			temp = a[i] - '0' + b[i] - '0' + carry;
			a[i] = temp % 10 + '0';
			if (temp / 10)
				carry = 1;
			else
				carry = 0;
		}
		if (carry)
			a = "1" + a;
		cout << a << endl;
	}

}



int main()
{
	/*int n;
	while (cin >> n)
	{
		cout << Yanghui(n) << endl;
	}*/
	Add_intnum();

	return 0;
}