#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;


//int main()
//{
//	//1��int
//	int* p1 = (int*)malloc(sizeof(int)); //c
//	int* p2 = new int;                   //c++
//	free(p1);
//	p1 = nullptr;
//	p2 = nullptr;
//	delete p2;
//
//	//10��int������
//	int* p3 = (int*)malloc(sizeof(int)* 10);
//	int* p4 = new int[10];
//	free(p3);
//	delete[] p4;
//
//	//����һ��int���󣬲��ҳ�ʼ����10
//	int* p5 = new int(10);
//	delete p5;
//
//	return 0;
//}

//new/delete ��malloc/free����������new/delete���ڡ��Զ������͡����˿��ռ仹����ù��캯������������
//����������һ����

//class A
//{
//public:
//	/*struct ListNode
//	{
//		ListNode* _next;
//		ListNode* _prev;
//		int _val;
//	};*/
//
//	ListNode(int val)
//		:_next(nullptr)
//		: _prev(nullptr)
//		: _val(val)
//
//
//};
//struct ListNode
//{
//	ListNode* _next;
//	ListNode* _prev;
//	int _val;
//};
//
//
//
//ListNode* BuyListNode(int val)
//{
//
//}
//
//int main()
//{
//	ListNode* cur_cpp = new ListNode(1);
//
//	return 0;
//}


//new��delete�ĵײ����ʵ��
//int main()
//{
	//1.operator new ��malloc�����Կ��ռ䣬�÷�Ҳ����
	//2.������ʧ�����Ժ�malloc����nullptr��operator new���쳣
	//3.����operator new�ײ��Ƿ�װmallocʵ���ˣ�ֻ�Ǵ�����ʧ���Ժ����쳣
	//newʧ����Ҳ�����쳣 -�� ������������ʧ���˻����϶�ʹ�����쳣�ķ�ʽ����
	//new���ʵ��  operator new + ���캯��
	//delete���ʵ�� �������� + operator delete	


	//return 0;
//}


int main()
{
	void* p1 = malloc(1024 * 1024 * 1024 * 1);
	void* p2 = malloc(1024 * 1024 * 1024 * 2);
	void* p4 = malloc(1024 * 1024 * 1024 * 4);

	return 0;
}









