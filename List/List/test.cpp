#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<list>
using namespace std;


//vector 动态增长数组  
//缺陷：1、头插头删和中间插入删除需要挪动数据，效率低下O(N),也就是说只适合尾插
//		2、空间不够需要增容，增容是要付出代价的，有不小的性能消耗

//list 带头双循环的链表，可以针对性解决vector的缺陷，也就是说vector和list是两个互补形式存在的



void test_list1()
{
	list<int> l1;
	l1.push_back(1);
	l1.push_back(2);
	l1.push_back(3);
	l1.push_back(4);
	
	list<int>copy(l1);
	list<int> l2;
	l2 = l1;

	//迭代器
	list<int>::iterator it1 = l1.begin();
	while (it1 != l1.end())
	{
		cout << *it1 << " ";
		++it1;

	}
	cout << endl;




}

void test_list2()
{
	list<int> l1;
	l1.push_back(1);
	l1.push_back(2);
	l1.push_back(3);
	l1.push_back(4);

	l1.pop_back();

	

	list<int>::iterator it1 = l1.begin();
	for (auto e : l1)
	{
		cout << e << " ";
	}
	cout << endl;
}

int main()
{

	test_list1();
	test_list2();


	return 0;
}