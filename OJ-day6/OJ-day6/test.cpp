#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<math.h>
using namespace std;


void Fun1()
{

	int W, H, i, j, counts = 0;

	cin >> W >> H;

	if (W % 4 == 0 || H % 4 == 0)
	{

		counts = W*H / 2;

	}
	else if(W % 2 == 0 && H % 2 == 0)
	{

		counts = (W*H / 4 + 1) * 2;

	}
	else
	{

		counts = W*H / 2 + 1;

	}

	cout << counts << endl;
	

}


//×Ö·û´®×ªÕûÊý
class Solution {
public:
	int StrToInt(string str) {
		if (str.empty())
			return 0;
		int symbol = 1;
		int len = str.size();
		if (str[0] == '-')
		{
			symbol = -1;
			str[0] = '0';
		}
		else if (str[0] == '+')
		{
			symbol = 1;
			str[0] = '0';
		}
		int ret = 0;
		for (int i = 0; i < len; i++)
		{
			if (str[i] < '0' || str[i] > '9')
			{
				return 0;
			}
			else
			{
				ret = ret * 10 + str[i] - '0';
			}
		}

		if ((symbol == 1 && ret > INT_MAX) || (symbol == -1 && ret < INT_MIN))
		{
			return 0;
		}
		return ret*symbol;

	}
};


int main()
{
	Fun1();


	return 0;
}
