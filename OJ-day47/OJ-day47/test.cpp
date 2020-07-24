#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

//合唱团 -》动态规划
int main()
{
	int n;
	while (cin >> n)
	{
		vector<int> a(n);
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
		}
		int k, d;
		cin >> k >> d;
		vector<vector<long long>> dp_max(n, vector<long long>(k + 1, 0));
		vector<vector<long long>> dp_min(n, vector<long long>(k + 1, 0));
		for (int i = 0; i < n; i++)
		{
			dp_max[i][1] = a[i];
			dp_min[i][1] = a[i];
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = 2; j <= k; j++)
			{
				for (int m = max(0, i - d); m <= i - 1; m++){
					dp_max[i][j] = max(dp_max[i][j], max(dp_max[m][j - 1] * a[i], dp_min[m][j - 1] * a[i]));
					dp_min[i][j] = min(dp_min[i][j], min(dp_min[m][j - 1] * a[i], dp_max[m][j - 1] * a[i]));
				}
			}
		}
		long long max_value = dp_max[k - 1][k];
		for (int i = k; i < n; i++)
		{
			max_value = max(max_value, dp_max[i][k]);
		}
		cout << max_value << endl;
	}
	return 0;
}

//马戏团-》动态规划，最长上升子序列
struct players
{
	int w;//体重
	int h;//身高
};
bool Com_w(players p1, players p2)
{
	//按体重从小到大进行排序
	if (p1.w != p2.w)
		return p1.w <= p2.w;
	else//体重相等，身高高的在上
		return p1.h > p2.h;
}

int main()
{
	int N, h, w, id;
	vector<players> v;
	while (cin >> N)
	{
		v.clear();
		for (int i = 0; i < N; i++)
		{
			players tmp;
			cin >> id >> w >> h;//用不上id,就不用了存了
			tmp.w = w;
			tmp.h = h;
			v.push_back(tmp);
		}
		sort(v.begin(), v.end(), Com_w);//按照体重排序
		//按照身高求最大上升子序列
		int dp[N + 1];
		int max = 0;
		dp[0] = 1;
		for (int i = 1; i < N; i++)
		{
			dp[i] = 1;
			for (int j = 0; j < i; j++)
			{
				if (v[j].h <= v[i].h && dp[j] + 1 > dp[i])
					dp[i] = dp[j] + 1;
			}
		}
		for (int i = 0; i < N; i++)
		{
			if (max < dp[i])
			{
				max = dp[i];
			}
		}
		cout << max << endl;



	}

	return 0;
}