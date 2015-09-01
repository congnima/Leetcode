//Binary Tree Level Order Traversal
//
//Given a binary tree, return the level order traversal of its nodes
//' values. (ie, from left to right, level by level).
//
//For example :
//Given binary tree{ 3, 9, 20, #, #, 15, 7 },
//3
/// \
//9  20
/// \
//15   7
//return its level order traversal as :
//[
//	[3],
//	[9, 20],
//	[15, 7]
//]

#include <vector>
#include <iostream>
#include "Tree.hpp"
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
class Solution 
{
public:
	vector<vector<int>> levelOrder(TreeNode* root) 
	{
		std::vector<std::vector<int>> res;

		if (nullptr == root)
			return res;

		std::deque<TreeNode*> deque;
		deque.push_back(root);

		std::vector<int> tmp;
		TreeNode* treeNode = nullptr;
		size_t level_size = deque.size();

		while (!deque.empty())
		{
			treeNode = deque.front();
			deque.pop_front();
			
			tmp.push_back(treeNode->val);

			if (nullptr != treeNode->left)
				deque.push_back(treeNode->left);
			if (nullptr != treeNode->right)
				deque.push_back(treeNode->right);
			
			if (--level_size == 0)
			{
				res.push_back(tmp);
				tmp.clear();

				level_size = deque.size();
			}

		}

		return res;
	}
};