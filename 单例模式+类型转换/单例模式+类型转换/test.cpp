#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<thread>
#include<vector>
#include<windows.h>
#include<memory>
using namespace std;

// 迭代器模式 -- 基于面向对象三大特性之一的 封装设计出来的，用一个迭代器类封装以后，不暴露容器的结构的情况下，统一的方式访问修改容器中的数据。

// 适配器模式 -- 体现的是一种复用
// 还有一些常见的设计模式如：工厂模式、装饰器模式、观察者模式、单例模式...
// 一个类只能在全局(进程中)只有一个实例对象。
// 什么场景下使用？比如一个进程中有一个内存池，进程中的多线程需要内存都要到这个内存池中取，那么这个内存池的类就可以设计单例模式。

// 类的名称是随着你的场景给的，比如你的是内存池，那么你就定义成MemoryPool

namespace lazy_man
{
	// 懒汉模式 -- 第一次获取对象时，再创建对象
	class Singleton
	{
	public:
		static Singleton* GetInstance()
		{
			//::Sleep(1000);  增加没加锁时出现线程不安全的条件（2个以上线程同时过了判断条件）

			// 双检查
			if (_pinst == nullptr)
			{
				//_mtx.lock();
				unique_lock<mutex> lock(_mtx);
				if (_pinst == nullptr)
				{
					_pinst = new Singleton;
				}
				//_mtx.unlock();
			}

			// ...

			return _pinst;
		}

		static void DelInstance()
		{
			//unique_lock<mutex> lock(_mtx);
			delete _pinst;
			_pinst = nullptr;
		}

		Singleton(const Singleton& s) = delete;

	private:
		Singleton()
		{}

		static Singleton* _pinst;
		static mutex _mtx;
	};

	// 1、如果要手动释放单例对象，可以调用DelInstance
	// 2、如果需要程序结束时，正常释放单例对象，可以加入下面的设计
	class GC
	{
	public:
		~GC()
		{
			Singleton::DelInstance();
		}
	};

	static GC gc;


	Singleton* Singleton::_pinst = nullptr;
	mutex Singleton::_mtx;

	int x()
	{
		//Singleton s1;
		//Singleton s2;
		//cout << Singleton::GetInstance() << endl;
		//cout << Singleton::GetInstance() << endl;
		//cout << Singleton::GetInstance() << endl;
		//Singleton copy(*Singleton::GetInstance());

		vector<std::thread> vthreads;
		int n = 100;
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
}

namespace hungry_man
{
	// 饿汉模式  一开始(main函数之前)就创建对象
	class Singleton
	{
	public:
		static Singleton* GetInstance()
		{
			return &_inst;
		}

		Singleton(const Singleton&) = delete;
	private:
		Singleton()
		{}

		static Singleton _inst;
	};

	Singleton Singleton::_inst;
	// static对象是在main函数之前创建的，这会只有主线程，所以不存在线程安全。


	int x()
	{
		//Singleton s1;
		//Singleton s2;
		//cout << Singleton::GetInstance() << endl;
		//cout << Singleton::GetInstance() << endl;
		//cout << Singleton::GetInstance() << endl;
		//Singleton copy(*Singleton::GetInstance());

		vector<std::thread> vthreads;
		int n = 10;
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
}

//int main()
//{
//	hungry_man::x();
//
//	return 0;
//}

// 总结对比一下饿汉和懒汉的区别
// 1、懒汉模式需要考虑线程安全和释放的问题，实现相对更复杂，饿汉模式不存在以上问题，实现简单
// 2、懒汉是一种懒加载模式需要时在初始化创建对象，不会影响程序的启动。饿汉模式则相反，程序启动阶段就创建初始化实力对象，会导致程序启动慢，影响体验。
// 3、如果有多个单例类，假设有依赖关系(B依赖A)，要求A单例先创建初始化，B单例再创建初始化，那么就不能饿汉，因为无法保证创建初始化顺序，这时用懒汉我们就可以手动控制。

// 总结一下：实际中懒汉模式还是更实用一些



/////////////////////////////////////////////////////////////////////////////
// 类型转换
class A
{
public:
	virtual void f()
	{}

	int _a;
};

class B : public A
{
public:
	int _b;
};


//A* pa = &a;
//f_cast(pa);
//
//pa = &b;
//f_cast(pa);

void f_cast(A* pa)
{
	// 如果想区分pa是指向父类，还是子类对象？
	// 如果pa是指向子类对象，则转换成功，
	// 如果pa指向父类对象则转换失败返回nullptr 
	B* pb = dynamic_cast<B*>(pa);
	//B* pb = (B*)pa;
	if (pb != nullptr)
	{
		cout << "转换成功：pa指向子类对象" << endl;
		pb->_a = 1;
		pb->_b = 2;
	}
	else
	{
		cout << "转换失败：pa指向父类对象" << endl;
	}
}

int x10()
{
	int i = 1;
	double d = 8.88;
	i = d; // c语言支持相近类型的隐式类型转换 (相近类型，也就是意义相似的类型)
	cout << i << endl;

	int* p = nullptr;
	p = (int*)i; // c语言支持相近类型的强制类型转换 (不相近类型，也就是意义差别很大的类型)
	cout << p << endl;

	// C++ 兼容C语言留下来的隐式转换和显示转换，但是C++觉得C语言做得不规范，C++想规范一下
	// 标准C++为了加强类型转换的可视性，引入了四种命名的强制类型转换操作符
	// static_cast、reinterpret_cast、const_cast、dynamic_cast
	d = static_cast<double>(i);     // 对应c语言隐式类型转换 （相近类型）
	p = reinterpret_cast<int*>(i);  // 对应c语言大部分强制类型转换（不相近类型）

	volatile const int ci = 10;
	//const int ci = 10;
	int* pi = const_cast<int*>(&ci); // 对应c语言强制类型转换中去掉const属性的（不相近类型）
	//int* pi = (int*)&ci;
	*pi = 20;
	cout << *pi << endl;
	cout << ci << endl; // 这里打印是10是因为ci存储的内存被改了，但是ci被放进了寄存器，这里去寄存器中取，还是10.本质这是由于编译器对const对象存取优化机制导致。
	// 想要禁止编译器做这个优化，每次都到内存中去取值，就把volatile加上

	A a;
	B b;

	// C++中子类对象可以赋值给父类的对象、指针、引用，这个过程中会发生切片，这个过程是
	// 语法天然支持的，这个叫向上转换，都可以成功。

	// 如果是父类的指针或者引用，传给子类的指针，这个过程叫向下转换，这个过程有可能能成功
	// 要看具体情况。
	// 最后需要注意的是：dynamic_cast向下转换只能针对继承中的多态类型(父类必须包含虚函数)

	// 因为dynamic_cast如何识别父类的指针是指向父类对象还是子类对象的呢？dynamic_cast的原理
	// dynamic_cast通过去虚表的上方存储的标识信息，来判断指向父类对象还是子类对象。
	A* pa = &a;
	f_cast(pa);

	pa = &b;
	f_cast(pa);

	return 0;
}

// 总结一下：尽量少用类型转换，如果要用尽量规范一点，且知道转换后会有什么影响

class AA
{
public:
	//AA(int a)
	explicit AA(int a)
	{
		cout << "AA(int a)" << endl;
	}

	//AA(int a1, int a2)
	explicit AA(int a1, int a2)
	{
		cout << "AA(int a1, int a2)" << endl;
	}

	AA(const AA& a)
	{
		cout << "AA(const AA& a)" << endl;
	}
private:
	int _a1;
	int _a2;
};

int main()
{
	AA aa1(1);

	// 隐式转换-> A tmp(1); A a2(tmp)，再优化成直接构造
	AA aa2 = 1;
	AA aa3 = { 1, 2 }; // C++11
}


