#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

//T��������������
//template<class T>
//ͨ�����õĵط�ȷ��T�����ͣ����ɶ�Ӧ�Ĵ��룬������̽���ģ���ʵ����
//template<typename T>
//void Swap(T& x1, T& x2)
//{
//	T x = x1;
//	x1 = x2;
//	x2 = x;
//}

//���ͱ��-> ���Խ����ҪЩ���swap����������

namespace bit
{
	template <class T>
	void Swap(T& x1, T& x2)
	{
		T x = x1;
		x1 = x2;
		x2 = x;
	}

}



int main()
{
	int a = 1, b = 2;
	bit::Swap(a, b);
	swap(a, b); //C++��������swap����

	double c = 1.1, d = 2.2;
	bit::Swap(c, d);
	

	return 0;
}

