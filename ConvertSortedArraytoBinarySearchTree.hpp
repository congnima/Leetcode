//Convert Sorted Array to Binary Search Tree
//
//
//Given an array where elements are sorted in ascending order, 
//convert it to a height balanced BST.


#include "Tree.hpp"
#include <vector>
using namespace std;

/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/
class Solution {
public:
	TreeNode* sortedArrayToBST(vector<int>& nums)
	{
		if (0 == nums.size())
			return nullptr;
		else
			return sortedArrayToBST(nums, 0, nums.size() - 1);
	}

	TreeNode* sortedArrayToBST(std::vector<int>& nums,
		int l , int u)
	{
		if (l > u)
			return nullptr;
		else if (l == u)
			return new TreeNode(nums[l]);

		int m = (l + u) / 2;

		TreeNode* root = new TreeNode(nums[m]);
		root->left = sortedArrayToBST(nums, l, m - 1);
		root->right = sortedArrayToBST(nums, m + 1, u);

		return root;
	}
};