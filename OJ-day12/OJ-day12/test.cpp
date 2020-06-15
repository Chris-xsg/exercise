#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
#include<vector>
using namespace std;

//参数解析：
//输入一行命令，参数分隔符为空格，输出参数个数和各个参数
//对于用""包含起来的参数，中间有空格，不能解析为多个参数
void Parameter_Determination()
{
	string str;

	while (getline(cin, str))
	{
		string ret;
		int count = 0;
		char A = '\"'; //保存引号 TMD坑死了
		char B = '\"';
		for (int i = 0; i <= str.size(); i++)
		{
			if (str[i] == A)
			{
				while (str[i] != B)
				{
					str[i++];
				}
				count++;
			}

			else if (str[i] == ' ')
			{
				count++;
			}
			else if (str[i] == '\0')
			{
				count++;
			}
		}
		cout << count << endl;

		for (int i = 0; i <= str.size(); i++)
		{
			if (str[i] == A)
			{
				++i;
				while (str[i] != B)
				{
					ret += str[i];
					i++;
				}

				cout << ret << endl;
				ret = "";

			}

			else if (str[i] == ' ')
			{
				cout << ret << endl;
				ret = "";
			}
			else if (str[i] == '\0')
			{
				cout << ret << endl;
				ret = "";
			}
			else
			{
				ret += str[i];
			}
		}

	}

}


//跳石板：贪心算法
int Springboard(int N,int M)
{
	if (N > M) 
	{
		return -1;
	}
	if (N == M) 
	{
		return 0;
	}
	int res = 0;
	for (int i = 2; i<N; i++) 
	{
		if (i*(N / i) == N) 
		{
			res++;
			if (Springboard(N + N / i, M) != -1) 
			{
				res += Springboard(N + N / i, M);
				return res;
			}
			else 
			{
				res--;
			}
		}
	}
	return -1;


}


int main()
{
	//Parameter_Determination();

	int N, M;
	while (cin >> N >> M)
	{
		cout << Springboard(N, M) << endl;

	}
	
	

	return 0;
}