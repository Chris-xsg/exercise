#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<string>
using namespace std;


//���ѵ�����--������Ĵ�д��ĸת����������λ����ĸeg��A-->F

int main()
{
	string inputLine;
	while (getline(cin, inputLine)) 
	{
		for (int i = (int)inputLine.size() - 1; i >= 0; --i)
		{
			if (inputLine[i] >= 'A' && inputLine[i] <= 'Z')
			{
				//ÿ�����Ķ�Ӧ����������֮��ĵ�21����ĸ
				inputLine[i] = (inputLine[i] - 'A' + 21) % 26 + 'A';
			}
		}
		printf("%s\n", inputLine.c_str());
	}
	return 0;
}


//���ӵĸ���

int main()
{
	int n, k, i;
	while (cin >> n)
	{
		k = 0;
		for (i = 2; i <= sqrt(n); i++)
		if (n%i == 0)
		{
			while (n%i == 0)n = n / i;
			k++;
		}
		if (n != 1)k++;
		cout << k << endl;
	}
	return 0;
}

