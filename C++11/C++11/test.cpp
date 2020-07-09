#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<list>
#include<string>
#include<map>
#include <initializer_list>
using namespace std;

// �б��ʼ������������Ҫ�ܿ�����ʵ��������õ�Ҳ���ࡣ
// ���˽⣩
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
//	// C++11  �������б��ʼ��
//	vector<int> v1{ 1, 2, 3, 4, 5 };
//	vector<int> v2 = { 1, 2, 3, 4, 5 };
//
//	list<int> l1{ 1, 2, 3, 4, 5 };
//	list<int> l2 = { 1, 2, 3, 4, 5 };
//
//	map<string, int> m1{ { "ƻ��", 1 }, { "����", 2 }, { "�㽶", 3 } };
//	map<string, int> m2 = { { "ƻ��", 1 }, { "����", 2 }, { "�㽶", 3 } };
//
//	Point p1(1, 2);
//	Point p2{ 1, 2 };
//	Point p3 = { 1, 2 };
//
//	auto ilt1 = { 1, 2, 3 };
//	initializer_list<int> ilt2 = { 1, 2, 3 };
//	// ���������֧�����ֻ��������б��ʼ�����أ�
//
//	return 0;
//}

//////////////////////////////////
// �����Ƶ�������RTTI  run time type Identification
// �������������Զ��������ʶ��
// ���˽⣩
//int main()
//{
//	int a = 10;
//	double b = 20;
//	auto c = a + b;
//
//	// �õ��������Ƶ��ַ���
//	cout << typeid(c).name() << endl;
//	string s;
//	cout << typeid(s).name() << endl;
//
//	// �������붨һ����c��sһ�����͵Ķ���
//	// ͨ������ȥ������
//	decltype(c) d;
//	decltype(s) e;
//
//	cout << typeid(d).name() << endl;
//	cout << typeid(e).name() << endl;
//
//	return 0;
//}

// auto�ͷ�Χfor -> ���˲��ִ����д��
// ��Ϥ

// auto�������βκͷ���ֵ
//auto func(auto e)
//{}

//int main()
//{
//	std::map<std::string, std::string> dict = { { "insert", "����" }, { "sort", "����" } };
//	std::map<std::string, std::string>::iterator it1 = dict.begin();
//	auto it2 = dict.begin();
//	// ����it1��it2������Ϊ����ȫһ�����͵Ķ���
//	// Ψһ�����it2�������Ǳ������Զ��Ƶ�����
//	// auto�����ƾ��ǿ��԰������ͱȽϸ��ӵط����򻯴����д��
//
//	// ����Ҫע�⵱���������Ƚϴ󣬻����������Ҫ���������string
//	// ��ø�&��const�����Լ��ٿ������Ч��
//	// ����֧�ַ�Χforԭ����Χfor�ᱻ�������滻�ɵ�������Ҳ������ζ��֧�ֵ�������֧�ַ�Χfor
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
//	// ����STL����������ʹ�÷�Χfor�÷�������Ҳ����(ԭ��ָ�������ΪҲ��Ȼ������������vector/string�ĵ���������ԭ��ָ��)
//	int a[] = { 1, 2, 3, 3, 5, 4 };
//	for (auto e : a)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//
//}

// final��override (�˽�)
// ����һ���������ؼ��ֱַ��������ʲô��
// final�����࣬��ͱ���������࣬���ܱ��̳�
// final�����������麯��������麯�����ܱ���д
// override��������д�麯��������Ƿ������д����������д���������򱨴�

// ����ָ��  ����Ϥ��
// ��������ר�Ż�2�ڿν����

// ������
// C++98����
// string/vector/list/deque/map/set/bitset + stack/queue/priority_queue
// C++11������
// array(��������):ʵ�����õĺ��٣�ȱ�㣺���� + �洢���ݵĿռ���ջ��,ջ�Ŀռ䱾���Ͳ���
// forword_list(������)��ʵ�����õ��٣�ȱ�㣺��֧��β��βɾ + insert����Ҳ���ڵ�ǰλ�õĺ���
// unordered_map/unordered_set : �Ƽ�ʹ�ã���Ϊ���ǵ�Ч�ʸ���map/set

//  Ĭ�ϳ�Ա��������
//class A
//{
//public:
//	A() = default; // ָ����ʾȥ����Ĭ�Ϲ��캯��
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

// Ҫ��A�Ķ����ܿ����͸�ֵ(������)
//class A
//{
//public:
//	A() = default; // ָ����ʾȥ����Ĭ�Ϲ��캯��
//
//	// C++98
//	// ֻ��������ʵ�֣������ͱ��취��(��������)��ȱ�ݣ����˿��������涨��
//	// Ϊ�˽�����ȱ�ݣ�private�޶�
//private:
//	A(const A& aa);
//	A& operator=(const A& aa);
//private:
//	int _a = 10;
//};
//
//// �����涨��
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
//	A() = default; // ָ����ʾȥ����Ĭ�Ϲ��캯��
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
// ��ֵ���ú��ƶ����� ���ص㣩
// C++98����������õĸ�����þ͸�һ������ȡ������
// C++98 ��ֵ����
// C++11 ��ֵ����
// ��������ֵ���ã�������ֵ���ã����Ƕ��Ǹ�����ȡ������
// ������ֵ������Ҫ�Ǹ���ֵȡ��������ֵ������Ҫ�Ǹ���ֵȡ������

// ʲô����ֵ��ʲô����ֵ��
// =��߾�����ֵ���ұߵľ�����ֵ�� ע�������һ��C�﷨�����µĿӣ��������ƺ�����һ����
// �������Ҳ��Ƿ�����ߵ�ֵҲ��һ����ֵ���ұߵ�ֵ��һ������ֵ
// int x1 = 10; int x2 = x1; int x3 = x1+x2; ����x1����ֵ��10����ֵ��x2����ֵ,x1+x2���ʽ����ֵ������ֵ
// �����޸ľͿ�����Ϊ����ֵ����ֵͨ���Ǳ���
// ��ֵͨ���ǳ��������ʽ���ߺ�������ֵ(��ʱ����)

//int main()
//{
//	int x = 1, y = 2;
//	
//	// ��ֵ���õĶ���
//	int a = 0;
//	int& b = a;
//
//	// ��ֵ���ò���������ֵ, const��ֵ���ÿ���
//	//int& e = 10; 
//	//int& f = x + y;
//	const int& e = 10;
//	const int& f = x + y;
//
//
//	// ��ֵ���õĶ���
//	int&& c = 10;
//	int&& d = x + y;
//
//	// ��ֵ���ò���������ֵ�����ǿ�������move����ֵ
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
//	f(x); // �����ƥ����ֵ���ò�����f
//	f(10);// �����ƥ����ֵ���ò�����f
//
//	return 0;
//}

// C++11�ֽ���ֵ����Ϊ������ֵ�ͽ���ֵ
// ����ֵ���������͵ĳ���������ʱ����
// ����ֵ���Զ������͵���ʱ����
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
		cout << "String(const String& s)-���-Ч�ʵ�" << endl;

		_str = new char[strlen(s._str) + 1];
		strcpy(_str, s._str);
	}

	// s3(��ֵ-����ֵ)
	String(String&& s)
		:_str(nullptr)
	{
		// ����������һ������ֵ�������㶼Ҫ���ˣ��ҵ�Ŀ���Ǹ�����һ����Ŀռ䣬һ����ֵ
		// �������Ŀ��ƺ�ֻ����
		cout << "String(String&& s)-�ƶ�����-Ч�ʸ�" << endl;
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
	return tmp; // ���ﷵ��ʵ���ǿ���tmp����ʱ����
}

int main()
{
	String s1("��ֵ");
	String s2(s1);                      // ��������ֵ
	String s3(f("��ֵ-����ֵ"));        // ��������ֵ-����ֵ(���ݸ����ã������Ҿ�������)

	return 0;
}





