//Merge Two Sorted Lists
//
//Merge two sorted linked lists and return it as a new list.
//The new list should be made by splicing together the nodes of the first two lists.


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
	ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
		if (NULL == l1 && NULL != l2)
			return l2;
		if (NULL == l2 && NULL != l1)
			return l1;
		if (NULL == l1 && NULL == l2)
			return NULL;

		ListNode* head = NULL;
		ListNode* end = NULL;

		while (NULL != l1 && NULL != l2)
		{
			if (l1->val <= l2->val)
			{
				if (NULL == head)
					end = head = l1;
				else
				{
					end->next = l1;
					end = l1;
				}

				l1 = l1->next;
			}
			else
			{
				if (NULL == head)
					end = head = l2;
				else
				{
					end->next = l2;
					end = l2;
				}

				l2 = l2->next;
			}
		}

		if (NULL != l1)
		{
			end->next = l1;
			end = end->next;
		}
		if (NULL != l2)
		{
			end->next = l2;
			end = end->next;
		}

		while (NULL != end->next)
			end = end->next;

		end->next = NULL;

		return head;
	}
};