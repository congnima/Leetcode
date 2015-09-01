//Minimum Depth of Binary Tree
//
//Given a binary tree, find its minimum depth.
//
//The minimum depth is the number of nodes along 
//the shortest path from the root node down to the nearest leaf node.


#include "Tree.hpp"
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
	int minDepth(TreeNode *root) {
		if (NULL == root)
			return 0;
		
		if (NULL == root->left && NULL == root->right)
			return 1;
		else if (NULL == root->left && NULL != root->right)
			return minDepth(root->right) + 1;
		else if (NULL != root->left && NULL == root->right)
			return minDepth(root->left) + 1;

		int lhs = minDepth(root->left);
		int rhs = minDepth(root->right);

		return ((lhs > rhs) ? rhs : lhs)+1;
	}
};