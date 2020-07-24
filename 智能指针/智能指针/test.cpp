#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

#include"SmartPtr.h"

int div()
{
	int a, b;
	cin >> a >> b;
	if (b == 0)
		throw invalid_argument("除0错误");

	return a / b;
}

void f1()
{
	/*int* p1 = new int;
	int* p2 = new int;
	int* p3 = new int*/;

/*int* p = new int;
try
{
cout << div() << endl;
}
catch (...)
{
delete p;
throw;
}
delete p;*/

SmartPtr<int> sp1(new int);
*sp1 = 10;

SmartPtr<pair<int, int>> sp2(new pair<int, int>);
sp2->first = 20;
sp2->second = 30;

cout << div() << endl;
}

//int main()
//{
//	try
//	{
//		f1();
//	}
//	catch (exception& e)
//	{
//		cout << e.what() << endl;
//	}
//
//	return 0;
//}

// 智能指针的坑
int x1()
{
	int* p1 = new int;
	int* p2 = p1;

	//bit::auto_ptr<int> ap1(new int);
	//bit::auto_ptr<int> ap2 = ap1;
	// *ap1 = 1; 悬空崩溃

	//bit::unique_ptr<int> up1(new int);
	//bit::unique_ptr<int> up2(up1);

	bit::shared_ptr<int> sp1(new int);
	bit::shared_ptr<int> sp2(sp1);

	bit::shared_ptr<int> sp3(new int);
	bit::shared_ptr<int> sp4(sp3);
	bit::shared_ptr<int> sp5(sp3);

	sp1 = sp4;


	return 0;
}

// shared_ptr的拷贝赋值时线程安全问题
// shared_ptr是否是线程安全的，答：注意这里问题的shared_ptr对象拷贝和析构++/--引用计数是否是安全的，库的实现中是安全的。
#include<thread>

int x2()
{
	bit::shared_ptr<int> sp(new int);
	cout << sp.use_count() << endl;
	int n = 10000;

	std::thread t1([&](){
		for (int i = 0; i < n; ++i)
		{
			bit::shared_ptr<int> sp1(sp);
		}
	});

	std::thread t2([&](){
		for (int i = 0; i < n; ++i)
		{
			bit::shared_ptr<int> sp2(sp);
		}
	});

	t1.join();
	t2.join();

	cout << sp.use_count() << endl;

	return 0;
}

struct ListNode
{
	int val;
	//ListNode* _next;
	//ListNode* _prev;
	//bit::shared_ptr<ListNode> _spnext;
	//bit::shared_ptr<ListNode> _spprev;

	bit::weak_ptr<ListNode> _spnext;
	bit::weak_ptr<ListNode> _spprev;

	~ListNode()
	{
		cout << "~ListNode()" << endl;
	}
};

int x3()
{
	/*ListNode* n1 = new ListNode;
	ListNode* n2 = new ListNode;

	n1->_next = n2;
	n2->_prev = n1;

	delete n1;
	delete n2;*/

	bit::shared_ptr<ListNode> spn1(new ListNode);
	bit::shared_ptr<ListNode> spn2(new ListNode);

	cout << spn1.use_count() << endl;
	cout << spn2.use_count() << endl;

	// 循环引用
	spn1->_spnext = spn2; // 解决方式：使用weak_ptr，不增加引用计数
	spn2->_spprev = spn1;

	cout << spn1.use_count() << endl;
	cout << spn2.use_count() << endl;

	return 0;
}

// 定制删除器 -- （了解）
#include<memory>
class A
{
public:
	~A()
	{
		cout << "~A()" << endl;
	}
private:
	int _a1;
	int _a2;
};

template<class T>
struct DeleteArry
{
	void operator()(T* pa)
	{
		delete[] pa;
	}
};

struct Free
{
	void operator()(void* p)
	{
		cout << "free(p)" << endl;

		free(p);
	}
};

struct Fclose
{
	void operator()(FILE* p)
	{

		cout << "fclose(p)" << endl;

		fclose(p);
	}
};

int x4()
{
	std::shared_ptr<A> sp1(new A);
	std::shared_ptr<A> sp2(new A[10], DeleteArry<A>());
	std::shared_ptr<A> sp3((A*)malloc(sizeof(A)), Free());
	std::shared_ptr<FILE> sp4(fopen("test.txt", "w"), Fclose());

	return 0;
}

// 智能指针是RAII思想的一种应用的体现
// 本质RAII就是借助构造函数和析构函数来搞事情，因为构造函数和析构函数的特点都是自动调用
#include<mutex>

// 使用RAII思想设计的锁管理守卫
template<class Lock>
class LockGuard
{
public:
	LockGuard(Lock& lock)
		:_lk(lock)
	{
		_lk.lock();
	}

	~LockGuard()
	{
		cout << "解锁" << endl;
		_lk.unlock();
	}

	LockGuard(LockGuard<Lock>&) = delete;
	LockGuard<Lock>& operator=(LockGuard<Lock>&) = delete;
private:
	Lock& _lk;  // 注意这里是引用
};


//void f()
//{
//	mutex mtx;
//	mtx.lock();
//
//	// func()   // 假设func函数有可能抛异常
//
//	mtx.unlock();
//}

void f()
{
	mutex mtx;
	LockGuard<mutex> lg(mtx);

	cout << div() << endl;   // 假设div函数有可能抛异常
}

int x5()
{
	//try
	//{
	//	f();
	//}
	//catch (exception& e)
	//{
	//	cout << e.what() << endl;
	//}
	char* p = new char[1024 * 1024 * 1024];


	return 0;
}

// 创建出的类对象只能在堆上
// 思路：正常创建对象一定要调用构造函数，或者拷贝构造
class HeapOnly
{
public:
	static HeapOnly* GetObj()
	{
		return new HeapOnly;
	}

private:
	HeapOnly()
	{}

	// C++98防拷贝：声明成私有
	//HeapOnly(const HeapOnly& );
public:
	// C++11 : 声明成delete
	HeapOnly(const HeapOnly&) = delete;
};

int x7()
{
	//HeapOnly hp;
	//HeapOnly* p = new HeapOnly;
	//HeapOnly* p = HeapOnly::GetObj();
	std::shared_ptr<HeapOnly> sp1(HeapOnly::GetObj());
	std::shared_ptr<HeapOnly> sp2(HeapOnly::GetObj());

	//HeapOnly copy(*sp1);


	return 0;
}

//class StackOnly
//{
//public:
//	static StackOnly GetObj()
//	{
//		return StackOnly();
//	}
//private:
//	StackOnly()
//	{}
//};

// 这种方案存在一定程序缺陷，无法阻止在数据段(静态区)创建对象
class StackOnly
{
public:
	void* operator new(size_t size) = delete;
};

int x8()
{
	StackOnly so;
	//StackOnly* p = new StackOnly;

	static StackOnly sso;


	return 0;
}

// 之前已经学过一些设计模式
// 迭代器模式 -- 基于面向对象三大特性之一的 封装设计出来的，用一个迭代器类封装以后，不暴露容器的结构的情况下，统一的方式访问修改容器中的数据。

// 适配器模式 -- 体现的是一种复用
// 还有一些常见的设计模式如：工厂模式、装饰器模式、观察者模式、单例模式...
// 一个类只能在全局(进程中)只有一个实例对象。
// 什么场景下使用？比如一个进程中有一个内存池，进程中的多线程需要内存都要到这个内存池中取，那么这个内存池的类就可以设计单例模式。

// 类的名称是随着你的场景给的，比如你的是内存池，那么你就定义成MemoryPool
#include<thread>
#include<vector>
#include<windows.h>

class Singleton
{
public:
	static Singleton* GetInstance()
	{
		::Sleep(1000);
		if (_pinst == nullptr)
		{
			_pinst = new Singleton;
		}

		return _pinst;
	}

	Singleton(const Singleton& s) = delete;

private:
	Singleton()
	{}

	static Singleton* _pinst;
};

Singleton* Singleton::_pinst = nullptr;

int main()
{
	//Singleton s1;
	//Singleton s2;
	//cout << Singleton::GetInstance() << endl;
	//cout << Singleton::GetInstance() << endl;
	//cout << Singleton::GetInstance() << endl;
	//Singleton copy(*Singleton::GetInstance());

	vector<std::thread> vthreads;
	int n = 16;
	for (int i = 0; i < n; ++i)
	{
		vthreads.push_back(std::thread([]()
		{
			//cout << std::this_thread::get_id() <<":";
			cout << Singleton::GetInstance() << endl;
		}));
	}

	for (auto& t : vthreads)
	{
		t.join();
	}

	return 0;
}