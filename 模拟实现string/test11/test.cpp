#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;


namespace XSG
{
	class string
	{
	public:
		string(const char* str = "") //构造函数
		{
			if (str == nullptr)
				str = "";
			_str = new char[strlen(str) + 1];
			strcpy(_str, str);
		}

		string(const string& s) //拷贝构造
			:_str(nullptr)
		{
			string tmp(s._str);
			swap(_str, tmp._str);

		}

		string& operator=(const string& s)//赋值
		{
			if (this != &s)
			{
				string tmp(s._str);
				swap(_str, tmp._str);
			}
			return *this;
		}

		~string()//析构
		{
			if (_str)
			{
				delete[] _str;
				_str = nullptr;
			}
		}

	private:
		char* _str;
	};

}

int main()
{
	XSG::string s1 = "hello";
	XSG::string s2(s1);
	XSG::string s3 = s1;

	return 0;
}