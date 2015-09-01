
#ifndef _LINK_LIST_HPP
#define	_LINK_LIST_HPP

#include <cstddef>
#include <memory>
#include <string>
#include <cctype>
#include <vector>
#include <algorithm>
#include <iostream>
#include <assert.h>

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class LinkList
{
public:
	LinkList(std::string str);
	LinkList(ListNode* pLstNd = nullptr);
	~LinkList();
	LinkList(const LinkList& lst);
	LinkList operator= (const LinkList& lst);

	//"{2,1,3,4}" present list: 2->1->3->4
	//and parse "{2,1,3,4}"into a vector<int>:
	//[2,1,3,4]
	void ParseListStr();
	//get a head pointer from string
	ListNode* IniList();
	// free all list node and reset all data
	void Clear(); 
	// reset the list to initial state
	//like the string when consturct
	ListNode* Reset();

	//print a list
	static void PrintList(ListNode* head);
private:
	ListNode* head;
	std::vector<int> listNode;
	std::string strList;
};


LinkList::LinkList(std::string str) :head(nullptr)
{
	strList = str;

	ParseListStr();
}

LinkList::LinkList(ListNode* pLstNd) :head(pLstNd)
{

}

LinkList::~LinkList()
{
	Clear();
}


void LinkList::ParseListStr()
{
	if (strList.empty())
		return;

	std::string strNode;
	listNode.clear();

	for (auto x : strList)
	{
		if (std::isalnum(x))
			strNode += x;
		else
		{
			if (!strNode.empty())
				listNode.push_back(atoi(strNode.c_str()));
			strNode.clear();
		}
	}

	std::reverse(listNode.begin(), listNode.end());
}

ListNode* LinkList::IniList()
{
	if (0 == listNode.size())
		return nullptr;
	
	if (nullptr != head)
		head = nullptr; // should clear(),but head may be
					//changed outside,so head in this class
					//would be a wild pointer

	assert(nullptr == head);

	for (auto x : listNode)
	{
		if (nullptr == head)
		{
			head = new ListNode(x);
		}
		else
		{
			ListNode* p = new ListNode(x);
			p->next = head;

			head = p;
		}
	}

	return head;
}

void LinkList::PrintList(ListNode* head)
{
	if (nullptr == head)
	{
		std::cout << "nullptr" << std::endl;
	}
	else
	{
		ListNode* p = head;
		while (NULL != p)
		{
			std::cout << p->val << ",";
			p = p->next;
		}
		std::cout << std::endl;
	}

}

void LinkList::Clear()
{
	// free memory
	if (nullptr == head)
		return;

	ListNode* p = nullptr;

	while (nullptr != head)
	{
		p = head;
		head = head->next;
		free(p);
	}

	head = nullptr;

}


ListNode* LinkList::Reset()
{
	Clear();

	//ParseListStr();
	head = IniList();
	return head;
}

#endif