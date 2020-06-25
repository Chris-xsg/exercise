#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<stack>
using namespace std;


//洗牌
void Shuffle(vector<int >& arr)
{
	int n = arr.size();
	vector<int> left,right;
	for (int i = 0; i < n; i++)
	{
		if (i < n / 2)
			left.push_back(arr[i]);
		else
			right.push_back(arr[i]);
	}
	arr.clear();
	stack<int> a;//用栈操作来洗牌
	reverse(left.begin(), left.end());//逆置左右手的牌
	reverse(right.begin(), right.end());
	for (int i = 0; i < n / 2; i++)
	{//先右后左入栈
		a.push(right[i]);
		a.push(left[i]);
	}
	for (int j = 0; j < n; j++)
	{//出栈 arr就为洗完后的
		arr.push_back(a.top());
		a.pop();
	}
}


void Shuffle_Cards()
{
	int T;
	while (cin >> T)
	{
		vector<vector<int>> ret(T+1, vector<int>(INT_MAX, 0));
		ret.clear();
		int n, k;
 		while (T--)//T组数据
		{
			cin >> n >> k;
			vector<int> arr(2 * n, 0);
			for (int i = 0; i < 2 * n; i++)
			{
				cin >> arr[i];

			}
			while (k--)
			{
				Shuffle(arr);
			}
			
			for (int i = 0; i < 2 * n; i++)
			{
				ret[T].push_back(arr[i]);
			}
		}

		for (int i = T; i>0; i--)
		{
			for (int j = 0; j < ret[T].size(); j++)
			{
				if (ret[i][j] != ret[i][j - 1])
					cout << ret[i][j] << " ";
				else
					cout << ret[i][j];
			}
			cout << endl;
		}
	
	}
	
}


//MP3光标位置
int main()
{
	int n;
	string order;
	while (cin >> n >> order)
	{
		int num = 1, first = 1; //将n首歌曲编号1：n , num为光标当前所在歌曲的编号,first为当前屏幕显示页的第一首歌曲的编号
		if (n <= 4) //歌曲总数不超过4时，所有歌曲一页即可显示完，不需翻页，first始终不变
		{
			for (int i = 0; i<order.size(); i++)
			{
				if (num == 1 && order[i] == 'U') num = n;
				else if (num == n && order[i] == 'D') num = 1;
				else if (order[i] == 'U') num--;
				else  num++;
			}
			for (int i = 1; i <= n - 1; i++)
				cout << i << ' ';
			cout << n << endl;
			cout << num << endl;
		}
		else  //歌曲总数大于4时，显示完全所有歌曲需要翻页，屏幕总是显示4首歌曲
		{
			for (int i = 0; i<order.size(); i++)
			{
				if (first == 1 && num == 1 && order[i] == 'U') { first = n - 3; num = n; } //特殊翻页1
				else if (first == n - 3 && num == n && order[i] == 'D') { first = 1; num = 1; } //特殊翻页2
				else if (first != 1 && num == first && order[i] == 'U') { first--; num--; } //一般翻页1
				else if (first != n - 3 && num == first + 3 && order[i] == 'D') { first++; num++; } //一般翻页2
				else if (order[i] == 'U') num--; //其他情况1
				else num++; //其他情况2
			}
			for (int i = first; i<first + 3; i++)
				cout << i << ' ';
			cout << first + 3 << endl;
			cout << num << endl;
		}
	}
	return 0;
}


int main()
{
	Shuffle_Cards();
	return 0;
}

