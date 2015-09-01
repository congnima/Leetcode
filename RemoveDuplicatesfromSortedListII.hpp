//Remove Duplicates from Sorted List II
//
//Given a sorted linked list, delete all nodes that have duplicate numbers, 
//leaving only distinct numbers from the original list.
//
//For example,
//Given 1->2->3->3->4->4->5, return 1->2->5.
//Given 1->1->1->2->3, return 2->3.

/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/
#include "LinkList.hpp"

class Solution 
{
public:
	ListNode *deleteDuplicates(ListNode *head) 
	{
		if (nullptr == head)
			return nullptr;

		ListNode* p= new ListNode(INT_MIN);
		p->next = head;
		ListNode* q = head;

		head = p;

		while (nullptr != q && nullptr != q->next)
		{
			while (nullptr != q && nullptr != q->next && 
				q->val == q->next->val)
			{
				ListNode* tmp = q;
				q = q->next;
				delete tmp;
			}

			if (p->next != q && nullptr != q)
			{
				q = q->next;
				p->next = q;
			}
			else
			{
				p = q;
				q = q->next;
			}
		}

		ListNode* tmp = head;
		head = head->next;
		delete tmp;

		return head;
	}
};