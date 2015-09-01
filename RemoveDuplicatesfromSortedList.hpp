//Remove Duplicates from Sorted List
//
//Given a sorted linked list, delete all duplicates such that each element appear only once.
//
//For example,
//Given 1->1->2, return 1->2.
//Given 1->1->2->3->3, return 1->2->3.


#include "LinkList.hpp"
#include <cstdlib>
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
	ListNode *deleteDuplicates(ListNode *head) {
		if (NULL == head)
			return NULL;

		ListNode* p = head;
		ListNode* q = NULL;

		while (NULL != p->next)
		{
			if (p->val != p->next->val)
				p = p->next;
			else
			{
				q = p->next;
				p->next = q->next;
				delete q;
			}

		}

		return head;
	}
};