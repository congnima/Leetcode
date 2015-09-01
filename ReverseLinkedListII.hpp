//Reverse a linked list from position m to n.Do it in - place and in one - pass.
//
//For example :
//Given 1->2->3->4->5->NULL, m = 2 and n = 4,
//
//return 1->4->3->2->5->NULL.
//
//Note :
//	 Given m, n satisfy the following condition :
//1 ¡Ü m ¡Ü n ¡Ü length of list.


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
	ListNode *reverseBetween(ListNode *head, int m, int n) 
	{
		if (nullptr == head)
			return nullptr;

		if (m == n)
			return head;

		ListNode* begin = nullptr;

		n = n - m;

		while (--m > 0)
		{
			if (nullptr == begin)
				begin = head;
			else
				begin = begin->next;
		}

		ListNode tmp(0);
		tmp.next = head;

		ListNode* end = nullptr;
		ListNode* p = nullptr;

		if (nullptr == begin)// case m == 1
			begin = &tmp;

		end = begin->next;
		p = end->next;


		while (--n >= 0 && nullptr != p)
		{
			end->next = p->next;

			p->next = begin->next;
			begin->next = p;

			p = end->next;
		}

		if (begin == &tmp)
			head = begin->next;

		return head;
	}
};