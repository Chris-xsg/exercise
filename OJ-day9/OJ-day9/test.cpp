#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
using namespace std;


//另类加法：不使用+或其他算数运算符
class UnusualAdd {
public:
	int addAB(int A, int B) {
		// write code here
		if (A == 0)
			return B;
		else if (B == 0)
			return A;
		else//按位异或和按位与表示加法
			return addAB(A^B, (A&B) << 1);
	}
};






//计算n*m的棋盘格子从左上角到右下角总共有多少种走法，不能走回头路

//1、递归
int func(int m, int n) {
	if (m == 0 || n == 0) {
		return 1;
	}
	return func(m, n - 1) + func(m - 1, n);
}
int main() {
	int m, n;
	while (cin >> m >> n) {
		cout << func(m, n) << endl;
	}

	return 0;
}



//动态规划
int main() {
	int m, n;
	while (cin >> m >> n) {
		vector<vector<int> > dp(n + 1, vector<int>(m + 1, 0));
		for (int i = 0; i <= n; i++) {
			for (int j = 0; j <= m; j++) {
				if (i == 0 && j == 0) {
					dp[i][j] = 1;
					continue;
				}
				if (i == 0) {    // 上边界
					dp[i][j] = dp[i][j - 1];
				}
				else if (j == 0) {    // 左边界
					dp[i][j] = dp[i - 1][j];
				}
				else {
					dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
				}
			}
		}
		cout << dp[n][m] << endl;
	}

	return 0;
}