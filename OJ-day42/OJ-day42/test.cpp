#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;

//��kС���� -->����+ȥ��
bool Find(vector<int>& v, int n)
{
	for (int i = 0; i < v.size(); i++)
	{
		if (v[i] == n)
			return true;
	}
	return false;
}

int The_KMinNum()
{
	int n;
	while (cin >> n)
	{
		vector<int> v(n);
		int k;
		for (int i = 0; i < n; i++)
		{
			cin >> v[i];
		}
		cin >> k;
		if (k > n || k==0)
			return 0;
		sort(v.begin(), v.end());//����
		vector<int> tmp;
		tmp.push_back(v[0]);
		for (int i = 0; i < n; i++)
		{//ȥ��
			if (Find(tmp,v[i]))
				continue;
			tmp.push_back(v[i]);

		}
		return tmp[k - 1];

	}

}

int main()
{
	cout << The_KMinNum() << endl;
	return 0;
}


//�������
void Unscramble_Password()
{
	string pas;
	while (getline(cin, pas))
	{
		string tmp = "";
		for (int i = 0; i < pas.size(); i++)
		{
			if (pas[i] <= '9' && pas[i] >= '0')
				tmp += pas[i];
		}
		cout << tmp << endl;
	}

}

int main()
{
	Unscramble_Password();
	return 0;
}