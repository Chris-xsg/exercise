#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<cmath>
#include<vector>
using namespace std;


/**
*  奇数位上都是奇数或者偶数位上都是偶数
*  输入：数组arr，长度大于2
*  len：arr的长度
*  将arr调整成奇数位上都是奇数或者偶数位上都是偶数
*/
void oddInOddEvenInEven(vector<int>& arr, int len) 
{
	int Odd = 1;//奇数指针从1开始，每次只指向奇数下标
	int Even = 0;//偶数指针从0开始，每次只指向偶数下标

	while (Odd < len && Even < len)
	{
		if (arr[Odd] % 2 != 0 && arr[Even] % 2 == 0)
		{//奇数位置放着奇数，偶数位置放着偶数，符合条件直接向后移
			Odd += 2;
			Even += 2;
		}
		else if (arr[Odd] % 2 == 0 && arr[Even] % 2 != 0)
		{//奇数位置放着偶数，并且偶数位置也放着奇数，直接进行交换，然后再向后移
			swap(arr[Odd], arr[Even]);
			Odd += 2;
			Even += 2;
		}
		else if (arr[Odd] % 2 == 0)
		{//奇偶位置都放着偶数，那么Even向后移
			Even += 2;
		}
		else
		{//奇偶位置都放着奇数，那么Odd向后移
			Odd += 2;
		}
	}

}

void oddInOddEvenInEven(vector<int>& arr, int len) {
	int Even = 0, Odd = 1;
	while (Even<len&&Odd<len)
	{
		if (arr[len - 1] % 2 == 0)
		{//为偶数就将其与偶数位交换，偶数位向后移
			swap(arr[len - 1], arr[Even]);
			Even += 2;
		}
		else
		{//奇数就与奇数位交换，奇数位向后移
			swap(arr[len - 1], arr[Odd]);
			Odd += 2;
		}
	}
}


//猴子分桃
int main()

{
	int n;
	long long a, b;
	while (cin >> n)
	{
		if (n == 0)
			break;
		else
		{
			a = pow(5, n) - 4;
			b = pow(4, n) + n - 4;
			cout << a << " " << b << endl;
		}
	}
	return 0;

}