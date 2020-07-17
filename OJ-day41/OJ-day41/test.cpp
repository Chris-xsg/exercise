#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<stack>
#include<string>
using namespace std;

//������--���ж��Ƿ���������
bool Five(vector<vector<char>> v)
{
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			if (v[i][j] == '.')
			{
				continue;
			}
			//�ĸ������ң��£����£�����
			int right = 1, down = 1, right_down = 1, left_down = 1;
			for (int k = 1; k < 5; k++)
			{//�ĸ������������ĸ�
				if (j < 16 && v[i][j] == v[i][j + k])
					right++;//���ұߺ����Ƿ������
				if (j < 16 && v[i][j] == v[i+k][j])
					down++;//���±��������Ƿ������
				if (j < 16 && v[i][j] == v[i+k][j + k])
					right_down++;//�����±�б���Ƿ������
				if (j < 16 && v[i][j] == v[i+k][j - k])
					left_down++;//���ұߺ����Ƿ������
			}
			if (right == 5 || down == 5 || right_down == 5 || left_down == 5)
				return true;
		}

	}
	return false;
}

bool In(vector<vector<char>> v)
{
	char c;
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			cin >> c;
			v[i][j] = c;
		}
	}
	return true;
}

int main()
{
	vector<vector<char>> v(20, vector<char>(20));

	while (In(v))
	{
		cout << (Five(v) ? "Yes" : "No") << endl;
	}

	return 0;
}

//Emacs ������ --����׺���ʽ�ļ���-->ջ
int main()
{
	stack<int> s1;
	int n;
	while (cin >> n)
	{
		for (int i = 0; i<n; i++)
		{
			string s;
			cin >> s;
			if (s[0] >= '0'&&s[0] <= '9')
			{
				int num = 0;
				for (int i = 0; i<s.length(); i++)
					num = num * 10 + s[i] - '0';
				s1.push(num);
			}
			else
			{
				int x = s1.top(); s1.pop();
				int y = s1.top(); s1.pop();
				if (s == "+")       s1.push(x + y);
				else if (s == "-")  s1.push(y - x);
				else if (s == "*")  s1.push(x*y);
				else if (s == "/")  s1.push(y / x);
			}
		}
		cout << s1.top() << endl;
	}
	return 0;
}
