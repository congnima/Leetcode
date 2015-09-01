//Binary Tree Right Side View
//
//Given a binary tree, imagine yourself standing on the right side of it, 
//return the values of the nodes you can see ordered from top to bottom.
//
//For example :
//Given the following binary tree,
//		  1            <-- -
//		 /	\
//	    2    3         <-- -
//      \     \
//       5     4       <-- -
//You should return[1, 3, 4].
//
//Credits:
//Special thanks to @amrsaqr for adding this problem and creating all test cases.


#include <iostream>
#include <vector>
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
class Solution {
public:
	vector<int> rightSideView(TreeNode* root)
	{
		std::vector<int> res;

		if (nullptr == root)
			return res;

		std::deque<TreeNode*> deque;
		deque.push_back(root);

		TreeNode* treeNode = nullptr;
		size_t level_size = deque.size();

		while (!deque.empty())
		{
			treeNode = deque.front();
			deque.pop_front();

			if (nullptr != treeNode->left)
				deque.push_back(treeNode->left);
			if (nullptr != treeNode->right)
				deque.push_back(treeNode->right);

			if (--level_size == 0)
			{
				res.push_back(treeNode->val);

				level_size = deque.size();
			}

		}

		return res;
	}
};