#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#define PI 3.14


//��̬��̨�� -- ������1����2�� ..... n��
int jumpFloorII(int number)
{
	if (number <= 0)
		return -1;
	else if (number == 1)//1��ʱֻ��1������
		return 1;
	else//f(n) = 2*f(n-1)
		return 2 * jumpFloorII(number - 1);
}





//�쵽������
//int main()
//{
//	double n, r;
//	while (cin >> n >> r)
//	{
//		if (n > r * 2 * PI)
//		{
//			cout << "NO" << endl;
//		}
//		else
//			cout << "Yes" << endl;
//	}
//	return 0;
//}


