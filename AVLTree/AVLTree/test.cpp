#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>
#include <set>
#include <map>
#include <list>
#include <algorithm>
#include <assert.h>
using namespace std;

// 增 删 查  不支持改(因为底层的搜索树key随便改，树的结构就乱了)
void test_set()
{
	set<int> s;
	s.insert(3);
	s.insert(1);
	s.insert(5);
	s.insert(3);
	s.insert(6);
	s.insert(4);

	// 遍历走的搜索树的中序，所以是有序
	// 排序+去重
	set<int>::iterator it = s.begin();
	while (it != s.end())
	{
		// *it = 2;
		cout << *it << " ";
		++it;
	}
	cout << endl;

	// 有就删，没有就不删
	s.erase(3);
	s.erase(30);
	for (auto e : s)
	{
		cout << e << " ";
	}
	cout << endl;

	set<int>::iterator ret = s.find(40);
	if (ret != s.end())
		s.erase(ret);

	for (auto e : s)
	{
		cout << e << " ";
	}
	cout << endl;
}

// key不允许修改(同set) ，value可以修改
void test_map1()
{
	map<int, double> idmap;
	idmap.insert(pair<int, double>(1, 1.1));
	idmap.insert(pair<int, double>(5, 5.5));
	idmap.insert(pair<int, double>(2, 2.2));

	map<int, double>::iterator it = idmap.begin();
	while (it != idmap.end())
	{
		//cout << (*it).first << ":" << (*it).second << endl;
		cout << it->first << ":" << it->second << endl;
		++it;
	}
	cout << endl;

	string str[] = { "西瓜", "樱桃", "西瓜", "樱桃", "西瓜", "苹果", "西瓜" };
	/*map<string, int> countMap;
	for (auto e : str)
	{
	//map<int, double>::iterator ret = countMap.find(e);
	auto ret = countMap.find(e);
	if (ret != countMap.end())
	{
	ret->second++;
	}
	else
	{
	countMap.insert(pair<string, int>(e, 1));
	}
	}
	*/
	map<string, int> countMap;
	for (auto e : str)
	{
		countMap[e]++; // 大家可以下去思考一下，怎么实现的？我们下节课再讲
	}
	cout << endl;

	for (auto& kv : countMap)
	{
		cout << kv.first << ":" << kv.second << endl;
	}
	cout << endl;
}

void test_map2()
{
	map<int, int> iiMap;
	iiMap.insert(pair<int, int>(1, 1));
	iiMap.insert(pair<int, int>(5, 5));
	iiMap.insert(pair<int, int>(2, 2));
	map<int, int> copy(iiMap);

	//map<int, int>::iterator it = iiMap.begin();
	auto it = iiMap.begin();
	while (it != iiMap.end())
	{
		//cout << (*it).first << ":" << (*it).second << endl;
		cout << it->first << ":" << it->second << endl;
		++it;
	}
	cout << endl;

	iiMap.insert(make_pair(2, 2));

	auto rit = iiMap.rbegin();
	while (rit != iiMap.rend())
	{
		cout << rit->first << ":" << rit->second << endl;
		++rit;
	}
	cout << endl;

	std::list<std::string> list;
	std::map<std::string, std::list<std::string>::iterator>  strIterMap;
	strIterMap.insert(pair<std::string, std::list<std::string>::iterator>("111", list.begin()));
	strIterMap.insert(make_pair("111", list.begin()));

	//std::map<std::string, std::list<std::string>::iterator>::iterator strIterMapIt = strIterMap.begin();
	auto strIterMapIt = strIterMap.begin();
}

void test_map3()
{
	map<int, int> iiMap;
	iiMap.insert(pair<int, int>(1, 1));
	iiMap.insert(pair<int, int>(5, 5));
	iiMap.insert(pair<int, int>(2, 2));
	iiMap.insert(pair<int, int>(3, 3));
	iiMap.insert(pair<int, int>(4, 4));
	iiMap.insert(pair<int, int>(7, 7));
	auto it = iiMap.begin();
	while (it != iiMap.end())
	{
		cout << it->first << ":" << it->second << endl;
		++it;
	}
	cout << endl;

	iiMap.erase(4);
	iiMap.erase(40);
	for (const auto& e : iiMap)
	{
		cout << e.first << ":" << e.second << endl;
	}
	cout << endl;

	struct ComparePairFirst
	{
		bool operator()(const pair<int, int>& pr)
		{
			return pr.first == 50;
		}
	};

	auto ret = iiMap.find(50); // O(logN)
	//auto ret = find_if(iiMap.begin(), iiMap.end(), ComparePairFirst()); // O(N)
	if (ret != iiMap.end())
	{
		iiMap.erase(ret);
	}
	else
	{
		cout << "key不存在" << endl;
	}

	for (const auto& e : iiMap)
	{
		cout << e.first << ":" << e.second << endl;
	}
	cout << endl;
}

void test_map4()
{
	string str[] = { "西瓜", "樱桃", "西瓜", "樱桃", "西瓜", "苹果", "西瓜" };
	map<string, int> countMap;
	// 第一种方法
	//for (auto e : str)
	//{
	//	auto ret = countMap.find(e);
	//	if (ret != countMap.end())
	//		ret->second++;
	//	else
	//		countMap.insert(pair<string, int>(e, 1));
	//}

	// 第二种方法
	/*for (auto e : str)
	{
	pair<map<string, int>::iterator, bool> ret = countMap.insert(make_pair(e, 1));
	if (ret.second == false)
	{
	// ret.first是已经在map的水果所在节点的迭代器
	ret.first->second++;
	}
	}*/

	// 第三种方法
	// mapped_type& operator[] (const key_type& k);
	for (auto e : str)
	{
		countMap[e]++;
	}


	for (auto& kv : countMap)
	{
		cout << kv.first << ":" << kv.second << endl;
	}
	cout << endl;

	map<string, string> dict;
	dict.insert(make_pair("sort", "排序"));
	dict["left"] = "左边"; // 插入+修改
	dict["left"] = "剩余"; // 修改
	dict["string"];		   // 插入
	dict["string"] = "字符串"; // 修改
}

// multi的意思就是允许键值冗余
void test_multi()
{
	multiset<int> ms;
	ms.insert(4);
	ms.insert(1);
	ms.insert(5);
	ms.insert(6);
	ms.insert(2);
	ms.insert(6);
	ms.insert(4);
	ms.insert(6);
	ms.insert(4);
	ms.insert(4);

	multiset<int>::iterator msit = ms.begin();
	while (msit != ms.end())
	{
		cout << *msit << " ";
		++msit;
	}
	cout << endl;

	// 查找的key有多个时，返回第一个(中序的第一个)
	auto pos = ms.find(4);
	while (*pos == 4)
	{
		cout << *pos << endl;
		++pos;
	}
	cout << endl;

	cout << ms.count(6) << endl;

	// multimap没有operator[]
	multimap<string, string> dict;
	dict.insert(make_pair("left", "左边"));
	dict.insert(make_pair("left", "剩余"));
	dict.insert(make_pair("right", "右边"));
	dict.insert(make_pair("insert", "插入"));

	for (auto& e : dict)
	{
		cout << e.first << ":" << e.second << endl;
	}
	cout << endl;

	// 遍历顺序的第一个
}

#include "AVLTree.h"
#include "BSTree.hpp"
#include <vector>
#include <time.h>


void TestTreeOP()
{
	AVLTree<int, int> avlt;
	BSTree<int, int> bst;
	vector<int> v;
	const int n = 1000000;
	srand(time(0));
	v.reserve(n);
	for (size_t i = 0; i < n; ++i)
	{
		v.push_back(i);
	}

	size_t begin1 = clock();
	for (auto e : v)
	{
		avlt.Insert(make_pair(e, e));
		//avlt.Find(e);
	}
	size_t end1 = clock();

	size_t begin2 = clock();
	for (auto e : v)
	{
		bst.Insert(e, e);
		//bst.Find(e);
	}
	size_t end2 = clock();

	cout << "avlt:" << end1 - begin1 << endl;
	cout << "bst:" << end2 - begin2 << endl;
}

int main()
{
	//test_set();
	//test_map();
	//test_map3();
	//test_map4();

	//test_multi();
	//TestAVLTree();
	TestTreeOP();


	return 0;
}