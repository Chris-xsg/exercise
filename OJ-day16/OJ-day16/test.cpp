#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<string>
using namespace std;


//计算n个数以内的完全数
int Cls_PerfectNumber_count(int n)
{
	int count = 0;
	if (n <= 0 || n > 500000)
	{
		return -1;
	}
	
	for (int i = 2; i <= n; i++)
	{
		int add = 0;
		for (int j = 1; j <= i / 2; j++)
		{
			
			if (i%j == 0)
			{
				add += j;
			}

		}
		if (add == i)
		{
			count++;
		}
	}
	return count;

}


//扑克牌大小
int main()
{
	string line;
	while (getline(cin, line))
	{
		if (line.find("joker JOKER") != -1)
			cout << "joker JOKER" << endl;
		else
		{
			int dash = line.find('-');
			string car1 = line.substr(0, dash);
			string car2 = line.substr(dash + 1);
			int c1 = count(car1.begin(), car1.end(), ' ');
			int c2 = count(car2.begin(), car2.end(), ' ');
			string first1 = car1.substr(0, car1.find(' '));
			string first2 = car2.substr(0, car2.find(' '));
			string str = "345678910JQKA2jokerJOKER";
			if (c1 == c2)
			{
				if (str.find(first1)>str.find(first2))
					cout << car1 << endl;
				else
					cout << car2 << endl;
			}
			else
			if (c1 == 3)
				cout << car1 << endl;
			else if (c2 == 3)
				cout << car2 << endl;
			else
				cout << "ERROR" << endl;
		}
	}
}



int main()
{
	int n;
	while (cin >> n)
	{
		cout << Cls_PerfectNumber_count(n) << endl;
			
	}
	return 0;
}
