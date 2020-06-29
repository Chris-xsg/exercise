#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <set>
#include <map>
#include <string>
using namespace std;

void test_set1()
{
	set<int> s;
	s.insert(3);
	s.insert(1);
	s.insert(4);
	s.insert(3);
	s.insert(7);

	// ����+ȥ��
	set<int>::iterator it = s.begin();
	while (it != s.end())
	{
		// *it = 1; // �����޸�
		cout << *it << " ";
		++it;
	}
	cout << endl;

	for (auto e : s)
	{
		cout << e << " ";
	}
	cout << endl;

	set<int> copy(s);
	for (auto e : copy)
	{
		cout << e << " ";
	}
	cout << endl;

	set<int>::iterator pos = s.find(30); // O(logN)
	//set<int>::iterator pos = find(s.begin(), s.end(), 3); // O(N)
	if (pos != s.end())
	{
		s.erase(pos);
	}

	s.erase(4);
	s.erase(40);

	for (auto e : s)
	{
		cout << e << " ";
	}
	cout << endl;
}

void test_map1()
{
	map<int, int> m;
	m.insert(pair<int, int>(1, 1));
	m.insert(pair<int, int>(3, 3));
	m.insert(pair<int, int>(2, 2)); // pair���캯��������һ����������
	m.insert(make_pair(4, 4));      // ����ģ�幹��һ��pair����

	map<int, int>::iterator it = m.begin();
	while (it != m.end())
	{
		//cout << (*it).first << ":" << (*it).second << endl;
		cout << it->first << ":" << it->second << endl;
		++it;
	}
	cout << endl;

	for (auto& e : m)
	{
		cout << e.first << ":" << e.second << endl;
	}
}

void test_map2()
{
	std::map<std::string, std::string> dict;
	dict.insert(pair<std::string, std::string>("sort", "����"));
	dict.insert(make_pair("string", "����"));
	dict.insert(make_pair("left", "���"));

	std::map<std::string, std::string>::iterator it = dict.begin();
	while (it != dict.end())
	{
		cout << it->first << ":" << it->second << endl;
		++it;
	}
	cout << endl;

}

void test_map3()
{
	// ��һ�ַ���
	//string strs[] = { "����", "ӣ��", "����", "ƻ��", "����", "����", "����", "ƻ��" };
	//map<string, int> countMap;
	//for (auto& str : strs)
	//{
	//	map<string, int>::iterator ret = countMap.find(str);
	//	if (ret != countMap.end())
	//	{
	//		//(*ret).second++;
	//		ret->second++;
	//	}
	//	else
	//	{
	//		countMap.insert(make_pair(str, 1));
	//	}
	//}

	//for (auto& e : countMap)
	//{
	//	cout << e.first << ":" << e.second << endl;
	//}

	//string strs[] = { "����", "ӣ��", "����", "ƻ��", "����", "����", "����", "ƻ��" };
	//map<string, int> countMap;
	//for (auto& str : strs)
	//{
	//	// 1.���ˮ��û��map�У������ɹ�
	//	// 2.���ˮ���Ѿ���map�У�����ʧ�ܣ�ͨ������ֵ�õ�ˮ�����ڵĽڵ��������++����
	//	pair<map<string, int>::iterator, bool> ret = countMap.insert(make_pair(str, 1));
	//	if (ret.second == false)
	//	{
	//		ret.first->second++;
	//	}
	//}

	//for (auto& e : countMap)
	//{
	//	cout << e.first << ":" << e.second << endl;
	//}

	/*mapped_type& operator[] (const key_type& k)
	{
	return (*((this->insert(make_pair(k, mapped_type()))).first)).second;
	}*/

	// ������
	string strs[] = { "����", "ӣ��", "����", "ƻ��", "����", "����", "����", "ƻ��" };
	map<string, int> countMap;
	for (auto& str : strs)
	{
		// 1�����ˮ������map�У���operator[]�����pair<str, 0>, ����ӳ�����(����)�����ý�����++��
		// 2�����ˮ����map�У���operator[]����ˮ����Ӧ��ӳ�����(����)�����ã�����++��
		countMap[str]++;
	}

	countMap["�㽶"];     // ����
	countMap["�㽶"] = 1; // �޸�
	cout << countMap["�㽶"] << endl; // ����
	countMap["���ܹ�"] = 5;  // ����+�޸�

	for (auto& e : countMap)
	{
		cout << e.first << ":" << e.second << endl;
	}

	std::map<std::string, std::string> dict;
	dict.insert(make_pair("sort", "����"));
	dict["string"];   // ���루һ�㲻�������ã�
	dict["string"] = "�ַ���"; // �޸� 
	dict["left"] = "���";    // ����+�޸�
}

void test_multi()
{
	// ��set��������������ֵ����
	multiset<int> ms;
	ms.insert(3);
	ms.insert(2);
	ms.insert(3);
	ms.insert(1);
	ms.insert(4);
	ms.insert(5);
	ms.insert(3);

	for (auto e : ms)
	{
		cout << e << " ";
	}
	cout << endl;

	auto pos = ms.find(3);
	cout << *pos << endl;
	++pos;
	cout << *pos << endl;
	++pos;
	cout << *pos << endl;
	++pos;
	cout << *pos << endl;


	set<int> s;
	s.insert(3);
	s.insert(2);
	s.insert(3);
	s.insert(1);
	s.insert(4);
	s.insert(5);

	for (auto e : s)
	{
		cout << e << " ";
	}
	cout << endl;

	// multi_map��map��������������һ����
	// ���ӵ���multi_mapû��operator[],��Ϊ���ж����ͬ��key�ǣ���֪�������ĸ�key��Ӧ��value
	multimap<string, int> mm;
	mm.insert(make_pair("ƻ��", 1));
	mm.insert(make_pair("ƻ��", 1));
	mm.insert(make_pair("ƻ��", 3));
	mm.insert(make_pair("����", 2));
	mm.insert(make_pair("����", 1));
}

#include "AVLTree.h"
#include "RBTree.h"
#include <vector>
#include <time.h>

//void TestRB_AVLTree()
//{
//	const int n = 1000000;
//	vector<int> v;
//	v.reserve(n);
//	srand(time(0));
//	for (size_t i = 0; i < n; ++i)
//	{
//		v.push_back(i);
//	}
//
//	RBTree<int, int> rbtree;
//	AVLTree<int, int> avltree;
//
//	size_t begin1 = clock();
//	for (auto e : v)
//	{
//		rbtree.Insert(make_pair(e, e));
//	}
//	size_t end1 = clock();
//
//	cout << "rbtree:" << end1 - begin1 << endl;
//
//	// ��������
//	size_t begin2 = clock();
//	for (auto e : v)
//	{
//		avltree.Insert(make_pair(e, e));
//	}
//	size_t end2 = clock();
//	cout << "avltree:" << end2 - begin2 << endl;
//}

#include "MyMap.h"
#include "MySet.h"

int main()
{
	//test_set1();
	//test_map2();
	//test_map3();
	//test_multi();
	//TestAVLTree();
	//TestRBTree();
	//TestRB_AVLTree();
	bit::test_map();
	bit::test_set();

	return 0;
}

//template <class Key, class T>
//class map {
//	typedef Key key_type;
//	typedef pair<const Key, T> value_type;
//private:
//	typedef rb_tree<key_type, value_type> rep_type;
//	rep_type t;  // red-black tree representing map
//}
//
//template <class Key>
//class set {
//	typedef Key key_type;
//	typedef Key value_type;
//private:
//	typedef rb_tree<key_type, value_type> rep_type;
//	rep_type t;  // red-black tree representing set
//}
//
//
//template <class Value>
//struct __rb_tree_node : public __rb_tree_node_base
//{
//	Value value_field; // �ڵ��д��ֵ
//};
//
//template <class Key, class Value>
//class rb_tree {
//protected:
//	typedef __rb_tree_node<Value> rb_tree_node;
//protected:
//	rb_tree_node* header;
//}