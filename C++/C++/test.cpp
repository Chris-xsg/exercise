#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<iostream>
#include<stdbool.h>
using namespace std; // std C++��׼��������ռ�

//�����ռ�
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
//	printf("%d\n", bit::printf);//���ֳ�ͻ
//	printf("%d\n", bit::N1::b);
//	return 0;
//}




//int main()
//{
//	int a = 1;
//	double b = 1.1;
//	//	CҪָ����ʽ���
//	printf("%d %f\n", a, b);
//	//C++ֱ�����
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


//ȱʡ����
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
//ȫȱʡ
//��ȱʡ(����ȱʡ)�������Ǵ������������ģ����ٴ�һ��

//����
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
//	//int& ra;���ñ����ʼ��
//
//	int x = 1;
//	c = x;//��x��ֵ��ֵ����c��������c�����x�ı���
//
//
//	return 0;
//}

//int main()
//{
//	const int a = 10;
//	//Ȩ�޷Ŵ� ֻ�� -> �ɶ���д
//	//int& b = a;  �޷����� a�Լ��޷��ı䣬b�Ǳ���Ҳ���ܸı�
//	const int& b = a;
//
//	int c = 20;
//	int& d = c;
//	//Ȩ����С �ɶ���д -> ֻ�� 
//	const int& e = c;//�������� c�Լ����Ըı䣬eֻ�ܶ������ܸı��ǿ��Ե�
//	
//
//	return 0;
//}

//int main()
//{
//
//	int i = 0;
//	double d = i; //��ʽ���͵�ת��
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
//	//�޲κ����������޷���ȫȱʡ�������������캯������
//
//	//Date d1(2020, 3, 12); ���캯��
//	//Date(int year, int month, int day)
//	//{
//	//	_year = year;
//	//	_month = month;
//	//	_day = day;
//	//}
//
//	////Date d2;
//	////�������캯�����ɺ�������
//	//Date()
//	//{
//	//	_year = 1900;
//	//	_month = 1;
//	//	_day = 1;
//	//}
//
//	//ȫȱʡ�Ĺ��캯�� �Ƽ���д��
//	/*Date(int year = 0, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}*/
//
//	//û��д���캯����������������һ��Ĭ�ϵĹ��캯��
//	//c++�в��ô�����ȥ���õĹ��캯������Ĭ�Ϲ��캯�� -> �޲ι��캯�� ȫȱʡ���캯��
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
////	Date d; //��ʼ��
////	d.print(); //��û�г�ʼ���Ϳ�ʼ����
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
////	//����������ͳ�ʼ��-�����캯��
////	Date d1(2020, 3, 12);
////	d1.print();
////
////	//Date d2(); ����d2 û�б��������
////	Date d2; 
////	d2.print();
////
////	Date d3;
////	d3.Init(2020, 3, 14);//���캯��ֻ���ڶ������ʱ��ʹ��һ��,������Ҫ�޸�ֻ��ʹ��Init
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
//		//Date��û����Դ��Ҫ������������������ʲô������д
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
//	//Date��д������û���⣬�������ɾ�Ҳ����
//	//Stack��д�����������⣬�ڴ�й¶
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
//	Date d1; //�����������������d1�������٣�d1����������ϵͳ��ɡ�����������ɵ���������
//	d1.print();
//	Stack st(10);
//	//Init  �Ա� ���캯��
//	//destory �Ա� ��������
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
//	//Date copy(d1) ��������ݹ������
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
//	Date copy(d1); //ͬ���͵Ķ�������������ʼ�����캯��
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
//	//���ʵ��Date֮���һ���Ƚϴ�С
//	//C���ԣ�CompareEqueDate(const Date d1, const Date& d2)
//	//C++:���������
//	cout << operator == (d1, d2) << endl;
//	cout << (d1 == d2) << endl;
//	return 0;
//}


//const��Ա
//�ж������Ǵ�������this���̵ĺ��ģ�
//const Date* ------->const Date*
//Date*       ------->Date*
//const Date* ------->Date* ������
//Date*       ------->const Date*
//Ȩ����С�����ܷŴ�

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
//	//const����ͷ�const���󶼿��Ե���
//	void Print() const //const Date* this -> ���const���ã��ڳ�Ա�����ڱ������ö��󲻱��޸�
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



//��̸���캯��

//class Date
//{
//public:
//	//��ʼ���б�
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
//	//��ʼ���б��ǳ�Ա��������ĵط�
//	B(int a, int ref)
//		:_aobj(a)
//		, _ref(ref)
//		, _n(10)
//	{}
//private:
//	//��������Ա�����ڳ�ʼ���б��н��г�ʼ�������Ƕ������ڶ����ʱ���ʼ��
//	A _aobj; // û��Ĭ�Ϲ��캯��
//	int& _ref; // ����
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
//	static int GetN() //��̬��Ա����û��thisָ��
//	{
//		return n;
//		
//	}
//
//private:
//	static int n; //��̬��Ա����
//};
//
////Ϊʲô���ڹ��캯����ʼ������Ϊn��������ĳ������n��������࣬Ҳ�������������ж���
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


//C++11�ĳ�Ա��ʼ��������
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
//	// �Ǿ�̬��Ա�����������ڳ�Ա����ʱ��ȱʡֵ��
//	int a = 10; //����ֻ�����������������10���ǳ�ʼ������ȱʡֵ
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


//��Ԫ����

//class Date
//{
//	
//	friend void Print(const Date& d); //��Ԫ����
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
//	//d << cout; ������ʧȥ�˳���Ŀɶ��ԣ�������<<��������÷�
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
//	cout << d1 << d2; //���ε�����operator<<,��һ��cout<<��һ������ֵcout
//	
//	return 0;
//}

