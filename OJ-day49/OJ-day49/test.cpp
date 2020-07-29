#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;



//二叉树的深度
/*
struct TreeNode {
int val;
struct TreeNode *left;
struct TreeNode *right;
TreeNode(int x) :
val(x), left(NULL), right(NULL) {
}
};*/


class Solution {
public:
	void TreeDepthHelper(TreeNode *pRoot, int cur, int &max)
	{
		if (pRoot == nullptr)
		{
			if (max < cur){
				max = cur;
			}
			return;
		}
		TreeDepthHelper(pRoot->left, cur + 1, max);
		TreeDepthHelper(pRoot->right, cur + 1, max);
	}
	int TreeDepth(TreeNode* pRoot)
	{
		if (pRoot == nullptr){
			return 0;
		}
		int depth = 0;
		int max = 0;
		TreeDepthHelper(pRoot, depth, max);
		return max;
	}
};


