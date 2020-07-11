#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
#include<vector>
using namespace std;

//年会抽奖
//链接：https://www.nowcoder.com/questionTerminal/610e6c0387a0401fb96675f58cda8559
//来源：牛客网

//int main(int argc, const char * argv[]) 
//{
//	int n = 0;
//	//fTable[n]记录n个人都拿错（全不获奖）的情况种数，allTable[n]记录所有可能的组合情况n的阶乘
//	long long fTable[21] = { 0, 0, 1 }, allTable[21] = { 0, 1, 2 };
//	for (int i = 3; i < 21; ++i) 
//	{
//		//递推计算i个人全部拿错
//		fTable[i] = (i - 1) * (fTable[i - 1] + fTable[i - 2]);
//		//递推计算i的阶乘
//		allTable[i] = i * allTable[i - 1];
//	}
//	//scanf返回值为正确输入数据的变量个数，当一个变量都没有成功获取数据时，此时返回-1
//	while (scanf("%d", &n) != -1) 
//	{
//		//注意%属于控制字符，两个连续的%%才表示真正的%字符
//		printf("%4.2lf%%\n", 100 * double(fTable[n]) / allTable[n]);
//	}
//	return 0;
//}


//抄送列表
int main()
{
	string s_table, s_cus;
	while (getline(cin, s_table))
	{
		getline(cin, s_cus);

		if (s_table[s_table.size() - 1] != '"')//防止最后一个是无双引号人名，以进入判断
			s_table.push_back(',');

		string tmp;
		int flag = 0;
		for (int i = 0; i < s_table.size(); i++)
		{
			if (s_table[i] == '"')//有双引号
			{
				++i;
				while (s_table[i] != '"')
				{
					tmp += s_table[i];
					i++;
				}

				if (tmp == s_cus)
				{
					flag = 1;
					break;
				}
				else
				{
					tmp.clear();
					++i;
					continue;
				}
			}
			else//无双引号
			{
				while (s_table[i] != ',')
				{
					tmp += s_table[i];
					i++;
				}

				if (tmp == s_cus)
				{
					flag = 1;
					break;
				}
				else
				{
					tmp.clear();
					continue;
				}
			}
		}
		if (flag == 0)
			cout << "Important!" << endl;
		else
			cout << "Ignore" << endl;
	}
	return 0;
}