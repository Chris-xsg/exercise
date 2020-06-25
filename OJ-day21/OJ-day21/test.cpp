#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<stack>
using namespace std;


//ϴ��
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
	stack<int> a;//��ջ������ϴ��
	reverse(left.begin(), left.end());//���������ֵ���
	reverse(right.begin(), right.end());
	for (int i = 0; i < n / 2; i++)
	{//���Һ�����ջ
		a.push(right[i]);
		a.push(left[i]);
	}
	for (int j = 0; j < n; j++)
	{//��ջ arr��Ϊϴ����
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
 		while (T--)//T������
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


//MP3���λ��
int main()
{
	int n;
	string order;
	while (cin >> n >> order)
	{
		int num = 1, first = 1; //��n�׸������1��n , numΪ��굱ǰ���ڸ����ı��,firstΪ��ǰ��Ļ��ʾҳ�ĵ�һ�׸����ı��
		if (n <= 4) //��������������4ʱ�����и���һҳ������ʾ�꣬���跭ҳ��firstʼ�ղ���
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
		else  //������������4ʱ����ʾ��ȫ���и�����Ҫ��ҳ����Ļ������ʾ4�׸���
		{
			for (int i = 0; i<order.size(); i++)
			{
				if (first == 1 && num == 1 && order[i] == 'U') { first = n - 3; num = n; } //���ⷭҳ1
				else if (first == n - 3 && num == n && order[i] == 'D') { first = 1; num = 1; } //���ⷭҳ2
				else if (first != 1 && num == first && order[i] == 'U') { first--; num--; } //һ�㷭ҳ1
				else if (first != n - 3 && num == first + 3 && order[i] == 'D') { first++; num++; } //һ�㷭ҳ2
				else if (order[i] == 'U') num--; //�������1
				else num++; //�������2
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

