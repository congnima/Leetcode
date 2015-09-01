//Implement Trie(Prefix Tree)
//
//Implement a trie with insert, search, and startsWith methods.
//
//Note:
//You may assume that all inputs are consist of lowercase letters a - z.

#include <string>
using namespace std;

class TrieNode 
{
public:
	// Initialize your data structure here.
	//constructor
	//////////
	TrieNode() 
	{
		chValue = ' ';
		bAWord = false;

		firstChild = nullptr;
		lastChild = nullptr;
		nextBrother = nullptr;
	}

	TrieNode(char ch)
	{
		chValue = ch;
		bAWord = false;

		firstChild = nullptr;
		lastChild = nullptr;
		nextBrother = nullptr;
	}

	//handle child
	//////////////
	void addChild(char ch)
	{
		TrieNode* node = new TrieNode(ch);

		if (nullptr == lastChild)
		{
			firstChild = node;
			lastChild = firstChild;
		}
		else
		{
			lastChild->nextBrother = node;
			lastChild = node;
		}
	}

	TrieNode* findCh(char ch)
	{
		TrieNode* p = firstChild;

		while (nullptr != p)
		{
			if (ch == p->getValue())
				return p;
			else
				p = p->nextBrother;
		}

		return nullptr;
	}

	//test
	/////////////
	bool isAWord()
	{
		return bAWord;
	}

	void isAWord(bool is)
	{
		bAWord = is;
	}

	//get pointer
	////////////////
	TrieNode* getFirstChild()
	{
		return firstChild;
	}

	TrieNode* getLastChild()
	{
		return lastChild;
	}

private:
	char getValue()
	{
		return chValue;
	}
private:
	char chValue;
	bool bAWord;
	TrieNode* firstChild;
	TrieNode* lastChild;
	TrieNode* nextBrother;
};

class Trie 
{
public:
	Trie() 
	{
		root = new TrieNode();
	}

	// Inserts a word into the trie.
	void insert(string s) 
	{
		if (s.empty())
			return;

		TrieNode* p = root;

		int i = 0;
		while (i < s.size())
		{
			TrieNode* tmp = p->findCh(s[i]);
			if (nullptr == tmp)
			{
				p->addChild(s[i]);
				++i;
				p = p->getLastChild();
			}
			else
			{
				++i;
				p = tmp;
			}
		}

		p->isAWord(true);

		return;
	}

	// Returns if the word is in the trie.
	bool search(string key) 
	{
		if (key.empty() || " " == key)
			return true;

		TrieNode* p = root;

		int i = 0;
		while (nullptr != p && i < key.size())
		{
			p = p->findCh(key[i++]);
		}

		if (nullptr == p)
			return false;
		else if (i == key.size() && p->isAWord())
			return true;

		return false;

	}

	// Returns if there is any word in the trie
	// that starts with the given prefix.
	bool startsWith(string prefix) 
	{
		if (prefix.empty() || " " == prefix)
			return true;

		TrieNode* p = root;

		int i = 0;
		while (nullptr != p && i < prefix.size())
		{
			p = p->findCh(prefix[i++]);
		}

		if (nullptr == p && i <= prefix.size())
			return false;
		else if (nullptr != p && i == prefix.size())
			return true;

	}

private:
	TrieNode* root;
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");