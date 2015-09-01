//Insertion Sort List
//
//Sort a linked list using insertion sort.


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
	ListNode *insertionSortList(ListNode *head) {
		if (NULL == head)
			return NULL;

		ListNode* p = head->next;

		if (NULL == p)
			return head;

		head->next = NULL;

		ListNode* q = NULL;
		ListNode* tmp = NULL;

		while (p != NULL)
		{
			if (p->val < head->val)
			{
				tmp = p;
				p = p->next;

				tmp->next = head;
				head = tmp;
				continue;
			}
			
			q = head;

			while (q->next != NULL && q->next->val < p->val)
			{
				q = q->next;
			}

			tmp = q->next;
			q->next = p;
			p = p->next;
			q->next->next = tmp;
		}

		return head;
	}
};