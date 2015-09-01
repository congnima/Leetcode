//Sort List

//Sort a linked list in O(nlogn) time using constant space complexity.



/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/

#include <cstddef>
#include "LinkList.hpp"


class Solution {
public:
	ListNode *sortList(ListNode *head)
	{
		if (NULL == head)
			return NULL;
		if (NULL == head->next)
			return head;

		ListNode* left = partitionList(head);
		ListNode* right = head->next;
		head->next = NULL;

		left = sortList(left);
		right = sortList(right);

		return stringList(left, right, head);
	}

	//ListNode* partitionList(ListNode* head)
	//{
	//	ListNode* p = NULL;
	//	ListNode* q = head;

	//	while (q != NULL && q->next != NULL)
	//	{
	//		if (q->next->val < head->val)
	//		{
	//			ListNode* tmp = NULL;
	//			tmp = q->next->next;

	//			q->next->next = p;
	//			p = q->next;

	//			q->next = tmp;
	//		}
	//		else
	//			q = q->next;
	//	}

	//	return p;
	//}
	ListNode* partitionList(ListNode* head)
	{
		ListNode* p = head;
		ListNode* q = NULL;
		ListNode* tmp = NULL;

		while (p->next != NULL && p->next->val < head->val)
			p = p->next;

		q = p;

		while (NULL != q->next)
		{
			if (q->next->val < head->val)
			{
				tmp = q->next;
				q->next = tmp->next;

				tmp->next = p->next;
				p->next = tmp;
			}
			else
				q = q->next;
		}

		if (p != head)
		{
			q = head->next;

			head->next = p->next;
			p->next = NULL;
		}
		else
			q = head;

		return q;
	}

	ListNode* stringList(ListNode* left, ListNode* right, ListNode* mid)
	{
		if (NULL == left)
		{
			mid->next = right;
			return mid;
		}

		ListNode* head = left;

		while (left->next != NULL)
			left = left->next;

		left->next = mid;
		mid->next = right;

		return head;
	}
};