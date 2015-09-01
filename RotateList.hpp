//Rotate List
//
//Given a list, rotate the list to the right by k places, where k is non - negative.
//
//For example :
//Given 1->2->3->4->5->NULL and k = 2,
//return 4->5->1->2->3->NULL.


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
	ListNode *rotateRight(ListNode *head, int k) {
		if (NULL == head)
			return NULL;

		if (0 == k)
			return head;

		ListNode* p = head;
		ListNode* q = head;

		while (k--)
		{
			if (NULL == q->next)
			{
				q->next = head;
			}
			q = q->next;
		}

		while (q->next != head && q->next != NULL)
		{
			p = p->next;
			q = q->next;
		}

		q->next = head;
		head = p->next;
		p->next = NULL;

		return head;
	}
};