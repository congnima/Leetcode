//Reorder List

//Given a singly linked list L: L0¡úL1¡ú¡­¡úLn-1¡úLn,
//reorder it to : L0¡úLn¡úL1¡úLn - 1¡úL2¡úLn - 2¡ú¡­
//
//You must do this in - place without altering the nodes' values.
//
//For example,
//Given{ 1, 2, 3, 4 }, reorder it to{ 1, 4, 2, 3 }.


#include "LinkList.hpp"
#include <cstddef>

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
	void reorderList(ListNode *head) {

		if (NULL == head)
			return;
		if (NULL == head->next)
			return;

		ListNode* mid = head;
		ListNode* end = head;
		ListNode* pre = NULL;

		while (end != NULL)
		{
			pre = mid;
			mid = mid->next;

			if (end != NULL)
				end = end->next;
			if (end != NULL)
				end = end->next;
		}

		pre->next = NULL;

		mid = reverseList(mid);
		head = mergeList(head, mid);
	}

	ListNode* reverseList(ListNode* head){
		if (NULL == head)
			return NULL;
		if (NULL == head->next)
			return head;

		ListNode* current = head;
		ListNode* next = current->next;

		head = NULL;

		while (NULL != current)
		{

			current->next = head;
			head = current;

			current = next;
			if (NULL != current)
				next = current->next;
		}

		return head;
	}

	ListNode* mergeList(ListNode* fst, ListNode* sec){
		if (NULL == fst && NULL == sec)
			return NULL;
		if (NULL == fst)
			return sec;
		if (NULL == sec)
			return fst;

		ListNode* p = fst;
		ListNode* q = p->next;
		while (sec != NULL)
		{
			p->next = sec;

			sec = sec->next;
			p->next->next = q;

			p = p->next;

			if (q != NULL)
			{
				q = q->next;
				p = p->next;
			}
		}

		return fst;
	}
};