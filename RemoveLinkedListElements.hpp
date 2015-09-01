//Remove Linked List Elements
//
//Remove all elements from a linked list of integers that have value val.
//
//Example
//Given : 1 --> 2 --> 6 --> 3 --> 4 --> 5 --> 6, val = 6
//	Return: 1 --> 2 --> 3 --> 4 --> 5
//
//		Credits:
//Special thanks to @mithmatt for adding this problem and creating all test cases.


#include "LinkList.hpp"
/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/
class Solution 
{
public:
	ListNode* removeElements(ListNode* head, int val) 
	{
		ListNode* p = head;

		while (nullptr != head && head->val == val)
		{
			p = head;
			head = head->next;
			free(p);
		}

		if (nullptr == head)
			return head;

		p = head;
		while (nullptr != p->next)
		{
			if (val == p->next->val)
			{
				ListNode* tmp = p->next;
				p->next = tmp->next;
				free(tmp);
			}
			else
			{
				p = p->next;
			}
		}

		return head;
	}
};