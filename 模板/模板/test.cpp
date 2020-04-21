#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

//T可以是任意类型
//template<class T>
//通过调用的地方确定T的类型，生成对应的代码，这个过程叫做模板的实例化
//template<typename T>
//void Swap(T& x1, T& x2)
//{
//	T x = x1;
//	x1 = x2;
//	x2 = x;
//}

//泛型编程-> 可以解决需要些多个swap函数的问题

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
	swap(a, b); //C++库里面有swap函数

	double c = 1.1, d = 2.2;
	bit::Swap(c, d);
	

	return 0;
}

