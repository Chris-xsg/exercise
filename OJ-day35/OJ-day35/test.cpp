#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
#include<vector>
using namespace std;

//���齱
//���ӣ�https://www.nowcoder.com/questionTerminal/610e6c0387a0401fb96675f58cda8559
//��Դ��ţ����

//int main(int argc, const char * argv[]) 
//{
//	int n = 0;
//	//fTable[n]��¼n���˶��ô�ȫ���񽱣������������allTable[n]��¼���п��ܵ�������n�Ľ׳�
//	long long fTable[21] = { 0, 0, 1 }, allTable[21] = { 0, 1, 2 };
//	for (int i = 3; i < 21; ++i) 
//	{
//		//���Ƽ���i����ȫ���ô�
//		fTable[i] = (i - 1) * (fTable[i - 1] + fTable[i - 2]);
//		//���Ƽ���i�Ľ׳�
//		allTable[i] = i * allTable[i - 1];
//	}
//	//scanf����ֵΪ��ȷ�������ݵı�����������һ��������û�гɹ���ȡ����ʱ����ʱ����-1
//	while (scanf("%d", &n) != -1) 
//	{
//		//ע��%���ڿ����ַ�������������%%�ű�ʾ������%�ַ�
//		printf("%4.2lf%%\n", 100 * double(fTable[n]) / allTable[n]);
//	}
//	return 0;
//}


//�����б�
int main()
{
	string s_table, s_cus;
	while (getline(cin, s_table))
	{
		getline(cin, s_cus);

		if (s_table[s_table.size() - 1] != '"')//��ֹ���һ������˫�����������Խ����ж�
			s_table.push_back(',');

		string tmp;
		int flag = 0;
		for (int i = 0; i < s_table.size(); i++)
		{
			if (s_table[i] == '"')//��˫����
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
			else//��˫����
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