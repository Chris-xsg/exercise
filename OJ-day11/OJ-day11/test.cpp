#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
#include<vector>
using namespace std;


//�ַ�����
int main()
{
	string str;
	while (getline(cin, str))
	{
		int count = 0;
		string tmp;
		tmp = "";
		for (int i = 0; i < str.size(); i++)
		{
			if ( tmp.find(str[i]) == string::npos)
			{
				tmp += str[i];
			}
			
		}
		cout << tmp << endl;


	}

	return 0;
}


//Ԫ�ز���
class Finder {
public:
	int findElement(vector<int> A, int n, int x) {
		// write code here
		int left = 0;
		int right = n - 1;
		int mid = 0;

		while (left <= right)
		{
			mid = (left + right) / 2;
			if (A[mid] == x)
				return mid;
			if (A[mid] < x)
			{
				if (A[mid] < A[left] && x > A[right]) //˵���ұ��������,x��mid���
				{
					right = mid - 1;
				}
				else
					left = mid + 1;
			}
			else
			{
				if (A[mid]>A[left] && x<A[left])//˵�����������ģ�x��mid�ұ�
				{
					left = mid + 1;
				}
				else
					right = mid - 1;
			}

		}
		return false;
	}
};


////����������� ��������
//class LCA {
//public:
//	int getLCA(int a, int b) {
//		// write code here
//
//		while (a != b)
//		{
//			if (a > b)
//				a /= 2;
//			else
//				b /= 2;
//		}
//		return a;
//	}
//};
//
//
////���������bit��  λ����
//int main()
//{
//	int byte;
//	while (cin >> byte)
//	{
//		int max = 0;
//		int count = 0;
//		while (byte)
//		{
//			int flag = 0;
//			while (byte && (byte & 1))
//			{
//				byte = byte >> 1;
//				count++;
//			}
//			if (!(byte & 1))
//			{
//				if (count>max)
//					max = count;
//				count = 0;
//				byte = byte >> 1;
//			}
//		}
//		cout << max << endl;
//	}
//
//	return 0;
//}
