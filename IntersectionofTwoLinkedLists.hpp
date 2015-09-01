//Intersection of Two Linked Lists
//
//Write a program to find the node at which the intersection of two singly linked lists begins.
//
//
//For example, the following two linked lists :
//
//		A : a1 ¡ú a2
//				   ¨K
//					c1 ¡ú c2 ¡ú c3
//					¨J
//B : b1 ¡ú b2 ¡ú b3
//	begin to intersect at node c1.
//
//
//Notes :
//
//	  If the two linked lists have no intersection at all, return null.
//	  The linked lists must retain their original structure after the function returns.
//	  You may assume there are no cycles anywhere in the entire linked structure.
//	  Your code should preferably run in O(n) time and use only O(1) memory.


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
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) 
	{
		if (nullptr == headA || nullptr == headB)
			return nullptr;

		size_t length_A = getLength(headA);
		size_t length_B = getLength(headB);

		size_t distance = length_A > length_B ?
			length_A - length_B :
			length_B - length_A;

		ListNode* p = headA;
		ListNode* q = headB;

		if (length_A > length_B)
			p = forwardNStep(headA, distance);
		else
			q = forwardNStep(headB, distance);

		while (nullptr != p && nullptr != q && p != q)
		{
			p = p->next;
			q = q->next;
		}

		if (p == q)
			return p;

	}

	ListNode* forwardNStep(ListNode* head, size_t n)
	{
		if (0 == n)
			return head;

		ListNode* p = head;

		while (0 != n && nullptr != p)
		{
			n--;
			p = p->next;
		}

		return p;
	}

	size_t getLength(ListNode* head)
	{
		if (nullptr == head)
			return 0;

		ListNode* p = head;

		int length = 0;
		while (nullptr != p)
		{
			length++;
			p = p->next;
		}

		return length;
	}
};