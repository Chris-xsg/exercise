#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<string>
using namespace std;

// 什么是异常：异常是面向对象语法处理错误一种方式

// C语言传统的处理错误的方式有哪些呢？
// 1、返回错误码  有些API接口都是把错误码放到errno中
// 2、终止程序    比如发生越界等严重问题时，我们也可以主动调用exit(xx)  assert;

// 传统的处理错误的缺陷:
// a、拿到错误码，需要查找错误码表，才知道是什么错误。
// b、如果一个函数是用过返回值拿数据，发生错误时很难处理。
//T& operator[](int index)
//{
//	// 如果index超出的容器范围，如何返回？
//}
// c、如果调用的函数栈很深，一层层返回错误码，整个处理很难受
//int f1()
//{
//	//... 发生错误，返回错误码
//	int ret;
//	if (ret != 0)
//		return ret;
//
//	return 0;
//}
//
//int f2()
//{
//	int ret = f1();
//	if (ret != 0)
//		return ret;
//
//	return 0;
//}
//
//int f3()
//{
//	int ret = f2();
//	if (ret != 0)
//		return ret;
//
//	return 0;
//}

// 面对上面的问题，C++给出的异常来解决

int x1()
{
	try
	{
		vector<int> v = { 1, 2, 3, 4, 5, 6 };
		for (int i = 0; i <= v.size(); ++i)
		{
			//cout << v[i] << " ";
			cout << v.at(i) << " ";
		}
		cout << endl;
	}
	catch (exception& e)
	{
		cout << e.what() << endl;
	}

	return 0;
}
namespace bit
{
	/*int div(int n, int m, int& ret)
	{
	if (m == 0)
	{
	return -1;
	}

	ret = n / m;
	return 0;
	}*/

	int div(int n, int m)
	{
		if (m == 0)
		{
			//throw "发生除0错误";
			throw string("发生除0错误"); // throw 可以抛出任意类型的对象
			// 直接跳转到catch匹配的地方
		}
		return n / m;
	}
}

void f1()
{
	try{
		int n, m;
		cin >> n >> m;
		cout << bit::div(n, m) << endl;
	}
	catch (const string& err)
	{
		cout << __LINE__ << err << endl;
	}
}

//int main()
//{
//	try
//	{
//		f1();
//	}
//	catch (int err)
//	{
//		cout <<err << endl;
//	}
//	catch (const string& err)
//	{
//		cout << __LINE__ << err << endl;
//	}
//	catch (...) // 捕获没有匹配的任意类型的异常,避免异常没捕获时程序直接终止了
//	{
//		cout << "未知异常" << endl;
//	}
//}

// 公司会给一个基类
// 要求你可以自己抛自己定义的异常，但是必须继承这个基类
// 这样的话，外层捕获就只需要捕获基类就可以
class Exception
{
public:
	Exception(const char* errmsg, int errid)
		: _errmsg(errmsg)
		, _errid(errid)
	{}

	virtual string what() = 0;
protected:
	int _errid;       // 错误码
	string _errmsg;   // 错误描述
	//stack<string> _st; // 调用栈帧
};

class SqlException : public Exception
{
public:
	SqlException(const char* errmsg, int errid)
		:Exception(errmsg, errid)
	{}

	virtual string what()
	{
		return "数据库错误:" + _errmsg;
	}
};

class NetworkException : public Exception
{
public:
	NetworkException(const char* errmsg, int errid)
		:Exception(errmsg, errid)
	{}

	virtual string what()
	{
		return "网络错误:" + _errmsg;
	}
};

void ServerStart()
{
	// 模拟一下出现问题抛异常报错
	if (rand() % 11 == 0)
		throw SqlException("数据库启动失败", 1);

	if (rand() % 7 == 0)
		throw NetworkException("网络连接失败", 3);

	cout << "正常运行" << endl;
}

int x3()
{
	/*for (size_t i = 0; i < 100; i++)
	{
	try
	{
	ServerStart();
	}
	catch (Exception& e)
	{
	cout << e.what() << endl;
	}
	catch (...)
	{
	cout << "未知异常" << endl;
	}
	}*/

	try{
		vector<int> v(10, 5);
		// 这里如果系统内存不够也会抛异常
		v.reserve(1000000000);

		// 这里越界会抛异常
		v.at(10) = 100;
	}
	catch (const exception& e) // 这里捕获父类对象就可以
	{
		cout << e.what() << endl;
	}
	catch (...)
	{
		cout << "Unkown Exception" << endl;
	}

	return 0;

	return 0;
}

// 异常可能会导致异常安全问题
//new / fopen / lock
//
//func();  // 如果抛异常就会有异常安全问题 -> 捕获重新抛出 or RAII 解决
//
//delete/fclose/ unlock

// 函数规范一下,如果要抛异常，你说明清楚，不抛异常也说明一下
// 但是现实中，很多人嫌麻烦，不遵守规范

// 这里表示这个函数会抛出A/B/C/D中的某种类型的异常
// void fun() throw(A, B, C, D);
// 这里表示这个函数只会抛出bad_alloc的异常
void* operator new (std::size_t size) throw (std::bad_alloc);

// 这里表示这个函数不会抛出异常
void* operator delete (std::size_t size, void* ptr) throw();
void* operator delete (std::size_t size, void* ptr) noexcept;

// 异常的优缺点总结：
// 优点：
// 1、清晰的包含错误信息
// 2、面对T operator[](int i)这样函数越界错误，异常可以很好的解决
// 3、多层调用时，里面发生错误，不再需要层层处理，最外层直接捕获即可
// 4、很多第三方库都是用异常，我们也使用异常可以更好的使用他们。比如：boost、gtest、gmock

// 缺点：
// 1、异常会导致执行流乱跳。会给我调试分析程序bug带来一些困难。
// 2、C++没有GC，异常可能到导致资源泄露等异常安全问题，需要学会使用RAII来解决。
// 3、C++的库里面的异常体系定义不太好用，很多公司都会选择自己定义。
// 4、C++的异常语言可以抛任意类型的异常，如果项目中没有做很好规范管理，那么会非常的混乱，所以一般需要定义出继承体系的异常规范。

// 异常整体而言还是一个利大于弊的东西，所以实际日常练习或者小项目，不太使用
// 公司一般还是会选择异常来处理错误
