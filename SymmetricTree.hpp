//Symmetric Tree

//Given a binary tree, check whether it is a mirror of itself
//(ie, symmetric around its center).

//For example, this binary tree is symmetric :

//		1
//	   / \
//	  2   2
//	 / \ / \
//	3  4 4  3
//But the following is not :
//		1
//	   / \
//	  2   2
//	   \   \
//	   3    3

#include "Tree.hpp"
#include <vector>
#include <deque>
#include <cmath>

class Solution {
public:
	bool isSymmetric(TreeNode *root) {
		if (NULL == root)
			return true;
		Flip(root->right);
		return isEqualTree(root->left, root->right);
	}
	void Flip(TreeNode *root){
		TreeNode *tmp;

		if (NULL == root)
			return;

		if (root->left == NULL && root->right == NULL)
			return;

		tmp = root->left;
		root->left = root->right;
		root->right = tmp;

		Flip(root->left);
		Flip(root->right);
	}
	bool isEqualTree(TreeNode* lhs, TreeNode* rhs)
	{
		if (lhs == NULL && rhs == NULL)
			return true;
		else if ((lhs == NULL && rhs != NULL) ||
			(lhs != NULL && rhs == NULL))
			return false;
		else if (lhs != NULL && rhs != NULL)
			return ((lhs->val == rhs->val) &&
				isEqualTree(lhs->left, rhs->left) &&
				isEqualTree(lhs->right, rhs->right));
	}
};