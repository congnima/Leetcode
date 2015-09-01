//Remove Nth Node From End of List 

//Given a linked list, remove the nth node from the end of list and return its head.
//
//For example,
//
//Given linked list : 1->2->3->4->5, and n = 2.
//
//After removing the second node from the end, the linked list becomes 1->2->3->5.
//Note :
//	 Given n will always be valid.
//	 Try to do this in one pass.



/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/

#include <cstddef> 
#include <cstdlib>

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode *removeNthFromEnd(ListNode *head, int n) {
		if (NULL == head)
			return NULL;

		ListNode* current = head;
		ListNode* prob = head;
		ListNode* previous = head;

		int adj = n - 1;

		while (adj--)
		{
			prob = prob->next;
		}

		while (NULL != prob->next)
		{
			previous = current;
			current = current->next;
			prob = prob->next;
		}

		if (current == head && NULL == head->next)
			return NULL;

		if (current == head && NULL != head->next)
		{
			head = current->next;
			return head;
		}
		//delete this node
		previous->next = current->next;
		free(current);

		return head;
	}
};