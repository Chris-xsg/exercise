#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
#include<set>
#include<vector>
using namespace std;


//求和  ---》递归
void ADD(int n, int m, vector<int>& v, int beg) 
{
	if (m == 0) 
	{
		for (int i = 0; i<v.size(); i++) 
		{
			i == 0 ? cout << v[i] : cout << " " << v[i];
		}
		cout << endl;
	}
	for (int i = beg; i <= n&&i <= m; i++) 
	{
		v.push_back(i);
		ADD(n, m - i, v, i + 1);
		v.pop_back();
	}
}
int main() 
{
	int n, m;
	while (cin >> n >> m) 
	{
		vector<int>v;
		ADD(n, m, v, 1);
	}
}


//电话号码--》set
int main()
{
	int n;
	string mapper[2] = { "ABCDEFGHIJKLMNOPQRSTUVWXYZ",
		"22233344455566677778889999" };
	while (cin >> n && n)
	{
		string str, temp;
		set<string, less<string> > list;
		for (int i = 0; i < n; ++i)
		{
			cin >> str; temp = "";
			for (char ch : str)
			{
				if (ch != '-' && isalpha(ch))
					temp += mapper[1][toupper(ch) - 'A'];
				else if (ch != '-' && isalnum(ch))
					temp += ch;
			}
			temp.insert(temp.begin() + 3, '-');
			list.insert(temp);
		}
		for (string str : list) cout << str << endl;
		cout << endl;
	}
	return 0;
}



