#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;


//年终奖 N*M矩阵路径问题 ---动态规划
class Bonus {
public:
	int getMost(vector<vector<int> > board) {
		// write code here
		vector<vector <int>> dp(6, vector<int>(6, 0));
		dp[0][0] = board[0][0];
		for (int i = 1; i < 6; i++)
		{//上边界
			dp[0][i] = dp[0][i - 1] + board[0][i];
		}
		for (int i = 1; i < 6; i++)
		{//左边界
			dp[i][0] = dp[i - 1][0] + board[i][0];
		}
		for (int i = 1; i < 6; i++)
		{
			for (int j = 1; j < 6; j++)
			{//不是边界，向下走的和向右走的，取大的
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + board[i][j];
			}
		}
		return dp[5][5];

	}
};


//迷宫问题 N*M二维数组找唯一路径 ---回溯
int N, M; //分别代表行和列
vector<vector<int>> maze;//迷宫矩阵
vector<vector<int>> path_temp;//存储当前路径，第一维表示位置
vector<vector<int>> path_best;//存储最佳路径
void MazeTrack(int i, int j)
{
	maze[i][j] = 1;//表示当前节点已走，不可再走
	path_temp.push_back({ i, j });//将当前节点加入到路径中

	if (i == N - 1 && j == M - 1) //判断是否到达终点
	{
		if (path_best.empty() || path_temp.size() < path_best.size())
			path_best = path_temp;
	}
	if (i - 1 >= 0 && maze[i - 1][j] == 0)//探索向上走是否可行
		MazeTrack(i - 1, j);
	if (i + 1 < N && maze[i + 1][j] == 0)//探索向下走是否可行
		MazeTrack(i + 1, j);
	if (j - 1 >= 0 && maze[i][j - 1] == 0)//探索向左走是否可行
		MazeTrack(i, j - 1);
	if (j + 1 < M && maze[i][j + 1] == 0)//探索向右走是否可行
		MazeTrack(i, j + 1);
	maze[i][j] = 0;         //恢复现场，设为未走
	path_temp.pop_back();
}

//最接近三数之和
int threeSumClosest(vector<int>& nums, int target) 
{
	std::sort(nums.begin(), nums.end());//排序
	if (nums.size() < 3)
	{//长度小于三返回0
		return 0;
	}
	int ret = nums[0] + nums[1] + nums[2];//先将前三个数加起来
	if (nums.size() == 3)
	{//只有三个的话，直接返回
		return ret;
	}
	if (target <= ret)//如果target比ret小，那就说明只能是ret最接近了
		return ret;
	for (int i = 0; i<nums.size(); i++)
	{//暴力求解，三层循环
		for (int j = i + 1; j<nums.size(); j++)
		{
			for (int k = j + 1; j<nums.size(); k++)
			{
				if (k == nums.size())
				{//当k为nums.size()时直接跳出，不然会越界
					break;
				}
				int sum = nums[i] + nums[j] + nums[k];
				if (abs(target - ret) >= abs(target - sum))
				{//比较两个各自相减的大小，小的给ret
					ret = sum;
				}
			}
		}
	}
	return ret;

}



int main()
{
	vector<int> nums;
	nums = { -1, 2, 1, -4 };
	int target = 1;
	int ret = threeSumClosest(nums, target);
	cout << ret << endl;


	//while (cin >> N >> M)
	//{
	//	maze = vector<vector<int>>(N, vector<int>(M, 0));
	//	path_temp.clear();
	//	path_best.clear();
	//	for (auto &i : maze)
	//	{
	//		for (auto &j : i)
	//			cin >> j;
	//	}
	//	MazeTrack(0, 0);
	//	for (auto i : path_best)
	//		cout << '(' << i[0] << ',' << i[1] << ')' << endl;//输出通路
	//}
	return 0;
}
