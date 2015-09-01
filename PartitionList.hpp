//Partition List
//
//Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.
//
//You should preserve the original relative order of the nodes in each of the two partitions.
//
//For example,
//Given 1->4->3->2->5->2 and x = 3,
//return 1->2->2->4->3->5.


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
	ListNode *partition(ListNode *head, int x) {
		if (NULL == head)
			return head;

		ListNode* p = head;
		ListNode* q = NULL;
		ListNode* prev = NULL;
		if (NULL != p->next)
			q = p->next;
		else
			return head;

		while (NULL != q && p->val < x && q->val < x)
		{
			p = q;
			q = q->next;
		}

		if (NULL == q)
			return head;

		if (p->val < x && q->val >= x)
			prev = p;

		while (NULL != q)
		{
			if (q->val < x)
			{
				p->next = q->next;
				if (NULL != prev)
				{
					q->next = prev->next;
					prev->next = q;
				}
				else
				{
					q->next = head;
					head = q;
				}
				prev = q;

				q = p->next;
			}
			else
			{
				p = q;
				q = q->next;
			}
		}

		return head;
	}
};