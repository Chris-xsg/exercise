#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<iostream>
#include<stdbool.h>
using namespace std; // std C++标准库的命名空间

//命名空间
//namespace bit
//{
//	int a;
//	int add();
//	int printf = 0;
//	namespace N1
//	{
//		int b;
//	}
//}
//
//int main()
//{
//	printf("%d\n", bit::printf);//名字冲突
//	printf("%d\n", bit::N1::b);
//	return 0;
//}




//int main()
//{
//	int a = 1;
//	double b = 1.1;
//	//	C要指定格式输出
//	printf("%d %f\n", a, b);
//	//C++直接输出
//	cout << a << "," << b << endl;
//    return 0;
//}

/*int main()
{
	int a = 1;
	scanf("%d", &a);
	printf("%d\n", a);


	cin >> a;
	cout << a << endl;
	return 0;
}*/


//缺省参数
//void TestFunc(int a = 0)
//{
//	cout << a << endl;
//}
//int main()
//{
//	TestFunc();
//	TestFunc(1);
//	return 0;
//}
//全缺省
//半缺省(部分缺省)：必须是从右往左，连续的，至少传一个

//引用
//int main()
//{
//	int a = 10;
//	int& ra = a;
//	cout << &a << endl;
//	cout << &ra << endl;
//	int& b = a;
//	cout << &b << endl;
//	int& c = b;
//	cout << &c << endl;
//
//	//int& ra;引用必须初始化
//
//	int x = 1;
//	c = x;//把x的值赋值给了c，并不是c变成了x的别名
//
//
//	return 0;
//}

//int main()
//{
//	const int a = 10;
//	//权限放大 只读 -> 可读可写
//	//int& b = a;  无法引用 a自己无法改变，b是别名也不能改变
//	const int& b = a;
//
//	int c = 20;
//	int& d = c;
//	//权限缩小 可读可写 -> 只读 
//	const int& e = c;//可以引用 c自己可以改变，e只能读，不能改变是可以的
//	
//
//	return 0;
//}

//int main()
//{
//
//	int i = 0;
//	double d = i; //隐式类型的转换
//	const double& rd = i;
//
//	return 0;
//}

//void swap(int& ra, int& rb)
//{
//	int c = ra;
//	ra = rb;
//	rb = c;
//}
//int main()
//{
//	int a = 0, b = 2;
//	swap(a, b);
//	cout << a << endl << b << endl;
//	return 0;
//}


//class Time
//{
//public:
//	Time()
//	{
//		_hour = 0;
//		_min = 0;
//		_sec = 0;
//	}
//	void print()
//	{
//		cout << _hour << ":" << _min << ":" << _sec << endl;
//
//	}
//private:
//	int _hour;
//	int _min;
//	int _sec;
//};


//class Date
//{
//public:
//	//无参和三个参数无法和全缺省的三个参数构造函数并存
//
//	//Date d1(2020, 3, 12); 构造函数
//	//Date(int year, int month, int day)
//	//{
//	//	_year = year;
//	//	_month = month;
//	//	_day = day;
//	//}
//
//	////Date d2;
//	////两个构造函数构成函数重载
//	//Date()
//	//{
//	//	_year = 1900;
//	//	_month = 1;
//	//	_day = 1;
//	//}
//
//	//全缺省的构造函数 推荐的写法
//	/*Date(int year = 0, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}*/
//
//	//没有写构造函数，编译器会生成一个默认的构造函数
//	//c++中不用传参数去调用的构造函数就是默认构造函数 -> 无参构造函数 全缺省构造函数
//
//	/*void Init(int year, int month, int day)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}*/
//
//	void print()
//	{
//		cout << _year << "-" << _month << "-" << _day << endl;
//		_t.print();
//	}
//
//private:
//	int _year;
//	int _month;
//	int _day;
//	Time _t;
//};
//
//
////int main()
////{
////	int i = 0;
////	Date d; //初始化
////	d.print(); //还没有初始化就开始访问
////
////	d.Init(2020, 3, 12);
////	d.print();
////
////
////	return 0;
////}
//
//
////int main()
////{
////	//对象定义出来就初始化-》构造函数
////	Date d1(2020, 3, 12);
////	d1.print();
////
////	//Date d2(); 导致d2 没有被定义出来
////	Date d2; 
////	d2.print();
////
////	Date d3;
////	d3.Init(2020, 3, 14);//构造函数只能在对象构造的时候使用一次,后面想要修改只能使用Init
////	d3.print();
////
////	return 0;
////}
//
//int main()
//{
//	/*Date d1;
//	Date d2(2020);
//	Date d3(2020, 1);
//	Date d4(2020, 2, 2);
//	d1.print();
//	d2.print();
//	d3.print();
//	d4.print();*/
//
//	Date d1;
//	d1.print();
//	
//
//
//
//
//	return 0;
//}



//class Date
//{
//public:
//	Date(int year = 0, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//	~Date()
//	{
//		//Date类没有资源需要清理，所以析构函数内什么都不用写
//	}
//
//	void print()
//	{
//		cout << _year << "-" << _month << "-" << _day << endl;
//				
//	}
//
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//class Stack
//{
//public:
//	Stack(int n)
//	{
//		_a = (int*)malloc(sizeof(int)*n);
//		_size = 0;
//		_capacity = n;
//
//	}
//
//	//Date不写析构，没问题，编译生成就也可以
//	//Stack不写析构，有问题，内存泄露
//	~Stack()
//	{
//		free(_a);
//		_size = _capacity = 0;
//		_a = nullptr;
//	}
//
//private:
//	int* _a;
//	int _size;
//	int _capacity;
//};
//
//
//int main()
//{
//	Date d1; //析构函数并不是完成d1对象销毁，d1对象销毁是系统完成。析构函数完成的是清理工作
//	d1.print();
//	Stack st(10);
//	//Init  对比 构造函数
//	//destory 对比 析构函数
//
//
//	return 0;
//}


//class Date
//{
//public:
//	Date(int year = 0, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//	//Date copy(d1) 存在无穷递归的问题
//	Date(const Date& d)
//	{
//		_year = d._year;
//		_month = d._month;
//		_day = d._day;
//	}
//
//
//	void print()
//	{
//		cout << _year << "-" << _month << "-" << _day << endl;
//
//	}
//
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//int main()
//{
//	Date d1(2020, 3, 12);
//	Date copy(d1); //同类型的对象做参数来初始化构造函数
//	copy.print();
//
//	return 0;
//}



//class Date
//{
//public:
//	Date(int year = 0, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//	
//
//
//	void print()
//	{
//		cout << _year << "-" << _month << "-" << _day << endl;
//
//	}
//
////private:
//	int _year;
//	int _month;
//	int _day;
//};

//bool CompareLessDate(const Date d1, const Date& d2);
//bool CompareGreatDate(const Date d1, const Date& d2);
//bool CompareEqueDate(const Date d1, const Date& d2)
//{
//	return d1._year == d2._year
//		&& d1._month == d2._month
//		&& d1._day == d2._day;
//}

//bool operator==(const Date d1, const Date& d2);
//
//int main()
//{
//	Date d1(2020, 3, 12);
//	Date d2(2020, 3, 13);
//
//	//如何实现Date之间的一个比较大小
//	//C语言：CompareEqueDate(const Date d1, const Date& d2)
//	//C++:运算符重载
//	cout << operator == (d1, d2) << endl;
//	cout << (d1 == d2) << endl;
//	return 0;
//}


//const成员
//判断依据是传隐含的this过程的核心：
//const Date* ------->const Date*
//Date*       ------->Date*
//const Date* ------->Date* 不可以
//Date*       ------->const Date*
//权限缩小，不能放大

//class Date
//{
//public:
//	//void Print() //Date* this
//	//{
//	//	cout << "Print()" << endl;
//	//	_year = 10;
//	//	cout << "year:" << _year << endl;
//	//	cout << "month:" << _month << endl;
//	//	cout << "day:" << _day << endl;
//	//}
//
//	//const对象和非const对象都可以调用
//	void Print() const //const Date* this -> 这个const作用：在成员函数内保护调用对象不被修改
//	{
//		cout << "Print()" << endl;
//		//_year  = 10; this -> _year = 10
//		cout << "year:" << _year << endl;
//		cout << "month:" << _month << endl;
//		cout << "day:" << _day << endl;
//	}
//
//	void Year()
//	{
//		cout << this->_year << endl;
//		
//	}
//
//	void Month()
//	{
//		cout << this->_month << endl;
//
//	}
//
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//void f1(const Date& d)
//{
//	d.Print();
//}
//
//int main()
//{
//	Date d1;
//	d1.Print();
//
//	f1(d1);
//
//	const Date d2;
//	d2.Print();
//
//	return 0;
//}



//再谈构造函数

//class Date
//{
//public:
//	//初始化列表
//	Date(int year, int month, int day)
//		: _year(year)
//		, _month(month)
//		, _day(day)
//	{}
//
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//class A {
//public:
//	A(int a)
//		:_a(a)
//	{}
//private:
//	int _a;
//};
//
//class B {
//public:
//	//初始化列表是成员变量定义的地方
//	B(int a, int ref)
//		:_aobj(a)
//		, _ref(ref)
//		, _n(10)
//	{}
//private:
//	//这三个成员必须在初始化列表中进行初始化，他们都必须在定义的时候初始化
//	A _aobj; // 没有默认构造函数
//	int& _ref; // 引用
//	const int _n; // const 
//};
//
//int main()
//{
//	
//	return 0;
//}

//int n = 0;
//class A
//{
//public:
//	A()
//	{
//		++n;
//	}
//	A(const A& a)
//	{
//		++n;
//
//	}
//
//	static int GetN() //静态成员函数没有this指针
//	{
//		return n;
//		
//	}
//
//private:
//	static int n; //静态成员变量
//};
//
////为什么不在构造函数初始化，因为n不是属于某个对象，n属于这个类，也属于这个类的所有对象
//int A::n = 0;
//
//int main()
//{
//	A a1;
//	A a2;
//	A a3(a2);
//
//	cout << a1.GetN() << endl;
//
//	return 0;
//}


//C++11的成员初始化的新玩
//class B {
//public:
//	B(int b = 0)
//		:_b(b)
//	{}
//	int _b;
//};
//
//class A {
//public:
//	void Print()
//	{
//		cout << a << endl;
//		cout << b._b << endl;
//		cout << p << endl;
//	}
//private:
//	// 非静态成员变量，可以在成员声明时给缺省值。
//	int a = 10; //这里只是声明，所以这里的10不是初始化，是缺省值
//	B b = 20;
//	int* p = (int*)malloc(4);
//	static int n;
//};
//int A::n = 10;
//int main()
//{
//	A a;
//	a.Print();
//	return 0;
//}


//友元函数

//class Date
//{
//	
//	friend void Print(const Date& d); //友元函数
//	friend ostream& operator<<(ostream& out, const Date& d);
//	friend istream& operator>>(istream& in, Date& d);
//public:
//	Date(int year = 1, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//	//cout << d; 
//	//d.operator<<(cout);
//	//d << cout; 这样用失去了程序的可读性，不符合<<运算符的用法
//	/*void operator<<(ostream& out)
//	{
//		out << _year << "-" << _month << "-" << _day << endl;
//
//	}*/
//	
//
//private:
//	int _year;
//	int _month;
//	int _day;
//
//};
//
//ostream& operator<<(ostream& out,const Date& d)
//{
//	cout << d._year<< "-" << d._month << "-" << d._day;
//	return out;
//
//}
//
//istream& operator>>(istream& in, Date& d)
//{
//	cin >> d._year >> "-" >> d._month >> "-" >> d._day;
//	return in;
//
//}
//
//void Print(const Date& d)
//{
//	cout << d._year << "-" << d._month << "-" << d._day << endl;
//}
//
//int main()
//{
//	Date d1(2020,3,26);
//	Date d2(2020, 3, 27);
//	//d1.operator<<(cout);
//	//d1 << cout;
//	cin >> d1 >> d2;
//	cout << d1;
//	cout << d1 << d2; //两次调用了operator<<,第一次cout<<有一个返回值cout
//	
//	return 0;
//}

