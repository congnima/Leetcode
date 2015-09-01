//Binary Tree Inorder Traversal
//
//Given a binary tree, return the inorder traversal of its nodes' values.
//
//For example :
//Given binary tree{ 1, #, 2, 3 },
//	1
//	  \
//	   2
//    /
//   3
//return[1, 3, 2].


/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/

#include <iostream>
#include <vector>
#include <stack>
#include "Tree.hpp"
using namespace std;

class Solution {
public:
	vector<int> inorderTraversal(TreeNode* root) 
	{
		std::vector<int> res;
		if (nullptr == root)
			return res;

		
		std::stack<TreeNode*> stack;

		stack.push(root);
		root = root->left;

		while (!stack.empty())
		{
			if (nullptr == root)
			{
				root = stack.top();
				stack.pop();

				res.push_back(root->val);

				root = root->right;

				if (nullptr != root)
				{
					stack.push(root);
					root = root->left;
				}

			}
			else
			{
				stack.push(root);

				root = root->left;
			}
		}


		return res;
	}
};