#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;


//�����г��ִ�������һ�������
int MoreThanHalfNum_Solution(vector<int> numbers) {

	int n = numbers.size();
	if (n == 0) return 0;

	int num = numbers[0], count = 1;
	for (int i = 1; i < n; i++)
	{
		if (numbers[i] == num) count++;
		else count--;
		if (count == 0)
		{
			num = numbers[i];
			count = 1;
		}
	}
	count = 0;
	for (int i = 0; i < n; i++)
	{
		if (numbers[i] == num) count++;
	}
	if (count * 2 > n) return num;
	return 0;

}

//�򵥴����¼
struct ErrMsg{
	string fname;
	int num;

	ErrMsg(string fname){
		this->fname = fname;
		this->num = 1;
	}

	bool operator==(const ErrMsg & a){
		return fname == a.fname;
	}
};
int main()
{
	string dirName, lineNum;
	vector<ErrMsg> v;
	while (cin >> dirName >> lineNum)
	{
		string fileName = dirName.substr(dirName.find_last_of("\\") + 1);
		if (fileName.size()>16) fileName.erase(fileName.begin(), fileName.end() - 16);
		fileName = fileName + " " + lineNum;//���ļ������к����ӳ�һ���ַ���
		ErrMsg er(fileName);
		auto it = find(v.begin(), v.end(), er);
		if (it == v.end())
			v.push_back(er);
		else (*it).num++;
	}
	if (v.size() <= 8 && v.size() >= 0)
	for (auto e : v) cout << e.fname << " " << e.num << endl;
	else if (v.size()>8)
	for (auto ite = v.end() - 8; ite<v.end(); ite++) cout << (*ite).fname << " " << (*ite).num << endl;
	return 0;
}




