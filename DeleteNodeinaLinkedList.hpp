//Delete Node in a Linked List
//
//Write a function to delete a node(except the tail)
//in a singly linked list, given only access to that node.
//
//Supposed the linked list is 1 -> 2 -> 3 -> 4 
//and you are given the third node with value 3, 
//the linked list should become 1 -> 2 -> 4 after calling your function.


#include "LinkList.hpp"
/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/
class Solution 
{
public:
	void deleteNode(ListNode* node) 
	{
		if (nullptr == node)
			return;

		ListNode* pCurrent = node;
		ListNode* pNext = node->next;

		while (nullptr != pNext)
		{
			pCurrent->val = pNext->val;

			if (nullptr == pNext->next)
				pCurrent->next = nullptr;
			else
				pCurrent = pNext;

			pNext = pNext->next;
		}
	}
};