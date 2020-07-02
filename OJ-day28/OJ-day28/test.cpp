#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<cmath>
#include<vector>
using namespace std;


/**
*  ����λ�϶�����������ż��λ�϶���ż��
*  ���룺����arr�����ȴ���2
*  len��arr�ĳ���
*  ��arr����������λ�϶�����������ż��λ�϶���ż��
*/
void oddInOddEvenInEven(vector<int>& arr, int len) 
{
	int Odd = 1;//����ָ���1��ʼ��ÿ��ָֻ�������±�
	int Even = 0;//ż��ָ���0��ʼ��ÿ��ָֻ��ż���±�

	while (Odd < len && Even < len)
	{
		if (arr[Odd] % 2 != 0 && arr[Even] % 2 == 0)
		{//����λ�÷���������ż��λ�÷���ż������������ֱ�������
			Odd += 2;
			Even += 2;
		}
		else if (arr[Odd] % 2 == 0 && arr[Even] % 2 != 0)
		{//����λ�÷���ż��������ż��λ��Ҳ����������ֱ�ӽ��н�����Ȼ���������
			swap(arr[Odd], arr[Even]);
			Odd += 2;
			Even += 2;
		}
		else if (arr[Odd] % 2 == 0)
		{//��żλ�ö�����ż������ôEven�����
			Even += 2;
		}
		else
		{//��żλ�ö�������������ôOdd�����
			Odd += 2;
		}
	}

}

void oddInOddEvenInEven(vector<int>& arr, int len) {
	int Even = 0, Odd = 1;
	while (Even<len&&Odd<len)
	{
		if (arr[len - 1] % 2 == 0)
		{//Ϊż���ͽ�����ż��λ������ż��λ�����
			swap(arr[len - 1], arr[Even]);
			Even += 2;
		}
		else
		{//������������λ����������λ�����
			swap(arr[len - 1], arr[Odd]);
			Odd += 2;
		}
	}
}


//���ӷ���
int main()

{
	int n;
	long long a, b;
	while (cin >> n)
	{
		if (n == 0)
			break;
		else
		{
			a = pow(5, n) - 4;
			b = pow(4, n) + n - 4;
			cout << a << " " << b << endl;
		}
	}
	return 0;

}