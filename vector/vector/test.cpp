#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
using namespace std;

//void test_vector()
//{
//	vector<int>v1;
//
//
//}
//
//int main()
//{
//	vector<int> v = { 10, 20, 30, 40 };
//	v[0];
//
//	vector<vector<int>> vv;
//	vv.resize(10);
//	for (size_t i = 0; i < 10; ++i)
//	{
//		vv[i].resize(5);
//	}
//	
//
//	return 0;
//}

//���������������㷨
//1���������洢�������ݵ����ݽṹ
//2������������ָ��һ��ʹ�ã����ʺ��޸����������ݣ�����㷨ʹ��
//3���㷨��ͨ����ʵ��ĳ���߼��ĺ���������������һЩ���������е����ݣ�
//�����㷨��ͨ��������������Щ�����е����ݵġ�


//������ʧЧ
int main()
{
	//vector<int> v = { 1, 2, 3, 4 };
	//vector<int>::iterator it = v.begin();
	////v.reserve(5);//������ʧЧ��reserve����itʧЧ��
	////����취����reserve����it
	////��Ӱ��v�ĵײ㴢�����ݿռ�ӿڶ��ᵼ�µ�����ʧЧ + ������erase������itָ���λ��ֵ��ɾ��
	////reserve��resize��insert/push_back/erase
	//while (it != v.end())
	//{
	//	cout << *it << " ";
	//	++it;
	//}
	//cout << endl;


	//ɾ�������е�ż��
	vector<int> v = { 1, 2, 3, 4, 5, 6, 7 };
	vector<int>::iterator it = v.begin();
	
	while (it != v.end())
	{
		if (*it % 2 == 0)
		{
			//v.erase(it);//vsɾ��it��itʧЧ�ˣ�����PJ STL��鱨��SGI�汾û���м�飬���ᱨ��
			it = v.erase(it);//�������
		}
		else
		{
			++it;
		}
		
	}

	for (auto e : v)
	{
		cout << e << " ";
	}
	cout << endl;


	return 0;
}