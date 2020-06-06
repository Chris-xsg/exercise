#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include<iostream>
using namespace std;

//Binary_Search_Tree 搜索二叉树/排序二叉树
template<class K>
struct BSTreeNode
{
	BSTreeNode<K>* _left;
	BSTreeNode<K>* _right;
	K _key;

	BSTreeNode(const K& key)
		:_left(nullptr)
		, _right(nullptr)
		, _key(key)
	{}
};

template<class K>
class BSTree
{
	typedef BSTreeNode<K> Node;
public:
	bool Insert(const K& key)
	{
		if (_root == nullptr)
		{
			_root = new Node(key);
			return true;
		}

		Node* parent = nullptr;
		Node* cur = _root;
		while (cur)
		{
			if (cur->_key < key)
			{
				parent = cur;
				cur = cur->_right;
			}
			else if (cur->_key > key)
			{
				parent = cur;
				cur = cur->_left;
			}		
			else
			{
				return false;
			}
		}

		cur = new Node(key);
		if (parent->_key < cur->_key)
		{
			parent->_right = cur;
		}
		else
		{
			parent->_left = cur;
		}

		return true;
	}

	// 递归的方式插入
	bool _InsertR(Node*& root, const K& key)
	{
		if (root == nullptr)
			root = new Node(key);

		if (root->_key < key)
			return _InsertR(root->_right, key);
		else if (root->_key > key)
			return _InsertR(root->_left, key);
		else
			return false;
	}

	bool InsertR(const K& key)
	{
		return _InsertR(_root, key);
	}

	Node* Find(const K& key)
	{
		Node* cur = _root;
		while (cur)
		{
			if (cur->_key < key)
				cur = cur->_right;	
			else if (cur->_key > key)
				cur = cur->_left;
			else
				return cur;
		}

		return NULL;
	}

	Node* _FindR(Node* root, const K& key)
	{
		if (root == nullptr)
			return nullptr;

		if (root->_key < key)
			return _FindR(root->_right, key);
		else if (root->_key > key)
			return _FindR(root->_left, key)
		else
		return  root;
	}

	Node* FindR(const K& key)
	{
		return _FindR(_root, key);
	}

	bool _EraseR(Node*& cur, const K& key)//递归
	{
		if (cur == nullptr)
			return false;

		if (cur->_key < key)
		{
			return _EraseR(cur->_right, key);
		}
		else if (cur->_key > key)
		{
			return _EraseR(cur->_left, key);
		}
		else
		{
			// 1.左为空
			// 2.右为空
			// 3.左右都不为空
			Node* del = cur;
			if (cur->_left == nullptr)
			{
				cur = cur->_right;
				delete del;
				return true;
			}
			else if (cur->_right == nullptr)
			{
				cur = cur->_left;
				delete del;
				return true;
			}
			else
			{
				// 替换法删除  左树的最大节点(最右节点) 或者是右树的最小节点(最左节点)
				Node* minNode = cur->_right;
				while (minNode->_left)
				{
					minNode = minNode->_left;
				}
				cur->_key = minNode->_key;

				// 转换成去右子树中删除这个最小节点的值的子问题。
				return _EraseR(cur->_right, minNode->_key);
			}
		}
	}

	bool EraseR(const K& key)
	{
		return _EraseR(_root, key);
	}



	bool Erase(const K& key)//非递归
	{
		Node* parent = nullptr;
		Node* cur = _root;
		while (cur)
		{
			if (cur->_key < key)
			{
				parent = cur;
				cur = cur->_right;
			}
			else if (cur->_key > key)
			{
				parent = cur;
				cur = cur->_left;
			}
			else
			{
				// 1.左为空
				// 2.右为空
				// 3.左右都不为空
				if (cur->_left == nullptr)
				{
					if (parent == nullptr)
					{
						_root = cur->_right;
					}
					else
					{
						if (cur == parent->_left)
							parent->_left = cur->_right;
						else
							parent->_right = cur->_right;
					}

					delete cur;
				}
				else if (cur->_right == nullptr)
				{
					if (parent == nullptr)
					{
						_root = cur->_left;
					}
					else
					{
						if (cur == parent->_left)
							parent->_left = cur->_left;
						else
							parent->_right = cur->_left;
					}

					delete cur;
				}
				else
				{
					// 替换法删除  左树的最大节点(最右节点) 或者是右树的最小节点(最左节点)
					Node* minNodeParent = cur;  // 这里要注意不能初始化给空
					Node* minNode = cur->_right;
					while (minNode->_left)
					{
						minNodeParent = minNode;
						minNode = minNode->_left;
					}

					swap(cur->_key, minNode->_key);
					// 转换成删除minNode

					// 因为minNode是作为空的节点，可以直接删除 
					if (minNodeParent->_right == minNode)
						minNodeParent->_right = minNode->_right;
					else
						minNodeParent->_left = minNode->_right;

					delete minNode;
				}

				return true;
			}
		}

		return false;
	}

	void _InOrder(Node* root)
	{
		if (root == nullptr)
			return;

		_InOrder(root->_left);
		cout << root->_key << " ";
		_InOrder(root->_right);
	}

	void InOrder()
	{
		_InOrder(_root);
		cout << endl;
	}
private:
	Node* _root = nullptr;
};

void TestBSTree()
{
	int a[] = { 5, 3, 4, 1, 7, 8, 2, 6, 0, 9 };
	BSTree<int> bst;
	for (auto e : a)
	{
		//bst.Insert(e);
		bst.InsertR(e);
	}
	bst.InOrder();

	bst.Erase(2);
	bst.InOrder();
	bst.Erase(8);
	bst.InOrder();
	bst.Erase(1);
	bst.InOrder();
	bst.Erase(5);
	bst.InOrder();

	for (auto e : a)
	{
		bst.EraseR(e);
		bst.InOrder();
	}
	bst.InOrder();
}

int main()
{
	TestBSTree();


	return 0;
}