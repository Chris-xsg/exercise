#pragma once

enum Colour
{
	BLACK,
	RED,
};

template<class T>
struct RBTreeNode
{
	RBTreeNode<T>* _left;
	RBTreeNode<T>* _right;
	RBTreeNode<T>* _parent;

	T _data;

	Colour _col;

	RBTreeNode(const T& data)
		:_left(nullptr)
		, _right(nullptr)
		, _parent(nullptr)
		, _data(data)
		, _col(RED)
	{}
};

template<class T>
struct __TreeIterator
{
	typedef RBTreeNode<T> Node;
	typedef __TreeIterator<T> Self;
	Node* _node;

	__TreeIterator(Node* node)
		:_node(node)
	{}

	T& operator*()
	{
		return _node->_data;
	}

	T* operator->()
	{
		return &_node->_data;
	}

	Self& operator++()
	{
		// 1������Ҳ�Ϊ�գ��������һ������������������ڵ�
		// 2�������Ϊ�գ���ʾ_node���ڵ������Ѿ��������,��һ���ڵ���������������
		//  ����·�������Һ�������������Ǹ�����
		if (_node->_right)
		{
			Node* subLeft = _node->_right;
			while (subLeft->_left)
			{
				subLeft = subLeft->_left;
			}

			_node = subLeft;
		}
		else
		{
			Node* cur = _node;
			Node* parent = cur->_parent;
			while (parent && cur == parent->_right)
			{
				cur = cur->_parent;
				parent = parent->_parent;
			}

			_node = parent;
		}

		return *this;
	}

	Self& operator--()
	{

		return *this;
	}

	bool operator!=(const Self& s)
	{
		return _node != s._node;
	}

	bool operator==(const Self& s)
	{
		return _node == s._node;
	}
};

template<class K, class T, class KOfT>
class RBTree
{
	typedef RBTreeNode<T> Node;
public:
	typedef __TreeIterator<T> iterator;
	iterator begin()
	{
		Node* cur = _root;
		while (cur && cur->_left)
		{
			cur = cur->_left;
		}

		return iterator(cur);
	}

	iterator end()
	{
		return iterator(nullptr);
	}

	bool Insert(const T& data)
	{
		// 1�����������Ĺ�����в���
		if (_root == nullptr)
		{
			_root = new Node(data);
			_root->_col = BLACK;
			return true;
		}

		KOfT koft;
		Node* parent = nullptr;
		Node* cur = _root;
		while (cur)
		{
			if (koft(cur->_data) < koft(data))
			{
				parent = cur;
				cur = cur->_right;
			}
			else if (koft(cur->_data) > koft(data))
			{
				parent = cur;
				cur = cur->_left;
			}
			else
			{
				return false;
			}
		}

		cur = new Node(data);
		if (koft(parent->_data) < koft(cur->_data))
		{
			parent->_right = cur;
			cur->_parent = parent;
		}
		else
		{
			parent->_left = cur;
			cur->_parent = parent;
		}

		// �����ڵ���
		cur->_col = RED;
		while (parent && parent->_col == RED)
		{
			// ���ɫ�������ؼ�������
			Node* grandfther = parent->_parent;
			if (grandfther->_left == parent)
			{
				Node* uncle = grandfther->_right;
				// ���1��uncle���ڣ���Ϊ��
				// ���2 or ���3��uncle������ or uncle���ڣ���Ϊ��
				if (uncle && uncle->_col == RED)
				{
					parent->_col = uncle->_col = BLACK;
					grandfther->_col = RED;

					// �������ϴ���
					cur = grandfther;
					parent = cur->_parent;
				}
				else
				{
					// �������˫�� -> ��Ϊ����
					if (cur == parent->_right)
					{
						RotateL(parent);
						swap(parent, cur);
					}

					// �ڶ������(ps���п����ǵ����ֱ������)
					RotateR(grandfther);
					grandfther->_col = RED;
					parent->_col = BLACK;

					break;
				}
			}
			else
			{
				Node* uncle = grandfther->_left;
				// ���1��uncle���ڣ���Ϊ��
				// ���2 or ���3��uncle������ or uncle���ڣ���Ϊ��
				if (uncle && uncle->_col == RED)
				{
					parent->_col = uncle->_col = BLACK;
					grandfther->_col = RED;

					cur = grandfther;
					parent = cur->_parent;
				}
				else
				{
					if (cur == parent->_left)
					{
						RotateR(parent);
						swap(parent, cur);
					}

					RotateL(grandfther);
					grandfther->_col = RED;
					parent->_col = BLACK;
				}
			}
		}

		_root->_col = BLACK;

		return true;
	}

	void RotateL(Node* parent)
	{
		Node* subR = parent->_right;
		Node* subRL = subR->_left;

		parent->_right = subRL;
		if (subRL)
			subRL->_parent = parent;

		subR->_left = parent;
		Node* ppNode = parent->_parent;
		parent->_parent = subR;

		// 1��ԭ��parent��������ĸ�������subR�Ǹ�
		// 2��parentΪ������ֻ���������е��������ı����ӹ�ϵ����ôsubRҪ��������λ��
		if (_root == parent)
		{
			_root = subR;
			subR->_parent = nullptr;
		}
		else
		{
			if (ppNode->_left == parent)
				ppNode->_left = subR;
			else
				ppNode->_right = subR;

			subR->_parent = ppNode;
		}
	}

	void RotateR(Node* parent)
	{
		Node* subL = parent->_left;
		Node* subLR = subL->_right;

		parent->_left = subLR;
		if (subLR)
			subLR->_parent = parent;

		subL->_right = parent;
		Node* ppNode = parent->_parent;
		parent->_parent = subL;

		if (_root == parent)
		{
			_root = subL;
			subL->_parent = nullptr;
		}
		else
		{
			if (ppNode->_left == parent)
				ppNode->_left = subL;
			else
				ppNode->_right = subL;

			subL->_parent = ppNode;
		}
	}


	void _InOrder(Node* root)
	{
		if (root == nullptr)
			return;

		_InOrder(root->_left);
		//cout << root->_kv.first << ":" << root->_kv.second << endl;
		_InOrder(root->_right);
	}

	void InOrder()
	{
		_InOrder(_root);
	}

	bool IsValidRBTree()
	{
		Node* pRoot = _root;
		// ����Ҳ�Ǻ����
		if (nullptr == pRoot)
			return true;

		// �����ڵ��Ƿ��������
		if (BLACK != pRoot->_col)
		{
			cout << "Υ����������ʶ������ڵ����Ϊ��ɫ" << endl;
			return false;
		}

		// ��ȡ����һ��·���к�ɫ�ڵ�ĸ���
		size_t blackCount = 0;
		Node* pCur = pRoot;
		while (pCur)
		{
			if (BLACK == pCur->_col)
				blackCount++;

			pCur = pCur->_left;
		}

		// ����Ƿ��������������ʣ�k������¼·���к�ɫ�ڵ�ĸ���
		size_t k = 0;
		return _IsValidRBTree(pRoot, k, blackCount);
	}

	bool _IsValidRBTree(Node* pRoot, size_t k, const size_t blackCount)
	{
		//�ߵ�null֮���ж�k��black�Ƿ����
		if (nullptr == pRoot)
		{
			if (k != blackCount)
			{
				cout << "Υ�������ģ�ÿ��·���к�ɫ�ڵ�ĸ���������ͬ" << endl;
				return false;
			}
			return true;
		}

		// ͳ�ƺ�ɫ�ڵ�ĸ���
		if (BLACK == pRoot->_col)
			k++;

		// ��⵱ǰ�ڵ�����˫���Ƿ�Ϊ��ɫ
		Node* pParent = pRoot->_parent;
		if (pParent && RED == pParent->_col && RED == pRoot->_col)
		{
			cout << "Υ����������û������һ��ĺ�ɫ�ڵ�" << endl;
			return false;
		}

		return _IsValidRBTree(pRoot->_left, k, blackCount) &&
			_IsValidRBTree(pRoot->_right, k, blackCount);
	}

	Node* Find(const K& key)
	{
		KOfT koft;
		Node* cur = _root;
		while (cur)
		{
			if (koft(cur->_data) < koft(data))
			{
				cur = cur->_right;
			}
			else if (koft(cur->_data) > koft(data))
			{
				cur = cur->_left;
			}
			else
			{
				return cur;
			}
		}

		return nullptr;
	}

private:
	Node* _root = nullptr;
};

//void TestRBTree()
//{
//	//int a[] = { 16, 3, 7, 11, 9, 26, 18, 14, 15 };
//	int a[] = { 4, 2, 6, 1, 3, 5, 15, 7, 16, 14 };
//	RBTree<int, int> t;
//	for (auto e : a)
//	{
//		t.Insert(make_pair(e, e));
//	}
//
//	t.InOrder();
//	cout << t.IsValidRBTree() << endl;
//}