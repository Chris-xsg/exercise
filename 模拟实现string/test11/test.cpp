#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;


namespace XSG
{
	class string
	{
	public:
		string(const char* str = "") //���캯��
		{
			if (str == nullptr)
				str = "";
			_str = new char[strlen(str) + 1];
			strcpy(_str, str);
		}

		string(const string& s) //��������
			:_str(nullptr)
		{
			string tmp(s._str);
			swap(_str, tmp._str);

		}

		string& operator=(const string& s)//��ֵ
		{
			if (this != &s)
			{
				string tmp(s._str);
				swap(_str, tmp._str);
			}
			return *this;
		}

		~string()//����
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