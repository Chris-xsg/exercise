#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<list>
#include<string>
#include<map>
#include <initializer_list>
using namespace std;

// 列表初始化，不过我们要能看懂，实际中这个用得也不多。
// （了解）
class Point
{
public:
	Point(int x = 0, int y = 0) : _x(x), _y(y)
	{}
private:
	int _x;
	int _y;
};

//int main()
//{
//	int x = 1;
//
//	// C++11  花括号列表初始化
//	vector<int> v1{ 1, 2, 3, 4, 5 };
//	vector<int> v2 = { 1, 2, 3, 4, 5 };
//
//	list<int> l1{ 1, 2, 3, 4, 5 };
//	list<int> l2 = { 1, 2, 3, 4, 5 };
//
//	map<string, int> m1{ { "苹果", 1 }, { "西瓜", 2 }, { "香蕉", 3 } };
//	map<string, int> m2 = { { "苹果", 1 }, { "西瓜", 2 }, { "香蕉", 3 } };
//
//	Point p1(1, 2);
//	Point p2{ 1, 2 };
//	Point p3 = { 1, 2 };
//
//	auto ilt1 = { 1, 2, 3 };
//	initializer_list<int> ilt2 = { 1, 2, 3 };
//	// 容器是如何支持这种花括号里列表初始化的呢？
//
//	return 0;
//}

//////////////////////////////////
// 类型推导，属于RTTI  run time type Identification
// 程序运行起来对对象的类型识别
// （了解）
//int main()
//{
//	int a = 10;
//	double b = 20;
//	auto c = a + b;
//
//	// 拿到类型名称的字符串
//	cout << typeid(c).name() << endl;
//	string s;
//	cout << typeid(s).name() << endl;
//
//	// 假设我想定一个跟c和s一样类型的对象。
//	// 通过对象去推类型
//	decltype(c) d;
//	decltype(s) e;
//
//	cout << typeid(d).name() << endl;
//	cout << typeid(e).name() << endl;
//
//	return 0;
//}

// auto和范围for -> 简化了部分代码的写法
// 熟悉

// auto不能做形参和返回值
//auto func(auto e)
//{}

//int main()
//{
//	std::map<std::string, std::string> dict = { { "insert", "插入" }, { "sort", "排序" } };
//	std::map<std::string, std::string>::iterator it1 = dict.begin();
//	auto it2 = dict.begin();
//	// 这里it1和it2可以认为是完全一个类型的对象
//	// 唯一差别是it2的类型是编译器自动推导出来
//	// auto的优势就是可以把在类型比较复杂地方，简化代码的写法
//
//	// 这里要注意当容器存对象比较大，或者这个对象要做深拷贝，如string
//	// 最好给&和const，可以减少拷贝提高效率
//	// 容器支持范围for原理：范围for会被编译器替换成迭代器，也就是意味着支持迭代器就支持范围for
//	//for (auto e : dict)
//	for (const auto& e : dict)
//	{
//		cout << e.first << ":" << e.second << endl;
//	}
//
//	for (const std::pair<const std::string, std::string>& e : dict)
//	{
//		cout << e.first << ":" << e.second << endl;
//	}
//	cout << endl;
//
//	// 除了STL的容器可以使用范围for用法，数组也可以(原声指针可以认为也天然迭代器，比如vector/string的迭代器就是原声指针)
//	int a[] = { 1, 2, 3, 3, 5, 4 };
//	for (auto e : a)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//
//}

// final与override (了解)
// 回忆一下这两个关键字分别的作用是什么？
// final修饰类，类就变成了最终类，不能被继承
// final还可以修饰虚函数，这个虚函数不能被重写
// override是子类重写虚函数，检查是否完成重写。不满足重写的条件，则报错。

// 智能指针  （熟悉）
// 后面我们专门花2节课讲这个

// 新容器
// C++98容器
// string/vector/list/deque/map/set/bitset + stack/queue/priority_queue
// C++11新容器
// array(定长数组):实际中用的很少，缺点：定长 + 存储数据的空间在栈上,栈的空间本来就不大。
// forword_list(单链表)：实际中用得少，缺点：不支持尾插尾删 + insert数据也是在当前位置的后面
// unordered_map/unordered_set : 推荐使用，因为他们的效率高于map/set

//  默认成员函数控制
//class A
//{
//public:
//	A() = default; // 指定显示去生成默认构造函数
//
//	A(const int& a)
//		:_a(a)
//	{}
//private:
//	int _a = 10;
//};
//
//int main()
//{
//	A aa1;
//	A aa2(aa1);
//
//	return 0;
//}

// 要求A的对象不能拷贝和赋值(防拷贝)
//class A
//{
//public:
//	A() = default; // 指定显示去生成默认构造函数
//
//	// C++98
//	// 只声明，不实现，这样就被办法用(拷贝对象)，缺陷：别人可以类外面定义
//	// 为了解决这个缺陷，private限定
//private:
//	A(const A& aa);
//	A& operator=(const A& aa);
//private:
//	int _a = 10;
//};
//
//// 类外面定义
//A::A(const A& aa)
//{}
//
//int main()
//{
//	A aa1;
//	A aa2(aa1);
//	aa1 = aa2;
//
//	return 0;
//}

//class A
//{
//public:
//	A() = default; // 指定显示去生成默认构造函数
//
//	// C++11
//	A(const A& aa) = delete;
//	A& operator=(const A& aa) = delete;
//private:
//	int _a = 10;
//};
//
//int main()
//{
//	A aa1;
//	A aa2(aa1);
//	aa1 = aa2;
//
//	return 0;
//}

////////////////////////////////////////////////////////////////////////////////////////
// 右值引用和移动语义 （重点）
// C++98就提出了引用的概念，引用就给一个对象取别名。
// C++98 左值引用
// C++11 右值引用
// 不管是左值引用，还是右值引用，他们都是给对象取别名，
// 不过左值引用主要是给左值取别名，右值引用主要是给右值取别名。

// 什么是左值？什么是右值？
// =左边就是左值？右边的就是右值？ 注意这个是一个C语法就留下的坑，就像左移和右移一样，
// 这里左右不是方向。左边的值也不一定左值，右边的值不一定是右值
// int x1 = 10; int x2 = x1; int x3 = x1+x2; 这里x1是左值，10是右值，x2是左值,x1+x2表达式返回值就是右值
// 可以修改就可以认为是左值，左值通常是变量
// 右值通常是常量，表达式或者函数返回值(临时对象)

//int main()
//{
//	int x = 1, y = 2;
//	
//	// 左值引用的定义
//	int a = 0;
//	int& b = a;
//
//	// 左值引用不能引用右值, const左值引用可以
//	//int& e = 10; 
//	//int& f = x + y;
//	const int& e = 10;
//	const int& f = x + y;
//
//
//	// 右值引用的定义
//	int&& c = 10;
//	int&& d = x + y;
//
//	// 右值引用不能引用左值，但是可以引用move后左值
//	//int&& m = a;
//	int&& m = move(a);
//
//	return 0;
//}

//template<class T>
//void f(const T& a)
//{
//	cout << "void f(const T& a)" << endl;
//}
//
//template<class T>
//void f(const T&& a)
//{
//	cout << "void f(const T&& a)" << endl;
//}
//
//int main()
//{
//	int x = 10;
//	f(x); // 这里会匹配左值引用参数的f
//	f(10);// 这里会匹配右值引用参数的f
//
//	return 0;
//}

// C++11又将右值区分为：纯右值和将亡值
// 纯右值：基本类型的常量或者临时对象
// 将亡值：自定义类型的临时对象
class String
{
public:
	String(const char* str = "")
	{
		_str = new char[strlen(str) + 1];
		strcpy(_str, str);
	}

	// s2(s1)
	String(const String& s)
	{
		cout << "String(const String& s)-深拷贝-效率低" << endl;

		_str = new char[strlen(s._str) + 1];
		strcpy(_str, s._str);
	}

	// s3(右值-将亡值)
	String(String&& s)
		:_str(nullptr)
	{
		// 传过来的是一个将亡值，反正你都要亡了，我的目的是跟你有一样大的空间，一样的值
		// 不如把你的控制和只给我
		cout << "String(String&& s)-移动拷贝-效率高" << endl;
		swap(_str, s._str);
	}

	String& operator=(const String& s)
	{
		return *this;
	}

	String& operator=(String&& s)
	{
		return *this;
	}


	~String()
	{
		delete[] _str;
	}
private:
	char* _str;
};

String f(const char* str)
{
	String tmp(str);
	return tmp; // 这里返回实际是拷贝tmp的临时对象
}

int main()
{
	String s1("左值");
	String s2(s1);                      // 参数是左值
	String s3(f("右值-将亡值"));        // 参数是右值-将亡值(传递给你用，用完我就析构了)

	return 0;
}





