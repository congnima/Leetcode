

#ifndef _GEN_TREE_
#define _GEN_TREE_

#include <cstddef>
#include <fstream>
#include <deque>
#include <cctype>

struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	TreeNode() :val(0), left(NULL), right(NULL){}
};

class Tree
{
public:
	Tree(TreeNode* p = NULL);
	Tree(std::string serialTree);
	Tree(const Tree& tree);
	Tree& operator=(const Tree& tree);
	~Tree();
	
	TreeNode* IniTree();
private:
	TreeNode* root; //root node
	std::deque<TreeNode*> queTree;
};

Tree::Tree(TreeNode* p)
{

	if (NULL == p);

	root = p;
}

//leetcode style
//The serialization of a binary tree follows a level order traversal, 
//where '#' signifies a path terminator where no node exists below.
//for example:
//			1
//		   / \
//		  2   3
//			 /
//			4
//			 \
//			  5
//The above binary tree is serialized as "{1,2,3,#,#,4,#,#,5}"
Tree::Tree(std::string serialTree) :root(NULL)
{
	if (serialTree.empty())
		return;

	std::string strNode;

	for (auto x : serialTree)
	{
		if (std::isalnum(x))
			strNode += x;
		else
		{
			
			if (x == '#')
				queTree.push_back(NULL);
			else if (!strNode.empty())
			{
				queTree.push_back(new TreeNode(atoi(strNode.c_str())));
				strNode.clear();
			}
			
		}
	}
}

TreeNode* Tree::IniTree()
{
	if (queTree.empty())
		return NULL;

	if (root != NULL)
		return root;

	std::deque<TreeNode*> queParentNode;
	
	root = queTree.front();
	queParentNode.push_back(root);
	queTree.pop_front();

	while (!queParentNode.empty() && !queTree.empty())
	{
		if (queTree.front() != NULL)
		{
			queParentNode.front()->left = queTree.front();
			queParentNode.push_back(queTree.front());
		}
		queTree.pop_front();

		if (!queTree.empty() && queTree.front() != NULL)
		{
			queParentNode.front()->right = queTree.front();
			queParentNode.push_back(queTree.front());
		}
		if (!queTree.empty())
			queTree.pop_front();

		queParentNode.pop_front();
	}

	return root;
}

Tree::~Tree()
{
	//delete root;//?
}



#endif