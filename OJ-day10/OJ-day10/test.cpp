#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<string>
using namespace std;


//�����壺�жϵ�ǰ����Ƿ��ʤ
class Board {
public:
	bool checkWon(vector<vector<int> > board) {
		// write code here
		if (board.empty())
			return false;
		for (int i = 0; i<3; i++)
		{//�������и������Ϊ3��ʾӮ��
			if ((board[i][0] + board[i][1] + board[i][2]) == 3)
			{
				return true;
			}
			else if ((board[0][i] + board[1][i] + board[2][i]) == 3)
			{
				return true;
			}
		}
		//�����Խ���
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



//����ǿ�ȵȼ�

int main()
{
	string pPasswordStr;
	while (getline(cin, pPasswordStr))
	{
		int socer = 0;//����
		int len = pPasswordStr.size();
		int nums = 0, numcounts = 0;//��¼����
		int chars = 0, charscounts = 0;//��¼�ַ�
		int lettersL = 0;//��¼��д��ĸ
		int lettersS = 0;//��¼Сд��ĸ
		//�жϳ���
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
				lettersS = 1;// ��Сд��ĸ
			}
			else if (pPasswordStr[i] <= 'Z' && pPasswordStr[i] >= 'A')
			{
				lettersL = 1;//�д�д��ĸ
			}
			else if (isdigit(pPasswordStr[i]))
			{
				nums = 1; //�����֣�����ÿ��һ�����־ͼ�1
				numcounts++;
			}
			else
			{
				chars = 1;//���ַ�������ÿ��һ���ַ��ͼ�1
				charscounts++;
			}
		}
		if (lettersL == 1 && lettersS == 1)
		{
			socer += 20;//��Сд�����ĸ
		}
		else if ((lettersL == 1 && lettersS != 1)
			|| (lettersL != 1 && lettersS == 1))
		{
			socer += 10;//ֻ�д�д��ĸ����ֻ��Сд��ĸ
		}
		if (numcounts == 1)
			socer += 10;//ֻ��һ������
		else if (numcounts > 1)
			socer += 20;//����һ������
		if (charscounts == 1)
			socer += 10;//ֻ��һ������
		else if (charscounts > 1)
			socer += 25;//����һ������

		if ((lettersL == 1 && lettersS != 1) && nums >= 1 && chars == 0)
			socer += 2; //��д��ĸ������
		else if ((lettersL != 1 && lettersS == 1) && nums >= 1 && chars == 0)
			socer += 2;//Сд��ĸ������
		else if ((lettersL == 1 || lettersS == 1) && nums >= 1 && chars >= 1)
			socer += 3;//��ĸ�����ֺͷ���
		else if (lettersL && lettersS && nums && chars)
			socer += 5;//��Сд��ĸ�����ֺͷ���

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