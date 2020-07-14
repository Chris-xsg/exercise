#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<cstring>
#include <iomanip>
using namespace std;

//�����
//DFS�㷨
// ������һ����άint������a[20][20]����¼�ģ�����Ĭ��ȫΪ0��
//'.'��Ϊ0,'#'��'@'��Ϊ1��ע���������ʱ��Ϳ����жϣ�ͬʱ�߹��ĸ���Ҳ��Ϊ1
//��ô����һ��DFSֻҪ�ݹ������ϡ��¡�����4�����ڵĸ��Ӿ���
//��һ��ȫ�ֱ���res��¼���
int a[20][20] = { 0 }, res = 0, m, n;//ע����ȫ�ֱ�������������ʱҪ������ʼ��
void dfs(int x, int y)
{
	if (a[x][y] == 1 || x<0 || x >= m || y<0 || y >= n)//�ݹ�ı߽�����
		return;
	res++;    //�������1
	a[x][y] = 1;//��1�����Ѿ��߹�
	dfs(x - 1, y);//�ֱ��Ӧ��
	dfs(x + 1, y);//��
	dfs(x, y - 1);//��
	dfs(x, y + 1);//�����ڸ���

}
int main()
{
	while (scanf("%d %d", &m, &n))
	{
		getchar();//ΪʲôҪgetchar()?��Ϊ��һ��9 6���滹��һ�����з�
		int x, y;
		char c;
		for (int i = 0; i<m; i++)
		{
			for (int j = 0; j<n; j++)
			{
				scanf("%c", &c);
				if (c == '@')
				{
					x = i;
					y = j;
				}
				else{
					if (c == '#')
						a[i][j] = 1;
				}
			}
			getchar();//ͬ���ģ��Ե�ÿ�����һ�����з�
		}
		dfs(x, y);
		printf("%d\n", res);
		res = 0;
		memset(a, 0, sizeof(a));//ȫ�ֱ�����ʼ��
	}

	return 0;
}


//Ģ����
//Ҫʹ�ö�̬�滮��ע��ÿ����ĸ�����Դ����һ�еĵ㣬��(1,3)�ĸ�����Դֻ������ߵ�(1,2)��1/2��
//��n�еĵ���(n,3)��������ԴΪ(n,2)+(n-1,3)*1/2����Ϊ(n,2)ֻ�������ߣ�����Ϊ1���������������ڳ�������г�

int has[25][25];//����Ģ��
double dp[25][25];//�ܹ�����ÿ�����ӵĸ���
int main()
{
	int n, m, k;
	while (cin >> n >> m >> k)
	{
		int i, j;
		memset(has, 0, sizeof(has));
		memset(dp, 0, sizeof(dp));
		int x, y;
		for (i = 0; i < k; ++i){
			cin >> x >> y;
			has[x][y] = 1;
		}
		for (i = 1; i <= n; ++i){
			for (j = 1; j <= m; ++j){
				if (i == 1 && j == 1) { dp[1][1] = 1; continue; }
				if (has[i][j]) { dp[i][j] = 0; continue; }
				if (i == n && j == m) { dp[i][j] = dp[i - 1][j] + dp[i][j - 1]; continue; }
				if (i == n) { dp[i][j] = dp[i - 1][j] * 0.5 + dp[i][j - 1]; continue; }
				if (j == m) { dp[i][j] = dp[i - 1][j] + dp[i][j - 1] * 0.5; continue; }
				if (i == 1) { dp[i][j] = dp[i][j - 1] * 0.5; continue; }
				if (j == 1) { dp[i][j] = dp[i - 1][j] * 0.5; continue; }
				dp[i][j] = dp[i][j - 1] * 0.5 + dp[i - 1][j] * 0.5;
			}
		}
		cout << fixed << setprecision(2) << dp[n][m] << endl;
	}
	return 0;
}