#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;


//���ս� N*M����·������ ---��̬�滮
class Bonus {
public:
	int getMost(vector<vector<int> > board) {
		// write code here
		vector<vector <int>> dp(6, vector<int>(6, 0));
		dp[0][0] = board[0][0];
		for (int i = 1; i < 6; i++)
		{//�ϱ߽�
			dp[0][i] = dp[0][i - 1] + board[0][i];
		}
		for (int i = 1; i < 6; i++)
		{//��߽�
			dp[i][0] = dp[i - 1][0] + board[i][0];
		}
		for (int i = 1; i < 6; i++)
		{
			for (int j = 1; j < 6; j++)
			{//���Ǳ߽磬�����ߵĺ������ߵģ�ȡ���
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + board[i][j];
			}
		}
		return dp[5][5];

	}
};


//�Թ����� N*M��ά������Ψһ·�� ---����
int N, M; //�ֱ�����к���
vector<vector<int>> maze;//�Թ�����
vector<vector<int>> path_temp;//�洢��ǰ·������һά��ʾλ��
vector<vector<int>> path_best;//�洢���·��
void MazeTrack(int i, int j)
{
	maze[i][j] = 1;//��ʾ��ǰ�ڵ����ߣ���������
	path_temp.push_back({ i, j });//����ǰ�ڵ���뵽·����

	if (i == N - 1 && j == M - 1) //�ж��Ƿ񵽴��յ�
	{
		if (path_best.empty() || path_temp.size() < path_best.size())
			path_best = path_temp;
	}
	if (i - 1 >= 0 && maze[i - 1][j] == 0)//̽���������Ƿ����
		MazeTrack(i - 1, j);
	if (i + 1 < N && maze[i + 1][j] == 0)//̽���������Ƿ����
		MazeTrack(i + 1, j);
	if (j - 1 >= 0 && maze[i][j - 1] == 0)//̽���������Ƿ����
		MazeTrack(i, j - 1);
	if (j + 1 < M && maze[i][j + 1] == 0)//̽���������Ƿ����
		MazeTrack(i, j + 1);
	maze[i][j] = 0;         //�ָ��ֳ�����Ϊδ��
	path_temp.pop_back();
}

//��ӽ�����֮��
int threeSumClosest(vector<int>& nums, int target) 
{
	std::sort(nums.begin(), nums.end());//����
	if (nums.size() < 3)
	{//����С��������0
		return 0;
	}
	int ret = nums[0] + nums[1] + nums[2];//�Ƚ�ǰ������������
	if (nums.size() == 3)
	{//ֻ�������Ļ���ֱ�ӷ���
		return ret;
	}
	if (target <= ret)//���target��retС���Ǿ�˵��ֻ����ret��ӽ���
		return ret;
	for (int i = 0; i<nums.size(); i++)
	{//������⣬����ѭ��
		for (int j = i + 1; j<nums.size(); j++)
		{
			for (int k = j + 1; j<nums.size(); k++)
			{
				if (k == nums.size())
				{//��kΪnums.size()ʱֱ����������Ȼ��Խ��
					break;
				}
				int sum = nums[i] + nums[j] + nums[k];
				if (abs(target - ret) >= abs(target - sum))
				{//�Ƚ�������������Ĵ�С��С�ĸ�ret
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
	//		cout << '(' << i[0] << ',' << i[1] << ')' << endl;//���ͨ·
	//}
	return 0;
}
