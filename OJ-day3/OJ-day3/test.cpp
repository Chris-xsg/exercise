#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;

//�ҳ��ַ���������������ִ�
void Find_LongNumstr()
{
	string str,tmp,Max;
	cin >> str;

	for (int i = 0; i < str.size(); i++)
	{
		if (isdigit(str[i]))
		{
			tmp += str[i];
		}
		if (!isdigit(str[i + 1]))
		{
			if (tmp.size() > Max.size())
			{
				Max = tmp;
				
			}
			tmp = "";
		}
	}
	cout << Max << endl;


}


//�����г��ִ�������һ�������
class Solution {
public:
	
	int MoreThanHalfNum_Solution()
	{
		vector<int> numbers;
		if (numbers.empty()) return 0;

		sort(numbers.begin(), numbers.end()); // ����ȡ�����м��Ǹ���
		int middle = numbers[numbers.size() / 2];//ֻҪ���Ǹ������϶����м�Ϊmiddle

		int count = 0; // ���ִ���
		for (int i = 0; i<numbers.size(); ++i)
		{
			if (numbers[i] == middle) ++count;
		}

		return (count>numbers.size() / 2) ? middle : 0;
	}
};


int main()
{
	//Find_LongNumstr();

	return 0;
}

