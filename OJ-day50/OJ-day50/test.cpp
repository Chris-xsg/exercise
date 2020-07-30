#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
#include<unordered_set>
using namespace std;

//쳲���������---����
class Solution {
public:
	int Fibonacci(int n) {
		//�ݹ�
		/*if(n == 0){
		return 0;
		}
		if(n == 1 || n == 2)
		return 1;
		return Fibonacci(n-1) +Fibonacci(n-2);
		*/
		//����
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


//�ַ����ָ�--����
//״̬��
//��״̬��ǰ1��2��3��..., n���ַ��ܷ���ݴʵ��еĴʱ��ɹ��ִ�
//F(i) : ǰi���ַ��ܷ���ݴʵ��еĴʱ��ɹ��ִ�
//״̬���ƣ�
//F(i) : true{j <i && F(j) && substr[j + 1, i]���ڴʵ����ҵ�} OR false
//��jС��i�У�ֻҪ���ҵ�һ��F(j)Ϊtrue�����Ҵ�j + 1��i֮����ַ����ڴʵ�
//���ҵ�����F(i)Ϊtrue
//��ʼֵ��
//���ڳ�ʼֵ�޷�ȷ���ģ���������һ��������ʵ������Ŀ�״̬����Ϊ״̬����ʼ
//��״̬��ֵ��Ҫ��֤״̬���ƿ�����ȷ��˳���Ľ��У�����ȡʲôֵ����ͨ����
//�����ӽ�����֤
//F(0) = true
//���ؽ����F(n)
class Solution {
public:
	bool wordBreak(string s, unordered_set<string> &dict) {
		if (s.empty())
			return false;
		if (dict.empty())
			return false;
		vector<bool> can_break(s.size() + 1, false);
		//��ʼ��F[0] = true
		can_break[0] = true;
		for (int i = 1; i <= s.size(); i++)
		{
			for (int j = i - 1; j >= 0; j--)
			{
				//F[i]:true{j<i && F[j] && substr[i+1,i]���ڴʵ����ҵ�} OR false
				//��j+1���ַ�������Ϊj
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

