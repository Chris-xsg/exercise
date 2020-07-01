#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;


//不用加减乘除做加法--位运算
int Add(int num1, int num2)
{
	int sum, flag;
	while (num2 != 0)
	{
		sum = num1^num2;//异或求得未进位的和
		flag = (num1&num2) << 1;//按位与求得进位
		num1 = sum;
		num2 = flag;
	}
	return num1;
}


//三角形--给定三条边，判断能否组成一个三角形
void Is_Triangle()
{
	double a, b, c;
	while (cin >> a >> b >> c)
	{
		if (a + b > c && a + c > b && b + c > a)
		{
			cout << "Yes" << endl;
		}
		else
			cout << "No" << endl;
	}
}



int main()
{
	/*int n, m;
	cin >> n >> m;
	cout << Add(n, m) << endl;*/

	Is_Triangle();

	return 0;
}