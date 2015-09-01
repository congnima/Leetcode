//Binary Tree Postorder Traversal
//
//Given a binary tree, return the postorder traversal of its nodes' values.
//
//For example :
//Given binary tree{ 1, #, 2, 3 },
//1
//\
//2
///
//3
//return[3, 2, 1].
//
//Note: Recursive solution is trivial, could you do it iteratively ?


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
class Solution 
{
public:
	vector<int> postorderTraversal(TreeNode* root) 
	{
		std::vector<int> res;

		if (nullptr == root)
			return res;

		std::vector<TreeNode*> que;
		que.push_back(root);

		typedef std::vector<TreeNode*>::iterator IT;
		typedef std::vector<TreeNode*>::reverse_iterator RIT;

		for (IT it = que.begin(); it != que.end(); it++)
		{
			if (nullptr != (*it)->left)
			{
				it = que.insert(it + 1, (*it)->left);
				it = it - 1;
			}
				
			if (nullptr != (*it)->right)
			{
				it = que.insert(it + 1, (*it)->right);
				it = it - 1;
			}
				
		}

		for (RIT it = que.rbegin(); it != que.rend(); it++)
		{
			res.push_back((*it)->val);
		}

		return res;
	}
};