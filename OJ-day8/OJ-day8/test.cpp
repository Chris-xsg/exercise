#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;


//vector<string>vec;
////按照字典序排序
//bool  lexicographically(){
//
//	int i = 0;
//	string s;
//
//	while ((i + 1) < vec.size()){
//		if (vec[i].compare(vec[i + 1]) >0)
//			return 0;
//		i++;
//	}
//	return 1;
//}
//
////按照字符串大小排序
//bool Lenths(){
//
//	int i = 0;
//	while ((i + 1) <vec.size()){
//		if (vec[i + 1].size() < vec[i].size())
//			return 0;
//		i++;
//	}
//	return 1;
//}
//
//int main(){
//
//	string s;
//	int n, i = 0;
//	bool b1, b2;
//
//	cin >> n;
//	while (i < n){
//		cin >> s;
//		vec.push_back(s);
//		i++;
//	}
//
//	b1 = lexicographically();
//	b2 = Lenths();
//
//	if (b1 && b2)
//		cout << "both";
//	else if (b1 && !b2)
//		cout << "lexicographically";
//	else if (!b1 && b2)
//		cout << "lengths";
//	else
//		cout << "none";
//
//
//	return 0;
//}

//最小公倍数
void Least_CommonMul()
{
	int A, B;
	cin >> A >> B;
	int C,D;
	if (A > B)
	{
		C = A;
		D = B;
	}
	else
	{
		C = B;
		D = A;
	}
		
	vector<int> arr;
	arr.resize(C);
	int i = 0;
	int j = 1;
	for (i,j; i < C, j <= C; ++i, ++j)
	{
		arr[i] = j * D;
	}
	for (int i = 0; i < arr.size(); ++i)
	{
		
		if ((arr[i] % C) == 0)
		{
			cout << arr[i] << endl;
			break;
		}
	}

}



int main()
{
	
	//Least_CommonMul();
	
	return 0;
}