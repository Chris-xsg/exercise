#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;


//int main()
//{
//	//1个int
//	int* p1 = (int*)malloc(sizeof(int)); //c
//	int* p2 = new int;                   //c++
//	free(p1);
//	p1 = nullptr;
//	p2 = nullptr;
//	delete p2;
//
//	//10个int的数组
//	int* p3 = (int*)malloc(sizeof(int)* 10);
//	int* p4 = new int[10];
//	free(p3);
//	delete[] p4;
//
//	//申请一个int对象，并且初始化成10
//	int* p5 = new int(10);
//	delete p5;
//
//	return 0;
//}

//new/delete 和malloc/free最大的区别是new/delete对于【自定义类型】除了开空间还会调用构造函数和析构函数
//内置类型是一样的

//class A
//{
//public:
//	/*struct ListNode
//	{
//		ListNode* _next;
//		ListNode* _prev;
//		int _val;
//	};*/
//
//	ListNode(int val)
//		:_next(nullptr)
//		: _prev(nullptr)
//		: _val(val)
//
//
//};
//struct ListNode
//{
//	ListNode* _next;
//	ListNode* _prev;
//	int _val;
//};
//
//
//
//ListNode* BuyListNode(int val)
//{
//
//}
//
//int main()
//{
//	ListNode* cur_cpp = new ListNode(1);
//
//	return 0;
//}


//new和delete的底层如何实现
//int main()
//{
	//1.operator new 和malloc都可以开空间，用法也类似
	//2.区别是失败了以后，malloc返回nullptr，operator new抛异常
	//3.本质operator new底层是封装malloc实现了，只是处理了失败以后抛异常
	//new失败了也是抛异常 -》 面向对象的语言失败了基本上都使用抛异常的方式处理
	//new如何实现  operator new + 构造函数
	//delete如何实现 析构函数 + operator delete	


	//return 0;
//}


int main()
{
	void* p1 = malloc(1024 * 1024 * 1024 * 1);
	void* p2 = malloc(1024 * 1024 * 1024 * 2);
	void* p4 = malloc(1024 * 1024 * 1024 * 4);

	return 0;
}









