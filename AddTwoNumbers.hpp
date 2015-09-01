//Add Two Numbers

//You are given two linked lists representing two non - negative numbers.
//The digits are stored in reverse order and each of their nodes contain a single 
//digit.Add the two numbers and return it as a linked list.
//
//Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
//Output : 7 -> 0 -> 8

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
	ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
		if (NULL == l1 && NULL == l2)
			return NULL;
		if (NULL != l1 && NULL == l2)
			return l1;
		if (NULL == l1 && NULL != l2)
			return l2;

		int carry = 0;
		ListNode* zeroNode = new ListNode(0);
		ListNode* head = l1;

		while (!(NULL == l1 && NULL == l2))
		{

			if (NULL == l2)
				l2 = zeroNode;

			l1->val = l1->val + l2->val + carry;
			carry = l1->val / 10;
			l1->val = l1->val % 10;


			if ((NULL == l1->next && NULL == l2->next && 0 != carry) ||
				NULL == l1->next && NULL != l2->next)
			{
				l1->next = new ListNode(0);
			
			}
			l1 = l1->next;
			l2 = l2->next;
			
		}


		return head;
	}
};