#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<iostream>
#include<string>
#include<assert.h>

using namespace std;

//int main()
//{
//	string s1; //�޲ι���
//	string s2("hello world"); //���ι���
//	string s3(s2); //��������
//	s2 = s3; //operator = 
//
//	cout << s1.size() << endl;
//	cout << s2.size() << endl;
//
//	cout << s1.length() << endl;
//	cout << s2.length() << endl;
//
//	cout << s1.capacity() << endl;
//	cout << s2.capacity() << endl;
//
//	cout << s1.empty() << endl;
//	cout << s2.empty() << endl;
//
//	s2.clear();
//	cout << s2 << endl;
//
//
//
//	return 0;
//}

//��ӡ�ͱ���
//int main()
//{
//	string s1("hello world");
//
//	cout << s1 << endl;
//	cout << s1.c_str() << endl;
//
//	s1.resize(20);
//	s1.push_back('x');
//	cout << s1 << endl; //ȫ����ӡ����
//	cout << s1.c_str() << endl; //����'\0'�ͽ���
//
//
//	return 0;
//}

//int main()
//{
//	//ת��������
//	string s("12345");
//	int value = 0;
//
//	//����s��1��size+[]
//	for (size_t i = 0; i < s.size(); ++i)
//	{
//		value *= 10;
//		value += (s[i] - '0');
//
//	}
//	cout << value << endl;
//
//	//2��������
//	value = 0;
//	string::iterator it = s.begin();
//	while (it != s.end())
//	{
//		value *= 10;
//		value += (*it - '0');
//		++it;
//	}
//	cout << value << endl;
//}

//int main()
//{
//	string s("hello world");
//	s.push_back('!');
//	s.append("hello world");
//	cout << s << endl;
//
//	//���Ƽ���+=
//	string s1("hello world");
//	string s2("123");
//	s1 += s2;
//	s1 += '5';
//	cout << s1 << endl;
//
//	return 0;
//	
//}

//int main()
//{
//	//ȡ����׺
//	string file1("string.cpp.zip");
//	string file2("string.c");
//
//	size_t pos1 = file1.find('.');
//	cout << file1.substr(pos1) << endl;
//
//	size_t pos2 = file1.rfind('.');//������
//	cout << file1.substr(pos2) << endl;
//
//	size_t pos3 = file2.find('.');
//	cout << file2.substr(pos3,file2.size() - pos3) << endl;
//
//	string url("https://www.gitee.com/HGtz2222/VimForCpp/tree/master");
//	cout << url << endl;
//	//ȡ������
//	size_t urlpos = url.find("://");
//	urlpos += 3;
//	size_t urlend = url.find('/', urlpos);
//	cout << url.substr(urlpos,urlend - urlpos) << endl;
//
//	return 0;
//}


//int main()
//{
//	string s1;
//	s1 += 'h';
//	s1 += "ello";
//	cout << s1 << endl;
//
//	//���龡������������Ϊʱ�临�Ӷ�ΪO(N)
//	s1.insert(0, "world ");
//	s1.insert(0, " ");
//
//	cout << s1 << endl;
//
//	s1.erase(s1.begin());
//	cout << s1 << endl;
//
//	s1.erase(s1.begin() + 5);
//	cout << s1 << endl;
//
//	//s1.erase(); //s1.clear();
//	cout << s1 << endl;
//
//	s1.erase(5, 3);
//	cout << s1 << endl;
//
//
//	return 0;
//}


//int main()
//{
//	string s1("hello world");
//	string s2("hello");
//
//	//size_t pos = s1.find('x');
//	//if (pos != string::npos)
//	//{
//	//	cout << pos << endl;
//	//}
//	//else
//	//{
//	//	cout << "û���ҵ�" << endl;
//	//}
//
//	//��strcmp�ȽϹ���һ�������ַ���ASCLL��ȥ�Ƚ�
//	/*cout << (s1 < s2) << endl;
//	cout << (s1 == s2) << endl;*/
//
//
//
//	return 0;
//}



//namespace bit
//{
//	class string
//	{
//	public:
//		string(const char* str)
//			:_str(new char[strlen(str) + 1])
//		{}
//	private:
//		char* _str;
//	};
//
//}


//���ַ���������ֻ����һ�ε��ַ�
//#include<iostream>
//#include<string>
//using namespace std;
//
//int main()
//{
//	string str;
//	while (cin >> str)
//	{
//		int CountArray[26] = { 0 };
//		int count = 1;
//		for (int i = 0; i < str.size(); i++)
//		{
//			CountArray[str[i] - 'a']++;
//		}
//		for (int i = 0; i < str.size(); i++)
//		{
//			if (CountArray[str[i] - 'a'] == 1)
//			{
//				cout << str[i] << endl;
//				count = 0;
//				break;
//			}
//			
//		}
//		if (count)
//		{
//			cout << -1 << endl;
//		}
//	}
//	return 0;
//	
//}

//�������һ�����ʵĳ���
//#include<iostream>
//#include<string>
//using namespace std;
//
//int Find_LastWordLen(string& str)
//{
//	if (str.empty())
//	{
//		return 0;
//	}
//	size_t pos = str.rfind(' ');
//	if (pos == string::npos)
//	{
//		return str.size();
//	}
//	else
//	{
//		return str.size() - pos - 1;
//
//	}
//}
//
//int main()
//{
//	string str;
//	getline(cin, str);
//	int len = Find_LastWordLen(str);
//	cout << len << endl;
//	
//
//	return 0;
//}



//�ַ���ת��������
//class Solution {
//public:
//	int StrToInt(string str) {
//
//		const int length = str.length();
//		int isNegtive = 1, overValue = 0;
//		int digit = 0, value = 0;
//		if (length == 0) return 0;
//		else
//		{
//			int idx = 0;
//			if (str[0] == '-') 
//			{ 
//				isNegtive = -1; idx = 1; 
//			}
//			else if (str[0] == '+') 
//			{ 
//				idx = 1; 
//			}
//
//			for (; idx<length; idx++) 
//			{
//				digit = str[idx] - '0';
//				// overValue��ʾ����ѭ���Ƿ��Խ��
//				overValue = isNegtive*value - INT_MAX / 10
//					+ (((isNegtive + 1) / 2 + digit > 8) ? 1 : 0);
//
//				if (digit<0 || digit>9) return 0;
//				else if (overValue > 0) return 0;
//
//				value = value * 10 + isNegtive*digit;
//			}
//			return value;
//		}
//	}
//};


//namespace XSG
//{
//	//�ַ�����
//	class string
//	{
//	public:
//		string(char* str = nullptr)
//			:_str(str)
//		{}
//		char& operator[](size_t pos)
//		{
//			return _str[pos];
//		}
//
//	private:
//		char* _str;
//	};
//
//}
//
//int main()
//{
//	XSG::string s1;
//	XSG::string s2("hello");
//	s2[0] = 'x';
//
//	return 0;
//}

//��ɾ��ĵ�string��ģ��ʵ��
namespace xsg
{
	class string
	{
	public:
		string(const char* str = "")
			:_size(strlen(str))
		
			{
				_capacity = _size;
				_str = new char[_capacity + 1];
				strcpy(_str, str);
			}

		~string()
		{
			delete[] _str;
			_str = nullptr;
			_size = _capacity = 0;
		}

		string(const string& s)
		{
			_str = new char[s._size + 1];
			strcpy(_str, s._str);
			_size = s._size;
			_capacity = s._size;
			//_capacity = s._capacity; ����\0������Ч�ַ�
		}

		string& operator=(const string& s)
		{
			if (this != &s)
			{
				delete[] _str;
				_str = new char[s._size + 1];
				strcpy(_str, s._str);
				_size = s._size;
				_capacity = s._size;
			}
			return *this;
		}

		size_t size() const
		{
			return _size;
		}

		size_t capacity() const
		{
			return _capacity;
		}

		char& operator[](size_t pos) const
		{
			assert(pos < _size);
			return _str[pos];
		}

		void reserve(size_t n)
		{
			if (n > _capacity)
			{
				char* newstr = new char[n + 1];
				strcpy(newstr, _str);
				delete[] _str;
				++_size;
				_str[_size] = '\0';
			}
		}

		void push_back(char ch)
		{
			//if (_size == _capacity)
			//{
			//	//����
			//	_capacity *= 2;
			//	char* tmp = new char[_capacity + 1];
			//	strcpy(tmp, _str);
			//	delete[] _str;
			//	_str = tmp;
			//}
			reserve(_capacity * 2);
			_str[_size] = ch;
			++_size;
			_str[_size] = '\0';
		}


		void append(const char* str)
		{
			size_t len = strlen(str);
			if (_size + len >= _capacity)
			{
				reserve(_size + len);
			}
			strcpy(_str + _size, str);
			_size += len;
		}

		string& operator+=(char ch)
		{
			this->push_back(ch);
			return *this;

		}

		string& operator+=(const char* str)
		{
			this->append(str);
			return *this;

		}

		ostream& operator<<(ostream& out)
		{

		}

	private:
		char* _str;
		size_t _size;
		size_t _capacity;

	};

}

int main()
{
	xsg::string s1("hello");
	s1.push_back('x');
	s1.push_back('y');



	return 0;
}