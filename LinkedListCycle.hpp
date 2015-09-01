//Linked List Cycle
//
//Given a linked list, determine if it has a cycle in it.
//
//Follow up :
//Can you solve it without using extra space ?


#include "LinkList.hpp"
/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/
class Solution {
public:
	bool hasCycle(ListNode *head) {
		if (NULL == head)
			return false;

		ListNode* p = head;
		ListNode* q = p->next;

		while (NULL != q)
		{
			p = p->next;

			for (int i = 2; i > 0 && NULL != q; i--)
			{
				q = q->next;
				if (q == p)
					return true;
			}
				

		}

		if (NULL == q)
			return false;
	}
};