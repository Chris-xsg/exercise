#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<thread>
#include<vector>
#include<windows.h>
#include<memory>
using namespace std;

// ������ģʽ -- �������������������֮һ�� ��װ��Ƴ����ģ���һ�����������װ�Ժ󣬲���¶�����Ľṹ������£�ͳһ�ķ�ʽ�����޸������е����ݡ�

// ������ģʽ -- ���ֵ���һ�ָ���
// ����һЩ���������ģʽ�磺����ģʽ��װ����ģʽ���۲���ģʽ������ģʽ...
// һ����ֻ����ȫ��(������)ֻ��һ��ʵ������
// ʲô������ʹ�ã�����һ����������һ���ڴ�أ������еĶ��߳���Ҫ�ڴ涼Ҫ������ڴ����ȡ����ô����ڴ�ص���Ϳ�����Ƶ���ģʽ��

// ���������������ĳ������ģ�����������ڴ�أ���ô��Ͷ����MemoryPool

namespace lazy_man
{
	// ����ģʽ -- ��һ�λ�ȡ����ʱ���ٴ�������
	class Singleton
	{
	public:
		static Singleton* GetInstance()
		{
			//::Sleep(1000);  ����û����ʱ�����̲߳���ȫ��������2�������߳�ͬʱ�����ж�������

			// ˫���
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

	// 1�����Ҫ�ֶ��ͷŵ������󣬿��Ե���DelInstance
	// 2�������Ҫ�������ʱ�������ͷŵ������󣬿��Լ�����������
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
	// ����ģʽ  һ��ʼ(main����֮ǰ)�ʹ�������
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
	// static��������main����֮ǰ�����ģ����ֻ�����̣߳����Բ������̰߳�ȫ��


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

// �ܽ�Ա�һ�¶���������������
// 1������ģʽ��Ҫ�����̰߳�ȫ���ͷŵ����⣬ʵ����Ը����ӣ�����ģʽ�������������⣬ʵ�ּ�
// 2��������һ��������ģʽ��Ҫʱ�ڳ�ʼ���������󣬲���Ӱ����������������ģʽ���෴�����������׶ξʹ�����ʼ��ʵ�����󣬻ᵼ�³�����������Ӱ�����顣
// 3������ж�������࣬������������ϵ(B����A)��Ҫ��A�����ȴ�����ʼ����B�����ٴ�����ʼ������ô�Ͳ��ܶ�������Ϊ�޷���֤������ʼ��˳����ʱ���������ǾͿ����ֶ����ơ�

// �ܽ�һ�£�ʵ��������ģʽ���Ǹ�ʵ��һЩ



/////////////////////////////////////////////////////////////////////////////
// ����ת��
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
	// ���������pa��ָ���࣬�����������
	// ���pa��ָ�����������ת���ɹ���
	// ���paָ���������ת��ʧ�ܷ���nullptr 
	B* pb = dynamic_cast<B*>(pa);
	//B* pb = (B*)pa;
	if (pb != nullptr)
	{
		cout << "ת���ɹ���paָ���������" << endl;
		pb->_a = 1;
		pb->_b = 2;
	}
	else
	{
		cout << "ת��ʧ�ܣ�paָ�������" << endl;
	}
}

int x10()
{
	int i = 1;
	double d = 8.88;
	i = d; // c����֧��������͵���ʽ����ת�� (������ͣ�Ҳ�����������Ƶ�����)
	cout << i << endl;

	int* p = nullptr;
	p = (int*)i; // c����֧��������͵�ǿ������ת�� (��������ͣ�Ҳ����������ܴ������)
	cout << p << endl;

	// C++ ����C��������������ʽת������ʾת��������C++����C�������ò��淶��C++��淶һ��
	// ��׼C++Ϊ�˼�ǿ����ת���Ŀ����ԣ�����������������ǿ������ת��������
	// static_cast��reinterpret_cast��const_cast��dynamic_cast
	d = static_cast<double>(i);     // ��Ӧc������ʽ����ת�� ��������ͣ�
	p = reinterpret_cast<int*>(i);  // ��Ӧc���Դ󲿷�ǿ������ת������������ͣ�

	volatile const int ci = 10;
	//const int ci = 10;
	int* pi = const_cast<int*>(&ci); // ��Ӧc����ǿ������ת����ȥ��const���Եģ���������ͣ�
	//int* pi = (int*)&ci;
	*pi = 20;
	cout << *pi << endl;
	cout << ci << endl; // �����ӡ��10����Ϊci�洢���ڴ汻���ˣ�����ci���Ž��˼Ĵ���������ȥ�Ĵ�����ȡ������10.�����������ڱ�������const�����ȡ�Ż����Ƶ��¡�
	// ��Ҫ��ֹ������������Ż���ÿ�ζ����ڴ���ȥȡֵ���Ͱ�volatile����

	A a;
	B b;

	// C++�����������Ը�ֵ������Ķ���ָ�롢���ã���������лᷢ����Ƭ�����������
	// �﷨��Ȼ֧�ֵģ����������ת���������Գɹ���

	// ����Ǹ����ָ��������ã����������ָ�룬������̽�����ת������������п����ܳɹ�
	// Ҫ�����������
	// �����Ҫע����ǣ�dynamic_cast����ת��ֻ����Լ̳��еĶ�̬����(�����������麯��)

	// ��Ϊdynamic_cast���ʶ�����ָ����ָ������������������أ�dynamic_cast��ԭ��
	// dynamic_castͨ��ȥ�����Ϸ��洢�ı�ʶ��Ϣ�����ж�ָ����������������
	A* pa = &a;
	f_cast(pa);

	pa = &b;
	f_cast(pa);

	return 0;
}

// �ܽ�һ�£�������������ת�������Ҫ�þ����淶һ�㣬��֪��ת�������ʲôӰ��

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

	// ��ʽת��-> A tmp(1); A a2(tmp)�����Ż���ֱ�ӹ���
	AA aa2 = 1;
	AA aa3 = { 1, 2 }; // C++11
}


