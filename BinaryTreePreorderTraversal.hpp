//Binary Tree Preorder Traversal
//
//Given a binary tree, return the preorder traversal of its nodes' values.
//
//For example :
//Given binary tree{ 1, #, 2, 3 },
//	1
//	 \
//	 2
//  /
// 3
//return[1, 2, 3].
//
//Note: Recursive solution is trivial, could you do it iteratively ?

/**
* Definition for binary tree
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/
#include "Tree.hpp"
#include <vector>
#include <stack>

using namespace std;

class Solution 
{
public:
	vector<int> preorderTraversal(TreeNode *root) 
	{
		std::vector<int> vec;

		if (nullptr == root)
			return vec;

		std::stack<TreeNode*> stack;
		
		stack.push(root);

		TreeNode* tmp = nullptr;

		while (!stack.empty())
		{
			tmp = stack.top();
			stack.pop();
			vec.push_back(tmp->val);

			if (nullptr != tmp->right)
				stack.push(tmp->right);
			if (nullptr != tmp->left)
				stack.push(tmp->left);
		}

		return vec;
	}
};