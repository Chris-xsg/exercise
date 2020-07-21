#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<string>
using namespace std;

//ÂæÍÕÃüÃû·¨
void Camel_Naming()
{
	string C;
	while (getline(cin, C))
	{
		string java;
		for (int i = 0; i < C.size(); i++)
		{
			if (C[i] == '_')
			{
				++i;
				java += toupper(C[i]);
			}
			else
				java += C[i];

		}
		cout << java << endl;

	}

}

int main()
{
	Camel_Naming();

	return 0;
}


//µ¥´Êµ¹ÅÅ
int main()
{
	string str;
	while (getline(cin, str))
	{
		vector<string>svec;
		svec.clear();
		string temp = "";
		for (int i = 0; i<str.size(); ++i)
		{
			if (str[i] >= 'a' && str[i] <= 'z' || str[i] >= 'A' && str[i] <= 'Z')
				temp += str[i];
			else
			{
				if (temp.size()>0)
				{
					svec.push_back(temp);
					temp = "";
				}
			}
		}
		if (temp.size()>0)
			svec.push_back(temp);
		for (int i = svec.size() - 1; i>0; --i)
			cout << svec[i] << ' ';
		cout << svec[0] << endl;
	}
	return 0;
}


