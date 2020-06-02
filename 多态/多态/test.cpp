#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
//
//class Person {
//public:
//	virtual void BuyTicket() { cout << "��Ʊ-ȫ��" << endl; }
//};
//
//class Student : public Person {
//public:
//	virtual void BuyTicket() { cout << "��Ʊ-���" << endl; }
//};
//
//// 1.���ɶ�̬��ָ��������ã�ָ��˭����˭���麯���� ��ָ���������ָ��Ķ���
//// 2.�����ɶ�̬��ָ��������ã�������˭�ĵ��þ���˭����ָ��������õ�����
//
//class A
//{
//public:
//	~A(){cout << "~A()" << endl;}
//};
//
//class B : public A
//{
//public:
//	~B(){cout << "~B()" << endl;}
//};
//
//class Car
//{
//public:
//	void Drive() {}
//};
//
//class Benz :public Car
//{
//public:
//	virtual void Drive()  override { cout << "Benz-����" << endl; }
//};
//
//int main()
//{
//	A* p1 = new A;
//	delete p1;
//
//	A* p2 = new B;
//	delete p2;
//
//	/*Student s;
//	Person  p;
//	Person* ptr = &s;
//	ptr->BuyTicket();
//	ptr = &p;
//	ptr->BuyTicket();*/
//
//
//
//	return 0;
//}

//class Car
//{
//public:
//	virtual void Drive() = 0; // ���麯��
//};
//
//// �������麯��������������ࣨҲ�нӿ��ࣩ�������಻��ʵ����������
//class BYD : public Car
//{
//	virtual void Drive()
//	{}
//};
//
//class BMW : public Car
//{
//	virtual void Drive()
//	{}
//};
//
//int main()
//{
//	//Car c;
//	BYD byd1;
//	BYD byd2;
//
//	BMW bmw1;
//	BMW bmw2;
//
//	return 0;
//}

///////////////////////////////////////////////////////////////////////////////////////////
// ԭ��
//class Base
//{
//public:
//	virtual void Func1()
//	{
//		cout << "Func1()" << endl;
//	}
//
//	virtual void Func2()
//	{
//		cout << "Func2()" << endl;
//	}
//
//private:
//	int _b = 1;
//	char _c = 'a';
//};
//
//int main()
//{
//	cout << sizeof(Base) << endl;
//	Base b1;
//	Base b2;
//
//	return 0;
//}


//class Person {
//public:
//	virtual void BuyTicket() { cout << "Person::BuyTicket()->��Ʊ-ȫ��" << endl; }
//	int _a = 1;
//};
//
//class Student : public Person {
//public:
//	virtual void BuyTicket() { cout << "Person::Student()->��Ʊ-���" << endl; }
//	int _b = 2;
//};
//
//int main()
//{
//	Person p;
//	Student s;
//
//	Person* ptr = &p;
//	ptr->BuyTicket();
//
//	ptr = &s;
//	ptr->BuyTicket();
//
//	return 0;
//}


class Base
{
public:
	virtual void Func1()
	{
		cout << "Base::Func1()" << endl;
	}

	virtual void Func2()
	{
		cout << "Base::Func2()" << endl;
	}

	void Func3()
	{
		cout << "Base::Func3()" << endl;
	}

private:
	int _b = 1;
};

class Derive : public Base
{
public:
	virtual void Func1()
	{
		cout << "Derive::Func1()" << endl;
	}

	virtual void Func4()
	{
		cout << "Derive::Func4()" << endl;
	}
private:
	int _d = 2;
};

typedef void(*V_FUNC)();


//int main()
//{
//	Base b;
//	Derive d;
//
//	V_FUNC* vftptr_d = (V_FUNC*)(*((int*)&d));
//	cout << vftptr_d << endl;
//
//	V_FUNC* vftptr_b = (V_FUNC*)(*((int*)&b));
//	cout << vftptr_b << endl;
//
//	return 0;
//}

//typedef void(*V_FUNC)();
//typedef int INT;
//
//void func()
//{
//	cout << "func()" << endl;
//}
//
//int main()
//{
//	INT i;
//	//void(*p)();  // ����ָ�붨��ܹ֣��������
//	V_FUNC p;      // ��������ϲ������ȥ����
//	p = func; // ���������ָ�� ָ��func
//	p();
//	(*p)();
//
//	return 0;
//}



typedef void(*V_FUNC)();

//int a[10];
//int* p = a;

// V_FUNC table[10];
// V_FUNC* p = table;
void PrintVFTable(V_FUNC* p)
{
	for (int i = 0; p[i] != 0; ++i)
	{
		printf("vtable[%d]:%p->", i, p[i]);
		V_FUNC f = p[i];
		f();
	}
}

int main()
{
	Derive d;
	Derive* ptr = &d;
	//PrintVFTable((V_FUNC*)(*(int*)ptr));
	PrintVFTable((V_FUNC*)ptr);
}