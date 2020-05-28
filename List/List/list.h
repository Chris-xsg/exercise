#include<iostream>
#include<assert.h>
using namespace std;

namespace xsg
{
	template<class T>
	struct __list_node
	{
		__list_node<T>* _prev;
		__list_node<T>* _next;
		T _data;

		__list_node(const T& data = T())
			:_next(nullptr)
			, _prev(nullptr)
			, _data(data)
		{}
	};

	template<class T, class Ref, class Ptr>
	struct __list_iterator
	{
		typedef __list_iterator<T, Ref, Ptr> Self;
		typedef __list_node<T> node;
		node* _node;

		__list_iterator(node* node)
			:_node(node)
		{}

		// ����ĵ����ĺ��Ļ��ǽڵ��ָ��
		// ���Ƿ�װ���࣬����ͨ�������ȥ����++ * ����Ϊ
		//T& operator*()
		Ref operator*()
		{
			return _node->_data;
		}

		// T* operator->()
		Ptr operator->()
		{
			return &_node->_data;
		}

		Self& operator++()
		{
			_node = _node->_next;
			return *this;
		}

		Self operator++(int)
		{
			__list_iterator<T> tmp(*this);
			_node = _node->_next;
			return tmp;
		}

		Self& operator--()
		{
			_node = _node->_prev;
			return *this;
		}

		Self operator--(int)
		{
			Self tmp(*this);
			_node = _node->_prev;
			return tmp;
		}

		bool operator!=(const Self& it)
		{
			return _node != it._node;
		}

		bool operator==(const Self& it)
		{
			return _node == it._node;
		}
	};

	template<class T>
	class list
	{
		typedef __list_node<T> node;
	public:
		typedef __list_iterator<T, T&, T*> iterator;
		typedef __list_iterator<T, const T&, const T*>  const_iterator; // const���������ʵ�֣�����ͨ�������Ĳ�һ����

		iterator begin()
		{
			return iterator(_head->_next);
		}

		iterator end()
		{
			return iterator(_head);
		}

		const_iterator begin() const
		{
			return const_iterator(_head->_next);
		}

		const_iterator end() const
		{
			return const_iterator(_head);
		}

		list()
		{
			_head = new node;
			_head->_next = _head;
			_head->_prev = _head;
		}

		//lsit<int> lt2(lt1)
		list(const list<int>& lt)
		{
			_head = new node;
			_head->_next = _head;
			_head->_prev = _head;

			for (auto e : lt)
			{
				push_back(e);
			}

		}


		/*list<T>& operator=(const list<int>& lt)
		{
			clear();
			if (this != lt)
			{
				for (auto e : lt)
				{
					push_back(e);

				}
			}
			
			return *this;
		}*/

		list<T>& operator=(const list<int>& lt)
		{
			swap(_head, lt._head);

			return *this;
		}

		~list()
		{
			clear();
			delete _head;
			_head = nullptr;
		}

		void clear()
		{
			iterator it = begin();
			while (it != end())
			{
				iterator next = it;
				++next;

				delete it._node;

				it = next;
			}

			_head->_next = _head;
			_head->_prev = _head;
		}

		void push_back(const T& x)
		{
			/*node* newnode = new node(x);
			node* tail = _head->_prev;

			tail->_next = newnode;
			newnode->_prev = tail;
			newnode->_next = _head;
			_head->_prev = newnode;*/

			insert(end(), x);

		}

		void pop_back()
		{
			erase(--end());
		}

		void push_front(const T& x)
		{
			insert(begin(), x);
		}

		void pop_front()
		{
			erase(begin());
		}

		void insert(iterator pos, const T& x)
		{
			node* cur = pos._node;
			node* prev = cur->_prev;
			node* newnode = new node(x);

			prev->_next = newnode;
			newnode->_prev = prev;
			newnode->_next = cur;
			cur->_prev = newnode;

		}

		iterator erase(iterator pos)
		{
			node* del = pos._node;
			node* prev = del->_prev;
			node* next = del->_next;

			prev->_next = next;
			next->_prev = prev;
			delete del;

			return pos;

		}

	private:
		node* _head;
	};

	void test_list1()
	{
		list<int> lt;
		lt.push_back(1);
		lt.push_back(2);
		lt.push_back(3);
		lt.push_back(4);

		list<int>::iterator it = lt.begin();
		while (it != lt.end())
		{
			*it *= 2;
			cout << *it << " ";
			++it;
		}
		cout << endl;
	}

	struct A
	{
		A(int a1 = 0, int a2 = 0)
		:_a1(a1)
		, _a2(a2)
		{}

		int _a1;
		int _a2;
	};

	void test_list2()
	{
		/*int* p1 = new int;
		cout << *p1 << endl;
		A* p2 = new A(1,2);
		cout << p2->_a1 << endl;
		cout << p2->_a2 << endl;*/

		list<A> lt;
		lt.push_back(A(1, 2));
		lt.push_back(A(10, 20));
		lt.push_back(A(100, 200));
		list<A>::iterator it = lt.begin();
		while (it != lt.end())
		{
			//cout << *it << " ";
			cout << it->_a1 << ":" << it->_a2 << endl;
			++it;
		}
		cout << endl;
	}

	void PrintList(const list<int>& lt)
	{
		list<int>::const_iterator it = lt.begin();
		while (it != lt.end())
		{
			//*it = 2;
			cout << *it << " ";
			++it;
		}
		cout << endl;
	}

	void test_list3()
	{
		list<int> lt;
		lt.push_back(1);
		lt.push_back(2);
		lt.push_back(3);
		lt.push_back(4);

		PrintList(lt);

		lt.clear();
		PrintList(lt);
	}
}