#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;


//���üӼ��˳����ӷ�--λ����
int Add(int num1, int num2)
{
	int sum, flag;
	while (num2 != 0)
	{
		sum = num1^num2;//������δ��λ�ĺ�
		flag = (num1&num2) << 1;//��λ����ý�λ
		num1 = sum;
		num2 = flag;
	}
	return num1;
}


//������--���������ߣ��ж��ܷ����һ��������
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