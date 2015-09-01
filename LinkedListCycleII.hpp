//Linked List Cycle II
//
//Given a linked list, return the node where the cycle begins.If there is no cycle, return null.
//
//Follow up :
//Can you solve it without using extra space ?


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
	ListNode *detectCycle(ListNode *head) 
	{
		if (nullptr == head)
			return nullptr;

		ListNode* slow = head;
		ListNode* fast = head;

		while (nullptr != fast && nullptr != fast->next)
		{
			slow = slow->next;
			fast = fast->next->next;

			if (slow == fast)
			{
				while (head != slow)
				{
					head = head->next;
					slow = slow->next;
				}
				if (head == slow)
					return head;
			}
		}

		if (nullptr == fast || nullptr == fast->next)
			return nullptr;
	}
};