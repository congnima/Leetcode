//Reverse Linked List
//
//Reverse a singly linked list.
//
//click to show more hints.
//
//Hint:
//A linked list can be reversed either iteratively or recursively.
//Could you implement both ?


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
	ListNode* reverseList(ListNode* head)
	{
		if (nullptr == head)
			return nullptr;

		ListNode* tail = head;
		ListNode* p = tail->next;

		while (nullptr != p)
		{
			tail->next = p->next;
			p->next = head;
			head = p;

			p = tail->next;
		}

		return head;
	}
};