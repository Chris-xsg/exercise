#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<string>

using namespace std;


//计算糖果
void Cls_Candynum()
{
	int a, b, c, d;
	int A, B, C;
	while (cin >> a >> b >> c >> d)
	{
		A = (a + c) / 2;
		B = (b + d) / 2;
		C = (d - b) / 2;
		if (A - B == a && B - C == b && A + B == c && B + C == d)
		{
			cout << A << " " << B << " " << C << endl;
		}
		else
		{
			cout << "No" << endl;
		}
	}

}


//进制转换
void  FUN(){
	string s = "", table = "0123456789ABCDEF";
	int m, n;
	cin >> m >> n;
	while (m){
		if (m<0){
			m = -m;
			cout << "-";
		}
		s = table[m%n] + s;
		m /= n;
	}
	cout << s << endl;
	
}



int main()
{
	Cls_Candynum();
	FUN();
	return 0;
}