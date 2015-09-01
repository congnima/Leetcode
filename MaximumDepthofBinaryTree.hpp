//Maximum Depth of Binary Tree
//
//Given a binary tree, find its maximum depth.
//
//The maximum depth is the number of nodes along the 
//longest path from the root node down to the farthest leaf node.


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