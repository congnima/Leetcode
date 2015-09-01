//Validate Binary Search Tree
//
//Given a binary tree, determine if it is a valid binary search tree(BST).
//
//Assume a BST is defined as follows :
//
//The left subtree of a node contains only nodes with keys less than the node's key.
//The right subtree of a node contains only nodes with keys greater than the node's key.
//Both the left and right subtrees must also be binary search trees.


#include "Tree.hpp"
/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/
class Solution 
{
public:
	bool isValidBST(TreeNode* root) 
	{
		if (nullptr == root || (nullptr == root->left && nullptr == root->right))
			return true;

		if (nullptr == root->left && nullptr != root->right)
			return root->right->val > root->val
			&& isValidBST(root->right);
		else if (nullptr != root->left && nullptr == root->right)
			return root->left->val < root->left->val
			&& isValidBST(root->left);
		else
			return root->left->val < root->val
			&& root->right->val > root->val
			&& isValidBST(root->left)
			&& isValidBST(root->right);
	}
};