//Flatten Binary Tree to Linked List
//
//Given a binary tree, flatten it to a linked list in - place.
//
//For example,
//Given
//
//		1
//	   / \
//    2   5
//   / \   \
//  3   4   6
//The flattened tree should look like :
//  1
//	\
//	 2
//	  \
//	   3
//		\
//		 4
//	      \
//		   5
//			\
//			 6


#include "Tree.hpp"
#include <vector>
/**
* Definition for binary tree
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/
class Solution {
public:
	void flatten(TreeNode *root) {
		if (NULL == root)
			return;

		preOrder(root);

		for (int i = 0; i < vctTree.size() - 1; i++)
		{
			vctTree[i]->left = NULL;
			vctTree[i]->right = vctTree[i + 1];
		}

		vctTree.back()->left = NULL;
		vctTree.back()->right = NULL;

	}
	void preOrder(TreeNode* root){
		if (NULL == root)
			return;

		vctTree.push_back(root);
		
		preOrder(root->left);
		preOrder(root->right);
	}
private:
	std::vector<TreeNode*> vctTree;
};