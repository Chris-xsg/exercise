#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>
using namespace std;

//class Person
//{
//public:
//	void Print()
//	{
//		cout << "name:" << _name << endl;
//		cout << "age:" << _age << endl;
//	}
//protected:
//	string _name = "peter"; // 姓名
//	int	   _age = 18;		// 年龄
//};
//
//// 继承后父类的Person的成员（成员函数+成员变量）都会变成子类的一部分。这里体现出了Student和Teacher复用了Person的成员。下面我们使用监视窗口查看Student和Teacher对象，可以看到变量的复用。调用Print可以看到成员函数的复用。
//class Student : public Person
//{
//protected:
//	int _stuid; // 学号
//};
//
//class Teacher : public Person
//{
//protected:
//	int _jobid; // 工号
//};
//
//int main()
//{
//	Student s;
//	Teacher t;
//	s.Print();
//	t.Print();
//
//	return 0;
//}

//class Person
//{
//public:
//	void Print()
//	{
//		cout << "name:" << _name << endl;
//		cout << "age:" << _age << endl;
//	}
//protected:
//	string _name = "peter"; // 姓名
//
//private:
//	int	   _age = 18;		// 年龄
//};
//
//struct Student : Person
//{
//public:
//	void f()
//	{
//		_name = "xxx";
//		//_age = 10; 父类的私有继承下来以后不可见
//	}
//protected:
//	int _stuid; // 学号
//};
//
//int main()
//{
//	Student s;
//	s.Print();
//	//s._name;
//
//	return 0;
//}


//class Person
//{
//protected:
//	string _name; // 姓名
//	string _sex;  // 性别
//	int	_age;	 // 年龄
//};
//
//class Student : public Person
//{
//public:
//	int _No; // 学号
//};
//
//void main()
//{
//	Student sobj;
//	// 1.子类对象可以赋值给父类对象/指针/引用
//	Person pobj = sobj;
//	Person* pp = &sobj;
//	Person& rp = sobj;
//
//	pp = &sobj;
//	Student* ps1 = (Student*)pp; // 这种情况转换时可以的。
//	ps1->_No = 10;
//
//	pp = &pobj;
//	Student* ps2 = (Student*)pp; // 这种情况转换时虽然可以，但是会存在越界访问的问题
//	ps2->_No = 10;
//}

//class Person
//{
//protected:
//	string _name = "小李子"; // 姓名
//	int _num = 111; 	   // 身份证号
//};
//
//class Student : public Person
//{
//public:
//	void Print()
//	{
//		cout << " 姓名:" << _name << endl;
//		cout << " 身份证号:" << Person::_num << endl;
//		cout << " 学号:" << _num << endl;
//	}
//protected:
//	int _num = 999; // 学号  子类成员隐藏(重定义)父类的成员
//};
//
//int main()
//{
//	Student s;
//	s.Print();
//
//	return 0;
//}

// 函数重载：同一作用
// 
// 父子类中，同名成员变量构成隐藏，同名函数构成隐藏(参数返回值都可以不同)
//class A
//{
//public:
//	void fun()
//	{
//		cout << "func()" << endl;
//	}
//};
//class B : public A
//{
//public:
//	void fun(int i)
//	{
//		cout << "func(int i)->" << i << endl;
//	}
//};
//
//void main()
//{
//	B b;
//	b.fun(10);
//	b.A::fun();
//};

//class Person
//{
//public:
//	//Person(const char* name = "peter")
//	Person(const char* name)
//		: _name(name)
//	{
//		cout << "Person()" << endl;
//	}
//
//	Person(const Person& p)
//		: _name(p._name)
//	{
//		cout << "Person(const Person& p)" << endl;
//	}
//
//	Person& operator=(const Person& p)
//	{
//		cout << "Person operator=(const Person& p)" << endl;
//		if (this != &p)
//			_name = p._name;
//
//		return *this;
//	}
//
//	~Person()
//	{
//		cout << "~Person()" << endl;
//	}
//protected:
//	string _name; // 姓名
//};
//
//// 派生类几个默认成员函数：构造、析构、拷贝构造、赋值
//class Student : public Person
//{
//public:
//	Student()
//		:Person("xxx")
//	{
//		cout << "Student()" << endl;
//	}
//
//	// s2(s1)
//	Student(const Student& s)
//		:Person(s)
//		, _id(s._id)
//	{
//		cout << "Student(const Student& s)" << endl;
//	}
//
//	// s1 = s3
//	Student& operator=(const Student& s) // 跟父类的operator=构成隐藏
//	{
//		if (this != &s)
//		{
//			Person::operator=(s);
//			_id = s._id;
//		}
//
//		cout << "Student& operator=(const Student& s)" << endl;
//
//		return *this;
//	}
//
//
//	~Student()  // 也跟父类的~Person()构成隐藏，编译器会将析构函数的名称处理成destrucator()
//	{
//		//Person::~Person();  不要显示调用，因为不能保证先调子类析构再调父类析构的顺序
//		// 子类析构函数调用完成够，自动调用父类的
//		cout << "~Student()" << endl;
//	}
//
//protected:
//	int _id;
//};

// C++98
//class A
//{
//private:
//	A()
//	{}
//};
//
//class B : public A
//{
//public:
//	
//};

// C++11
//class A final
//{
//};
//
//class B : public A
//{
//public:
//
//};

//class Person
//{
//public:
//	Person() { ++_count; }
//	int _p; // 姓名
//	static int _count; // 统计人的个数。
//};
//
//int Person::_count = 0;
//class Student : public Person
//{
//public:
//	int _stuNum; // 学号
//	static int _count; // 统计人的个数。
//};
//
//int Student::_count = 0;
//
//
//int main()
//{
//	Person p;
//	p._p = 2;
//	p._count = 1;
//
//
//	Student s;
//	s._p = 3;
//	s._count = 4;
//
//	/*Student s1;
//	Student s2(s1);
//	Student s3;
//	s1 = s3;*/
//
//	//B b;
//
//	return 0;
//}

//class Person
//{
//public:
//	string _name = "xxx"; // 姓名
//};
//class Student : virtual public Person
//{
//protected:
//	int _num; //学号
//};
//class Teacher : virtual public Person
//{
//protected:
//	int _id; // 职工编号
//};
//class Assistant : public Student, public Teacher
//{
//protected:
//	string _majorCourse; // 主修课程
//};
//
//int main()
//{
//	// 这样会有二义性无法明确知道访问的是哪一个
//	Assistant a;
//	a._name = "peter";
//
//	// 需要显示指定访问哪个父类的成员可以解决二义性问题，但是数据冗余问题无法解决
//	a.Student::_name = "xxx";
//	a.Teacher::_name = "yyy";
//
//	return 0;
//}

// 什么是菱形继承？菱形继承的问题？（数据冗余和二义性）如何解决？（虚继承）
// 虚继承是如何解决这个数据冗余和二义性的？
//class A
//{
//public:
//	int _a;
//};
//
//class B : public A
//{
//public:
//	int _b;
//};
//
//class C : public A
//{
//public:
//	int _c;
//};
//
//class D : public B, public C
//{
//public:
//	int _d;
//};
//
//#include<list>
//// 菱形继承，内存模型(在内存中是如何存储的？)
//// 注意监视窗口看到的有时是被编译器处理过的，不一定是实际的，实际中我们要去看内存窗口
////list<int> l;
////l.push_back(1);
////l.push_back(2);
////l.push_back(3);
////l.push_back(4);
//int main()
//{
//	D d;
//	cout << sizeof(d) << endl;
//	d.B::_a = 1;
//	d.C::_a = 2;
//	d._b = 3;
//	d._c = 4;
//	d._d = 5;
//
//	return 0;
//}


//class A
//{
//public:
//	//int _a[1000];
//	int _a;
//};
//
//class B : virtual public A
//{
//public:
//	int _b;
//};
//
//class C : virtual public A
//{
//public:
//	int _c;
//};
//
//class D : public B, public C
//{
//public:
//	int _d;
//};
//
//#include<list>
//// 菱形虚拟继承，内存模型(在内存中是如何存储的？)
//int main()
//{
//	D d;
//	cout << sizeof(d) << endl;
//	d.B::_a = 1;
//	d.C::_a = 2;
//	d._b = 3;
//	d._c = 4;
//	d._d = 5;
//
//	return 0;
//}


class X
{
protected:
	int _x;
};

// 继承 -> 白箱复用  （强关联关系）  is-a关系
class Y : public X
{
protected:
	int _y;
};

class M
{
protected:
	int _m;
};

// 组合 -> 黑箱复用 （弱关联关系）  has-a关系
class N
{
protected:
	M _mm;
	int _n;
};

// 两个类的关系更符合is-a就用继承
// 两个类的关系更符合has-a就用组合
// 都可以，优先使用组合 

////////////////////////////////////////////////////////////////////////////////////////////


// 虚函数是实现多态的条件之一
//class Person {
//public:
//	// 虚函数重写的协变：返回值可以不同，但是必须是父类关系的指针或者引用
//	virtual Person BuyTicket() { cout << "Person 买票-全价" << endl; return this; }
//};
//
//// Student的虚函数的函数名、参数、返回值跟Perosn中的虚函数都相同，Student的虚函数重写了Person中的虚函数
//class Student : public Person {
//public:
//	virtual Student* BuyTicket() { cout << "Student 买票-半价" << endl; return this; }
//};

//class A
//{};
//
//class B : public A
//{};
//
//class Person {
//public:
//	// 虚函数重写的协变
//	virtual A* BuyTicket() { cout << "Person 买票-全价" << endl; return nullptr; }
//};
//
//// Student的虚函数的函数名、参数、返回值跟Perosn中的虚函数都相同，Student的虚函数重写了Person中的虚函数
//class Student : public Person {
//public:
//	virtual B* BuyTicket() { cout << "Student 买票-半价" << endl; return nullptr; }
//};
//
//
//// 达到多态的条件：
//// 1.虚函数的重写。(子类的虚函数和父类的虚函数的函数名、参数、返回值都相同(协变)，才满足重写)
//// 2.父类的指针/引用去调用虚函数
//// 多态：去完成某一行为，不同的对象去完成，效果是不一样的。
//
//// 虚函数重写例外：
//// 1、协变（返回值是父子类关系的指针或引用）
//// 2、子类的虚函数可以不加virtual
//// 3、析构函数名看起来不相同，但是构成重写（实际是被处理成了destrucator）
//
////void Func(Person* ptr)
////{
////	ptr->BuyTicket();
////}
//
//// 
//// 不满足多态，调用谁的函数->看类型
//// 满足多态，调用谁的函数->看指向的对象
//void Func(Person& rp)
//{
//	rp.BuyTicket();
//}
//
//int main()
//{
//	Person p;
//	Student s;
//	Func(p);
//	Func(s);
//
//	return 0;
//}

class Person
{
public:
	virtual ~Person() // 析构函数的名称destructor
	{
		cout << "~Person()" << endl;
	}
};

class Student : public Person
{
public:
	virtual ~Student()  // 析构函数的名称destructor
	{
		cout << "~Student()" << endl;
	}
};

int main()
{
	//Person p;
	//Student s;
	Person* p1 = new Student;
	delete p1;

	Person* p2 = new Person;
	delete p2;

	// p->destructor()
	// free(p)

	return 0;
}