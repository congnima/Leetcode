/*Merge k Sorted Lists

Merge k sorted linked lists and return it as one sorted list.
Analyze and describe its complexity.*/


#include "LinkList.hpp"
#include <vector>
#include <algorithm>
using namespace std;
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
	class Comp
	{
		bool operator()(ListNode* a, ListNode* b)
		{
			return a->val >= b->val;
		}
	};

	ListNode *mergeKLists(vector<ListNode *> &lists) 
	{
		if (lists.empty())
			return nullptr;

		std::make_heap(lists.begin(), lists.end(),Comp());

		ListNode* head = nullptr;

		while (!lists.empty())
		{
			std::pop_heap(lists.begin(), lists.end(), Comp());

			ListNode* p = lists.back()->next;
			lists.back()->next = head;
			head = lists.back();

			if (nullptr != p)
			{
				lists.back() = p;
				std::push_heap(lists.begin(), lists.end(), Comp());
			}
			else
				lists.pop_back();
		}

		return head;
	}
};