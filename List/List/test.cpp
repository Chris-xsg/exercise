#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<list>
using namespace std;


//vector ��̬��������  
//ȱ�ݣ�1��ͷ��ͷɾ���м����ɾ����ҪŲ�����ݣ�Ч�ʵ���O(N),Ҳ����˵ֻ�ʺ�β��
//		2���ռ䲻����Ҫ���ݣ�������Ҫ�������۵ģ��в�С����������

//list ��ͷ˫ѭ����������������Խ��vector��ȱ�ݣ�Ҳ����˵vector��list������������ʽ���ڵ�



void test_list1()
{
	list<int> l1;
	l1.push_back(1);
	l1.push_back(2);
	l1.push_back(3);
	l1.push_back(4);
	
	list<int>copy(l1);
	list<int> l2;
	l2 = l1;

	//������
	list<int>::iterator it1 = l1.begin();
	while (it1 != l1.end())
	{
		cout << *it1 << " ";
		++it1;

	}
	cout << endl;




}

void test_list2()
{
	list<int> l1;
	l1.push_back(1);
	l1.push_back(2);
	l1.push_back(3);
	l1.push_back(4);

	l1.pop_back();

	

	list<int>::iterator it1 = l1.begin();
	for (auto e : l1)
	{
		cout << e << " ";
	}
	cout << endl;
}

int main()
{

	test_list1();
	test_list2();


	return 0;
}