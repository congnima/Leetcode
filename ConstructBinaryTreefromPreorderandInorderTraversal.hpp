//Construct Binary Tree from Preorder and Inorder Traversal

//Given preorder and inorder traversal of a tree, construct the binary tree.

//Note:
//You may assume that duplicates do not exist in the tree.


/**
* Definition for binary tree
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/
#include <vector>
#include "Tree.hpp"
using namespace std;

class Solution {
public:
	TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) 
	{
		if (0 == inorder.size())
			return nullptr;

		return buildTree(preorder.begin(), preorder.end(),
			inorder.begin(), inorder.end());
	}

	TreeNode* buildTree(std::vector<int>::iterator pre_begin,
		std::vector<int>::iterator pre_end,
		std::vector<int>::iterator in_begin,
		std::vector<int>::iterator in_end)
	{
		if (pre_begin == pre_end ||
			in_begin == in_end)
			return nullptr;

		auto root = new TreeNode(*pre_begin);

		auto it = std::find(in_begin, in_end, *pre_begin);
		auto left_length = std::distance(pre_begin, it);

		if (1 != left_length)
		{
			root->left = buildTree(std::next(pre_begin), std::next(pre_begin,left_length + 2),
				in_begin,it);
			root->right = buildTree(std::next(pre_begin,left_length + 2),pre_end,
				std::next(it),in_end);
		}

		return root;
	}

};