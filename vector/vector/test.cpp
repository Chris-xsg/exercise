#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
using namespace std;

//void test_vector()
//{
//	vector<int>v1;
//
//
//}
//
//int main()
//{
//	vector<int> v = { 10, 20, 30, 40 };
//	v[0];
//
//	vector<vector<int>> vv;
//	vv.resize(10);
//	for (size_t i = 0; i < 10; ++i)
//	{
//		vv[i].resize(5);
//	}
//	
//
//	return 0;
//}

//容器、迭代器、算法
//1、容器：存储管理数据的数据结构
//2、迭代器：像指针一样使用，访问和修改容器的数据，配合算法使用
//3、算法：通常是实现某个逻辑的函数，这个处理的是一些存在容器中的数据，
//所以算法是通过迭代器处理这些容器中的数据的。


//迭代器失效
int main()
{
	//vector<int> v = { 1, 2, 3, 4 };
	//vector<int>::iterator it = v.begin();
	////v.reserve(5);//迭代器失效，reserve导致it失效了
	////解决办法：先reserve再用it
	////会影响v的底层储存数据空间接口都会导致迭代器失效 + 或者像erase这样，it指向的位置值被删除
	////reserve、resize、insert/push_back/erase
	//while (it != v.end())
	//{
	//	cout << *it << " ";
	//	++it;
	//}
	//cout << endl;


	//删除容器中的偶数
	vector<int> v = { 1, 2, 3, 4, 5, 6, 7 };
	vector<int>::iterator it = v.begin();
	
	while (it != v.end())
	{
		if (*it % 2 == 0)
		{
			//v.erase(it);//vs删除it后，it失效了，这里PJ STL检查报错；SGI版本没进行检查，不会报错
			it = v.erase(it);//解决方法
		}
		else
		{
			++it;
		}
		
	}

	for (auto e : v)
	{
		cout << e << " ";
	}
	cout << endl;


	return 0;
}