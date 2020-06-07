#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<stdlib.h>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

//组队竞赛-贪心算法
void Tanxin_alg()
{
	int n;
	while (cin >> n)
	{
		long long sum = 0;
		vector<int> a;
		a.resize(n * 3);
		for (int i = 0; i < (3 * n); i++)
		{
			cin >> a[i];
		}
		/*排序，然后取下标为3n - 2，3n - 4 ，3n - 4... n+2，n位置的元素累加即可， 
		相当下标为[0,n-1]的n个数做每组的最左边的数，剩下的2个数据两个为一组，
		大的值做最右边的数，次大的做中间值，这里就是把这个次大的值加起来 */

		std::sort(a.begin(), a.end());
		for (int i = n; i <= 3 * n - 2; i += 2)
		{
			sum += a[i];
		}
		cout << sum << endl;
	}

}

//删除公共字符
void Dele_str()
{
	string str1, str2;
	getline(cin, str1);
	getline(cin, str2);

	//使用哈希映射思想先统计str2字符出现的次数
	int hashtable[256] = { 0 };
	for (int i = 0; i < str2.size(); ++i)
	{
		hashtable[str2[i]]++;
	}

	// 遍历str1，str1[i]映射hashtable对应位置为0，则表示这个字符在 
	// str2中没有出现过，则将他+=到ret。注意这里最好不要str1.erases(i) 
	// 因为边遍历，边erase，容易出错。
	string ret;
	for (size_t i = 0; i < str1.size(); ++i)
	{
		if (hashtable[str1[i]] == 0)
		{
			ret += str1[i];
		}
	}
	cout << ret << endl;


}



int main()
{
	//Tanxin_alg();
	Dele_str();

	return 0;
}

