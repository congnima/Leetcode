//Balanced Binary Tree
//
//Given a binary tree, determine if it is height - balanced.
//
//For this problem, a height - balanced binary tree is defined as a binary tree 
//in which the depth of the two subtrees of every node never differ by more than 1.


#include "Tree.hpp"
#include <cmath>
/**
* Definition for binary tree
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/
class Solution {
public:
	bool isBalanced(TreeNode *root) {
		if (NULL == root)
			return true;

		if (NULL == root->left && NULL != root->right)
			return (maxDepth(root->right) <= 1);
		else if (NULL != root->left && NULL == root->right)
			return (maxDepth(root->left) <= 1);
		else if (NULL == root->left && NULL == root->right)
			return true;
		else return (isBalanced(root->left) &&
			isBalanced(root->right) &&
			std::abs(maxDepth(root->left) - maxDepth(root->right)) <= 1);
	}

	int maxDepth(TreeNode *root) {
		if (NULL == root)
			return 0;
		if (NULL == root->left &&
			NULL == root->right)
			return 1;

		int lhs = maxDepth(root->left);
		int rhs = maxDepth(root->right);

		return (lhs > rhs) ? lhs + 1 : rhs + 1;
	}
};