//Binary Search Tree Iterator
//
//Implement an iterator over a binary search tree(BST).Your iterator will be initialized with 
//the root node of a BST.
//
//Calling next() will return the next smallest number in the BST.
//
//Note: next() and hasNext() should run in average O(1) time and uses O(h) memory, where h is 
//	  the height of the tree.


#include "Tree.hpp"
#include <stack>
/**
* Definition for binary tree
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/
class BSTIterator 
{
public:
	BSTIterator(TreeNode *root) 
	{
		push(root);
	}

	/** @return whether we have a next smallest number */
	bool hasNext() 
	{
		return !stck.empty();
	}

	/** @return the next smallest number */
	int next() 
	{
		TreeNode* p = stck.top();
		int res = p->val;
		stck.pop();

		push(p->right);

		return res;
	}

	void push(TreeNode* p)
	{
		while (nullptr != p)
		{
			stck.push(p);
			p = p->left;
		}
	}

private:
	std::stack<TreeNode*> stck;
};

/**
* Your BSTIterator will be called like this:
* BSTIterator i = BSTIterator(root);
* while (i.hasNext()) cout << i.next();
*/