#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;


//连续最大和
int main()
{
	int n;
	while (cin >> n)
	{
		vector<int> v(n, 0);
		int sum = 0, max = INT_MIN;
		for (int i = 0; i<n; i++)
		{
			cin >> v[i];
			sum += v[i];
			if (sum > max)
				max = sum;
			if (sum < 0)
				sum = 0;
		}
		cout << max << endl;
	}
	return 0;
}

//删除公共字符
int main()
{
	string A, B;
	while (getline(cin, A) && getline(cin, B))
	{
		for (int i = 0; i<B.size(); i++)
		{
			while (1)
			{
				int found = A.find(B[i]);
				if (found != string::npos)
				{
					A.erase(found, 1);
				}
				if (found == string::npos)
				{
					break;
				}
			}
		}
		cout << A << endl;
	}

	return 0;
}


//24点游戏算法 ->全排列+递归
bool is24(int a[], int begin, int end, double tot)
{
	if (begin == end - 1) return (a[begin] == tot);
	else
	{
		bool ans = false;
		for (int i = begin; i<end; i++)
		{
			swap(a[i], a[end - 1]);
			ans = ans || is24(a, begin, end - 1, tot + a[end - 1]) 
				|| is24(a, begin, end - 1, tot - a[end - 1]) 
				|| is24(a, begin, end - 1, tot * a[end - 1]) 
				|| is24(a, begin, end - 1, tot / a[end - 1]);
			swap(a[i], a[end - 1]);
		}
		return ans;
	}


}

int main()
{
	int a[4];
	while (cin >> a[0] >> a[1] >> a[2] >> a[3])
	{
		if (is24(a, 0, 4, 24)) cout << "true" << endl;
		else cout << "false" << endl;
	}
}
