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

//////////////////////////////////////////////////////////////////////////////////（重点）
// 1、右值引用和移动语义概念语法 
// C++98就提出了引用的概念，引用就给一个对象取别名。
// C++98 左值引用
// C++11 右值引用
// 不管是左值引用，还是右值引用，他们都是给对象取别名，。
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
// 结论：所有深拷贝类(vector/list/map/set...)，都可以加两个右值引用做参数的移动拷贝和移动赋值

//////////////////////////////////////////////////////////////////////////////////
//  2、应用：右值引用的移动构造和移动赋值,可以减少拷贝
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
		cout << "String(const String& s)-拷贝构造-效率低" << endl;

		_str = new char[strlen(s._str) + 1];
		strcpy(_str, s._str);
	}

	// s3(右值-将亡值)
	String(String&& s)
		:_str(nullptr)
	{
		// 传过来的是一个将亡值，反正你都要亡了，我的目的是跟你有一样大的空间，一样的值
		// 不如把你的控制和只给我
		cout << "String(String&& s)-移动构造-效率高" << endl;
		swap(_str, s._str);
	}

	// s3 = s4
	String& operator=(const String& s)
	{
		cout << "String& operator=(const String& s)-拷贝赋值-效率低" << endl;

		if (this != &s)
		{
			char* newstr = new char[strlen(s._str) + 1];
			strcpy(newstr, s._str);

			delete[] _str;
			_str = newstr;
		}

		return *this;
	}

	// s3 = 右值-将亡值
	String& operator=(String&& s)
	{
		cout << "String& operator=(String&& s)-移动赋值-效率高" << endl;
		swap(_str, s._str);

		return *this;
	}


	~String()
	{
		delete[] _str;
	}

	// s1 + s2
	String operator+(const String& s2)
	{
		String ret(*this);
		//ret.append(s2);

		return ret;  // 返回的是右值
	}

	// s1 += s2
	String& operator+=(const String& s2)
	{
		//this->append(s2);
		return *this; // 返回是左值
	}

private:
	char* _str;
};

//String f(const char* str)
//{
//	String tmp(str);
//	return tmp; // 这里返回实际是拷贝tmp的临时对象
//}

//int main()
//{
//	String s1("左值");
//	String s2(s1);                      // 参数是左值
//	String s3(f("右值-将亡值"));        // 参数是右值-将亡值(传递给你用，用完我就析构了)
//	//String s4(move(s1));
//
//	String s5("左值");
//	s5 = s1;
//	s5 = f("右值-将亡值");
//
//	return 0;
//}

////////////////////////////////////////////////////////////////////////////////
// 3、应用：当传值返回值，返回是右值，结合前面学的移动构造和移动赋值，可以拷贝拷贝
class Solution1 {
public:
	vector<string> letterCombinations(string digits) {
		vector<string> v;

		return v;
	}
};

class Solution2 {
public:
	// 核心思想：找出杨辉三角的规律，发现每一行头尾都是1，中间第[j]个数等于上一行[j-1]+[j]
	vector<vector<int>> generate(int numRows) {
		vector<vector<int>> vv;
		// 先开辟杨辉三角的空间
		vv.resize(numRows);
		// ...

		return vv;
	}
};

int x1()
{
	String s1("s1");
	String s2("s2");

	String s3 = s1 += s2; // 拷贝构造
	String s4 = s1 + s2;  // 移动构造

	// 现实中不可避免存在传值返回的场景，传值返回的拷贝返回对象的临时对象。
	// 如果vector只实现参数为const左值引用深拷贝，那么下面的代价就很大
	// vector(const vector<T>& v)->深拷贝

	// 但是如果vector实现了参数右值引用的移动拷贝，那么这里效率就会很高
	// vector(vector<T>&& v) ->移动拷贝
	// 结论：右值引用本身没太多意义，右值引用的实现了移动构造和移动赋值
	// 那么面对接收函数传值返回对象(右值)等等场景，可以提高效率
	vector<string> v = Solution1().letterCombinations("abcd");
	vector<vector<int>> vv = Solution2().generate(5);

	return 0;
}

//////////////////////////////////////////////////////////////////////////////
// 4、右值引用去做函数的参数,减少拷贝

//std::vector::push_back
//void push_back(const value_type& val);
//void push_back(value_type&& val);
//
//std::list::push_back
//void push_back(const value_type& val);
//void push_back(value_type&& val);
//
//std::set::insert
//pair<iterator, bool> insert(const value_type& val);
//pair<iterator, bool> insert(value_type&& val);

//std::vector::emplace_back
//template <class... Args>
//void emplace_back(Args&&... args);   // 模板的可变参数 （了解）
// 网上有人说：emplace版本表push和insert高效。这句话不准确，没有深入去分析。

// ... 其他容器也插入数据结构也基本都是两个重载实现，一个左值引用，一个右值引用
int x2()
{
	vector<string> v;
	string s1("左值");
	string s2("左值");

	int val = 1234;

	// push_back中调用的是string的拷贝构造
	v.push_back(move(s2));             // void push_back(const value_type& val);

	// push_back中调用的是string的移动构造
	v.push_back("右值");         //void push_back(value_type&& val);
	v.push_back(to_string(val)); // void push_back(value_type&& val);

	v.emplace_back(s1); // v.emplace_back(move(s1)); 
	v.emplace_back("右值");

	vector<pair<string, string>> vp;
	vp.push_back(make_pair("右值", "右值"));

	pair<string, string> kv("左值", "左值");
	vp.push_back(kv);

	vp.emplace_back(make_pair("右值", "右值"));
	vp.emplace_back(kv);
	vp.emplace_back("右值", "右值"); // 体现emplace_back模板可变参数特点的地方

	return 0;
}

// 总结
// 右值引用做参数和作返回值减少拷贝的本质是利用了移动构造和移动赋值
// 左值引用和右值引用本质的作用都是减少拷贝，右值引用本质可以认为是弥补左值引用不足的地方, 他们两相辅相成

// 左值引用：解决的是传参过程中和返回值过程中的拷贝
// 做参数：void push(T x) -> void push(const T& x)  解决的是传参过程中减少拷贝
// 做返回值：T f2() -> T& f2()  解决的返回值过程中的拷贝
// ps:但是要注意这里有限制，如果返回对象出了作用域不在了就不能用传引用, 这个左值引用无法解决，等待C++11右值引用解决

// 右值引用：解决的是传参后，push/insert函数内部将对象移动到容器空间上的问题.
// + 传值返回接收返回值的拷贝
// 做参数： void push(T&& x)  解决的push内部不再使用拷贝构造x到容器空间上，而是移动构造过去
// 做返回值：T f2();  解决的外面调用接收f2()返回对象的拷贝，T ret = f2(),这里就是右值引用的移动构造，减少了拷贝

void Fun(int &x){ cout << "lvalue ref" << endl; }
void Fun(const int &x){ cout << "const lvalue ref" << endl; }
void Fun(int &&x){ cout << "rvalue ref" << endl; }
void Fun(const int&& x){ cout << "const rvalue ref" << endl; }

template<typename T>
void PerfectForward(T &&t)
{
	// 右值引用会第二次之后的参数传递过程中右值属性丢失,下一层调用会全部识别为左值
	// 完美转发解决
	Fun(std::forward<T>(t));
}

int x3()
{
	PerfectForward(10); // rvalue ref

	int a;
	PerfectForward(a); // lvalue ref
	PerfectForward(std::move(a)); // rvalue ref

	const int b = 8;
	PerfectForward(b); // const lvalue ref
	PerfectForward(std::move(b)); // const rvalue ref

	string s0("hello");
	string s1 = to_string(11111);

	/*basic_string(_Myt&& _Right) _NOEXCEPT
	: _Mybase(_Right._Getal())
	{	// construct by moving _Right
	_Tidy();
	_Assign_rv(_STD forward<_Myt>(_Right));
	}*/

	return 0;
}

#include <algorithm>
#include <functional>

template<class T>
struct Greater
{
	bool operator()(const T& x1, const T& x2)
	{
		return x1 > x2;
	}
};

bool g2(const int& x1, const int& x2)
{
	return x1 > x2;
}

int x4()
{
	int array[] = { 4, 1, 8, 5, 3, 7, 0, 9, 2, 6 };

	// 默认按照小于比较，排出来结果是升序
	std::sort(array, array + sizeof(array) / sizeof(array[0]));

	// 如果需要降序，需要改变元素的比较规则
	//std::sort(array, array + sizeof(array) / sizeof(array[0]), greater<int>());


	Greater<int> g1;
	g1(1, 2); // g1是一个对象，这里调用的是他的operator()实现的比较
	g2(1, 2); // g2是一个函数指针，这里是调用他指向的函数
	// 他们是完全不同的对象但是他们用起来是一样的。

	std::sort(array, array + sizeof(array) / sizeof(array[0]), g1);
	std::sort(array, array + sizeof(array) / sizeof(array[0]), g2);

	return 0;
}

struct Goods
{
	string _name;  // 名字
	double _price; // 价格
	int    _num;   // 数量
	// ...
};

// 那么这里如果去重载Goods的operator>/operator<是不好的，因为你不知道需要按哪一项成员去比较

struct ComparePriceGreater
{
	bool operator()(const Goods& gl, const Goods& gr)
	{
		return gl._price > gr._price;
	}
};

struct CompareNumGreater
{
	bool operator()(const Goods& gl, const Goods& gr)
	{
		return gl._num > gr._num;
	}
};

struct CompareNameGreater
{
	bool operator()(const Goods& gl, const Goods& gr)
	{
		return gl._name > gr._name;
	}
};
// 其实还有小于的，大于等于和小于等于，会发现我们要写很多个仿函数
// 其实直接写函数也可以，不过类似要写很多个函数
// 下面看我们用labmber表达式来更好的解决问题

int x5()
{
	Goods gds[] = { { "苹果", 2.1, 3 }, { "相交", 3.0, 5 }, { "橙子", 2.2, 9 }, { "菠萝", 1.5, 10 } };
	sort(gds, gds + sizeof(gds) / sizeof(gds[0]), ComparePriceGreater());
	sort(gds, gds + sizeof(gds) / sizeof(gds[0]), CompareNumGreater());
	sort(gds, gds + sizeof(gds) / sizeof(gds[0]), CompareNameGreater());

	// lamber
	/*auto price_greater = [](const Goods& g1, const Goods& g2){
	return g1._price > g2._price;
	};
	sort(gds, gds + sizeof(gds) / sizeof(gds[0]), price_greater);*/

	return 0;
}


// lamber表达式其实定义函数内存的匿名函数函数
// 1.掌握lamber表达式写的格式
// 2.lamber表达式的使用场景  （对比仿函数对象、函数指针）
// 3.lamber表达式的原理

int add1(int a, int b)
{
	return a + b;
}

int x7()
{
	// [捕捉列表](参数)->返回值类型{函数体}
	int a = 0, b = 1;
	// 实现一个a+b的lamber表达式
	auto add1 = [](int x1, int x2)->int{return x1 + x2; };
	cout << add1(a, b) << endl;

	// 捕捉列表就是捕捉跟我一个作用域的对象
	// 传值捕捉 [a]捕捉a  [a,b]捕捉a，b  [=]捕捉同一作用域中的所有对象
	// 传引用捕捉 [&a]捕捉a  [&a,&b]捕捉a，b  [&]捕捉同一作用域中的所有对象
	// 传值补充的对象是不能被改变的。(加上mutable就可以改变了)
	auto add2 = [a, b]()->int{return a + b; };
	add2();

	// 实现a和b交换
	//auto swap = [](int& a, int& b){int c = a; a = b; b = c; };
	auto swap = [](int& x, int& y){
		int z = x;
		x = y;
		y = z;
	};

	swap(a, b);

	/* 不正确的用法
	auto swapab = [a, b]()mutable {
	int c = a;
	a = b;
	b = c;
	};
	swapab();*/

	auto swapab = [&a, &b](){
		int c = a;
		a = b;
		b = c;
	};
	swapab();

	return 0;
}

int x8()
{
	Goods gds[] = { { "苹果", 2.1, 3 }, { "相交", 3.0, 5 }, { "橙子", 2.2, 9 }, { "菠萝", 1.5, 10 } };
	sort(gds, gds + sizeof(gds) / sizeof(gds[0]), ComparePriceGreater());
	sort(gds, gds + sizeof(gds) / sizeof(gds[0]), CompareNumGreater());
	sort(gds, gds + sizeof(gds) / sizeof(gds[0]), CompareNameGreater());

	// lamber优势就会让代码可读性更强
	/*auto price_greater = [](const Goods& g1, const Goods& g2)->bool{return g1._price > g2._price; };
	sort(gds, gds + sizeof(gds) / sizeof(gds[0]), price_greater);
	*/
	sort(gds, gds + sizeof(gds) / sizeof(gds[0]), [](const Goods& g1, const Goods& g2)->bool{return g1._price > g2._price; });

	sort(gds, gds + sizeof(gds) / sizeof(gds[0]), [](const Goods& g1, const Goods& g2)->bool{return g1._price < g2._price; });

	sort(gds, gds + sizeof(gds) / sizeof(gds[0]), [](const Goods& g1, const Goods& g2)->bool{return g1._num > g2._num; });

	sort(gds, gds + sizeof(gds) / sizeof(gds[0]), [](const Goods& g1, const Goods& g2)->bool{return g1._num < g2._num; });

	return 0;
}

int x9()
{
	int a = 1, b = 2;
	//  对象 = 对象（替换编译器生成的lamber_uuid仿函数的对象）
	auto add = [](int x, int y)->int{return x + y; };
	add(a, b);  // call lamber_uuid仿函数的operator()

	// 底层还是依靠仿函数来实现，也就是说你定义了一个lamber表达式，
	// 实际上编译器会全局域生成一个叫lamber_uuid类，仿函数的operator()的参数和实现
	// 就是我们写的labmber表达式的参数和实现
	/*
	00A5C8AC  mov         eax, dword ptr[b]
	00A5C8AF  push        eax
	00A5C8B0  mov         ecx, dword ptr[a]
	00A5C8B3  push        ecx
	00A5C8B4  lea         ecx, [add]
	00A5C8B7  call        <lambda_afc2b2a8543babab622761003a6aa683>::operator() (0A5AEC0h)
	*/

	auto swapab = [&a, &b](){
		int c = a;
		a = b;
		b = c;
	};
	swapab();
	/*
	0065DA4C  lea         ecx, [swapab]
	0065DA4F  call        <lambda_574e874b35e37ce2b7269242f59eb074>::operator() (065ADC0h)
	*/

	return 0;
}

//////////////////////////////////////////////////////////////////////////
// windows 自己的一套API           如：CreateThread
// Linux   使用posix的pthread      如：pthread_create
// C++98中，如果你想写多线程的程序，即可以在Windows下跑，也可以在Linux，那么怎么办？ 
// 用条件编译
/*
#ifdef _WIN32
CreateThread(...)
#else
pthread_create(...)
#endif
*/

// C++11 线程库
// 特点：跨平台、面向对象封装的类(每个线程是一个类对象)
// 实现原理：封装库时使用了条件编译，也就是说他的底层还是分别调用了不用平台的线程API

// 扩展：吐槽一下C++，C++缺点之一：就是更新有用的东西太慢了，比如线程库C++11(2011)才更新的,而且
// 到现在也没有更新一个官方的封装好的靠谱网络库。其次一些不痛不痒的语法更新了一堆，增加学习成本。

#include<thread>
#include<mutex>
#include<atomic>

// 1、函数指针配合thread使用

//mutex mtx;
//int x = 0;
//// 两个线程去一起对x加n次
//
//void Add(int n)
//{
//	mtx.lock(); // 串行 一个线程跑完了，另一个线程接着跑
//	for (int i = 0; i < n; ++i)
//	{
//		++x;
//	}
//	mtx.unlock();
//
//	// 并行
//	for (int i = 0; i < n; ++i)
//	{
//		mtx.lock();  // t2刚切出去，t1就解锁了，马上就把t2切回来
//		++x;  // t1
//		mtx.unlock();
//	}
//
//	// 思考为什么串行还快一些？因为这里锁的粒度太小了，时间都花到切换上下文
//}
//
//int main()
//{
//	thread t1(Add, 1000000);
//	thread t2(Add, 1000000);
//
//	t1.join();
//	t2.join();
//
//	cout << x << endl;
//
//	return 0;
//}

//int x = 0;
//atomic<int> x = 0; // 支持整形/浮点的原子++、--
//// 扩展学习：atomic支持CAS->无锁编程，一会我给大家发一篇文章链接，有兴趣的同学可以下去看看。
//// 两个线程去一起对x加n次
//
//void Add(int n)
//{
//	for (int i = 0; i < n; ++i)
//	{
//		++x;
//	}
//}
//
//int main()
//{
//	thread t1(Add, 1000000);
//	thread t2(Add, 1000000);
//
//	t1.join();
//	t2.join();
//
//	cout << x << endl;
//
//	return 0;
//}


// 仿函数配合thread使用
atomic<int> x = 0;

struct Add
{
	void operator()(int n)
	{
		for (int i = 0; i < n; ++i)
		{
			++x;
		}
	}
};

int y2()
{
	Add add;
	thread t1(add, 100000);
	//thread t2(add, 100000);
	thread t2(Add(), 100000);


	cout << t1.get_id() << endl;
	cout << t2.get_id() << endl;

	t1.join();
	t2.join();

	cout << x << endl;

	return 0;
}

// lamber表达式配合thread
int y3()
{
	atomic<int> x = 0;

	auto add = [&x](int n){
		for (int i = 0; i < n; ++i)
		{
			++x;
		}
	};

	thread t1(add, 100000);
	thread t2(add, 100000);

	cout << t1.get_id() << endl;
	cout << t2.get_id() << endl;

	t1.join();
	t2.join();

	cout << x << endl;

	return 0;
}

int main()
{
	atomic<int> x = 0;
	// m个线程对x加n次
	int m, n;
	cin >> m >> n;
	/*vector<thread> vthreads;
	for (int i = 0; i < m; ++i)
	{
	vthreads.push_back(thread([&x](int count){
	for (int i = 0; i < count; ++i)
	{
	++x;
	}
	}, n));
	}*/

	// 注意的是thread支持移动赋值和移动拷贝，不支持深拷贝的拷贝构造和拷贝赋值
	vector<thread> vthreads(m);
	for (int i = 0; i < m; ++i)
	{
		// 移动赋值
		/*thread t([&x](int count){
		for (int i = 0; i < count; ++i)
		{
		++x;
		}
		}, n);
		vthreads[i] = move(t);*/
		vthreads[i] = thread([&x](int count){
			for (int i = 0; i < count; ++i)
			{
				++x;
			}
		}, n);
	}

	for (auto& t : vthreads)
	{
		cout << t.get_id() << ".join()" << endl;
		t.join();
	}

	cout << x << endl;

	return 0;
}

// 扩展作业线程池
struct tack
{
	template<class Fn>
	tack(Fn)
	{}
};


class thread_pool
{
public:
	thread_pool(int n = 8)
		:vthreads(n)
	{}

private:
	vector<thread> vthreads;
	//queue<task> _q;
};