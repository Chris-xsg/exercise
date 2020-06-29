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

	// 排序+去重
	set<int>::iterator it = s.begin();
	while (it != s.end())
	{
		// *it = 1; // 不能修改
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
	m.insert(pair<int, int>(2, 2)); // pair构造函数，构造一个匿名对象
	m.insert(make_pair(4, 4));      // 函数模板构造一个pair对象

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
	dict.insert(pair<std::string, std::string>("sort", "排序"));
	dict.insert(make_pair("string", "排序"));
	dict.insert(make_pair("left", "左边"));

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
	// 第一种方法
	//string strs[] = { "西瓜", "樱桃", "西瓜", "苹果", "西瓜", "西瓜", "西瓜", "苹果" };
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

	//string strs[] = { "西瓜", "樱桃", "西瓜", "苹果", "西瓜", "西瓜", "西瓜", "苹果" };
	//map<string, int> countMap;
	//for (auto& str : strs)
	//{
	//	// 1.如果水果没在map中，则插入成功
	//	// 2.如果水果已经在map中，插入失败，通过返回值拿到水果所在的节点迭代器，++次数
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

	// 第三种
	string strs[] = { "西瓜", "樱桃", "西瓜", "苹果", "西瓜", "西瓜", "西瓜", "苹果" };
	map<string, int> countMap;
	for (auto& str : strs)
	{
		// 1、如果水果不在map中，则operator[]会插入pair<str, 0>, 返回映射对象(次数)的引用进行了++。
		// 2、如果水边在map中，则operator[]返回水果对应的映射对象(次数)的引用，对它++。
		countMap[str]++;
	}

	countMap["香蕉"];     // 插入
	countMap["香蕉"] = 1; // 修改
	cout << countMap["香蕉"] << endl; // 查找
	countMap["哈密瓜"] = 5;  // 插入+修改

	for (auto& e : countMap)
	{
		cout << e.first << ":" << e.second << endl;
	}

	std::map<std::string, std::string> dict;
	dict.insert(make_pair("sort", "排序"));
	dict["string"];   // 插入（一般不会这样用）
	dict["string"] = "字符串"; // 修改 
	dict["left"] = "左边";    // 插入+修改
}

void test_multi()
{
	// 跟set的区别就是允许键值冗余
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

	// multi_map和map和区别上上面是一样的
	// 附加的是multi_map没有operator[],因为当有多个相同的key是，不知道返回哪个key对应的value
	multimap<string, int> mm;
	mm.insert(make_pair("苹果", 1));
	mm.insert(make_pair("苹果", 1));
	mm.insert(make_pair("苹果", 3));
	mm.insert(make_pair("西瓜", 2));
	mm.insert(make_pair("西瓜", 1));
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
//	// 条件调试
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
//	Value value_field; // 节点中存的值
//};
//
//template <class Key, class Value>
//class rb_tree {
//protected:
//	typedef __rb_tree_node<Value> rb_tree_node;
//protected:
//	rb_tree_node* header;
//}