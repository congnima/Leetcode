//Kth Smallest Element in a BST
//
//Given a binary search tree, 
//write a function kthSmallest to find the kth smallest element in it.
//
//Note:
//You may assume k is always valid, 1 ¡Ü k ¡Ü BST's total elements.
//
//Follow up :
//What if the BST is modified(insert / delete operations) often 
//and you need to find the kth smallest frequently ? 
//How would you optimize the kthSmallest routine ?


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
	int kthSmallest(TreeNode* root, int& k) 
	{
		if (nullptr == root)
			return INT_MAX;

		int res = kthSmallest(root->left, k);
		if (res != INT_MAX)
			return res;
		if (0 == --k)
			return root->val;
		res = kthSmallest(root->right, k);
		if (res != INT_MAX)
			return res;
	}
};