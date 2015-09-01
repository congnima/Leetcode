//Copy List with Random Pointer
//
//A linked list is given such that each node contains an additional random pointer which could point 
//to any node in the list or null.
//
//Return a deep copy of the list.

#include <cstdlib>
#include <map>

/**
* Definition for singly-linked list with a random pointer.
* struct RandomListNode {
*     int label;
*     RandomListNode *next, *random;
*     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
* };
*/
struct RandomListNode {
	int label;
	RandomListNode *next, *random;
	RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
	
};

class Solution 
{
public:
	RandomListNode *copyRandomList(RandomListNode *head) 
	{
		if (nullptr == head)
			return nullptr;

		std::map<RandomListNode*,RandomListNode*> mpNode;

		RandomListNode* p = head;

		while (nullptr != p)
		{
			RandomListNode*  tmp = new RandomListNode(p->label);
			tmp->next = p->next;
			tmp->random = p->random;

			mpNode.insert(std::make_pair(p, tmp));

			p = p->next;
		}

		p = mpNode[head];

		while (nullptr != p)
		{
			p->next = mpNode[p->next];
			p->random = mpNode[p->random];

			p = p->next;
		}

		return mpNode[head];
	}
};