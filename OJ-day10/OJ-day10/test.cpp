#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<string>
using namespace std;


//井字棋：判断当前玩家是否获胜
class Board {
public:
	bool checkWon(vector<vector<int> > board) {
		// write code here
		if (board.empty())
			return false;
		for (int i = 0; i<3; i++)
		{//三行三列各自相加为3表示赢了
			if ((board[i][0] + board[i][1] + board[i][2]) == 3)
			{
				return true;
			}
			else if ((board[0][i] + board[1][i] + board[2][i]) == 3)
			{
				return true;
			}
		}
		//两条对角线
		if ((board[0][0] + board[1][1] + board[2][2]) == 3)
		{
			return true;
		}
		else if ((board[0][2] == board[1][1] == board[2][0]) == 3)
		{
			return true;
		}
		return false;
	}
};



//密码强度等级

int main()
{
	string pPasswordStr;
	while (getline(cin, pPasswordStr))
	{
		int socer = 0;//分数
		int len = pPasswordStr.size();
		int nums = 0, numcounts = 0;//记录数字
		int chars = 0, charscounts = 0;//记录字符
		int lettersL = 0;//记录大写字母
		int lettersS = 0;//记录小写字母
		//判断长度
		if (len <= 4)
		{
			socer = 5;
		}
		else if (len >= 5 && len <= 7)
		{
			socer = 10;
		}
		else if (len >= 8)
		{
			socer = 25;
		}

		for (int i = 0; i < len; i++)
		{
			if (pPasswordStr[i] <= 'z' && pPasswordStr[i] >= 'a')
			{
				lettersS = 1;// 有小写字母
			}
			else if (pPasswordStr[i] <= 'Z' && pPasswordStr[i] >= 'A')
			{
				lettersL = 1;//有大写字母
			}
			else if (isdigit(pPasswordStr[i]))
			{
				nums = 1; //有数字，并且每多一个数字就加1
				numcounts++;
			}
			else
			{
				chars = 1;//有字符，并且每多一个字符就加1
				charscounts++;
			}
		}
		if (lettersL == 1 && lettersS == 1)
		{
			socer += 20;//大小写混合字母
		}
		else if ((lettersL == 1 && lettersS != 1)
			|| (lettersL != 1 && lettersS == 1))
		{
			socer += 10;//只有大写字母或者只有小写字母
		}
		if (numcounts == 1)
			socer += 10;//只有一个数字
		else if (numcounts > 1)
			socer += 20;//大于一个数字
		if (charscounts == 1)
			socer += 10;//只有一个符号
		else if (charscounts > 1)
			socer += 25;//大于一个符号

		if ((lettersL == 1 && lettersS != 1) && nums >= 1 && chars == 0)
			socer += 2; //大写字母和数字
		else if ((lettersL != 1 && lettersS == 1) && nums >= 1 && chars == 0)
			socer += 2;//小写字母和数字
		else if ((lettersL == 1 || lettersS == 1) && nums >= 1 && chars >= 1)
			socer += 3;//字母，数字和符号
		else if (lettersL && lettersS && nums && chars)
			socer += 5;//大小写字母，数字和符号

		if (socer >= 90)
			cout << "VERY_SECURE" << endl;
		else if (socer >= 80 && socer < 90)
			cout << "SECURE" << endl;
		else if (socer >= 70 && socer < 80)
			cout << "VERY_STRONG" << endl;
		else if (socer >= 60 && socer < 70)
			cout << "STRONG" << endl;
		else if (socer >= 50 && socer < 60)
			cout << "AVERAGE" << endl;
		else if (socer >= 25 && socer < 50)
			cout << "WEAK" << endl;
		else if (socer >= 0 && socer < 25)
			cout << "VERY_WEAK" << endl;
	}
	


	return 0;
}