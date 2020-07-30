#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
#include<unordered_set>
using namespace std;

//斐波那契数列---动归
class Solution {
public:
	int Fibonacci(int n) {
		//递归
		/*if(n == 0){
		return 0;
		}
		if(n == 1 || n == 2)
		return 1;
		return Fibonacci(n-1) +Fibonacci(n-2);
		*/
		//动归
		int *F = new int[n + 1];
		F[0] = 0;
		F[1] = 1;
		for (int i = 2; i <= n; i++)
		{
			F[i] = F[i - 1] + F[i - 2];
		}
		return F[n];


	}
};


//字符串分割--动归
//状态：
//子状态：前1，2，3，..., n个字符能否根据词典中的词被成功分词
//F(i) : 前i个字符能否根据词典中的词被成功分词
//状态递推：
//F(i) : true{j <i && F(j) && substr[j + 1, i]能在词典中找到} OR false
//在j小于i中，只要能找到一个F(j)为true，并且从j + 1到i之间的字符能在词典
//中找到，则F(i)为true
//初始值：
//对于初始值无法确定的，可以引入一个不代表实际意义的空状态，作为状态的起始
//空状态的值需要保证状态递推可以正确且顺利的进行，到底取什么值可以通过简单
//的例子进行验证
//F(0) = true
//返回结果：F(n)
class Solution {
public:
	bool wordBreak(string s, unordered_set<string> &dict) {
		if (s.empty())
			return false;
		if (dict.empty())
			return false;
		vector<bool> can_break(s.size() + 1, false);
		//初始化F[0] = true
		can_break[0] = true;
		for (int i = 1; i <= s.size(); i++)
		{
			for (int j = i - 1; j >= 0; j--)
			{
				//F[i]:true{j<i && F[j] && substr[i+1,i]能在词典中找到} OR false
				//第j+1个字符的索引为j
				if (can_break[j] && dict.find(s.substr(j, i - j)) != dict.end())
				{
					can_break[i] = true;
					break;
				}
			}
		}
		return can_break[s.size()];
	}
};

