#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
using namespace std;


//����ӷ�����ʹ��+���������������
class UnusualAdd {
public:
	int addAB(int A, int B) {
		// write code here
		if (A == 0)
			return B;
		else if (B == 0)
			return A;
		else//��λ���Ͱ�λ���ʾ�ӷ�
			return addAB(A^B, (A&B) << 1);
	}
};






//����n*m�����̸��Ӵ����Ͻǵ����½��ܹ��ж������߷��������߻�ͷ·

//1���ݹ�
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



//��̬�滮
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
				if (i == 0) {    // �ϱ߽�
					dp[i][j] = dp[i][j - 1];
				}
				else if (j == 0) {    // ��߽�
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