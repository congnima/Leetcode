//Add and Search Word - Data structure design
//
//Design a data structure that supports the following two operations :
//
//void addWord(word)
//bool search(word)
//search(word) can search a literal word 
//or a regular expression string containing only letters a - z or ..A.
//means it can represent any one letter.
//
//For example :
//
//addWord("bad")
//addWord("dad")
//addWord("mad")
//search("pad") -> false
//search("bad") -> true
//search(".ad") -> true
//search("b..") -> true


#include <string>

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

	TrieNode* getNextBrother()
	{
		return nextBrother;
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
	void insert(std::string s)
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
	//bool search(std::string key)
	//{
	//	if (key.empty() || " " == key)
	//		return true;

	//	TrieNode* p = root;

	//	int i = 0;
	//	while (nullptr != p && i < key.size())
	//	{
	//		p = p->findCh(key[i++]);
	//	}

	//	if (nullptr == p)
	//		return false;
	//	else if (i == key.size() && p->isAWord())
	//		return true;

	//	return false;

	//}

	//recursion version for search()
	bool search(std::string key, TrieNode* p)
	{

		if (nullptr == p)
			return false;
		if (key.empty() && p->isAWord())
			return true;
		else if (key.empty() && !p->isAWord())
			return false;

		if (key[0] == '.')
		{
			std::string str = key.substr(1);
			char ch = ' ';

			if (str != "")
				ch = key[1];

			TrieNode* q = nullptr;
			if (p != root)
				q = p->getFirstChild();

			while (nullptr != q)
			{
				if (search(str,q->findCh(ch)))
					return true;

				q = q->getNextBrother();
			}

			if (nullptr == q)
				return false;
		}
		else
			return search(key.substr(1), p->findCh((char)key[0]));
	}

	//wrap method for recursion search()
	bool search(std::string key)
	{
		if (key.empty() || " " == key)
			return true;

		return search(key, root);
	}

	// Returns if there is any word in the trie
	// that starts with the given prefix.
	bool startsWith(std::string prefix)
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

class WordDictionary 
{
public:

	// Adds a word into the data structure.
	void addWord(std::string word) 
	{
		trie.insert(word);
	}

	// Returns if the word is in the data structure. A word could
	// contain the dot character '.' to represent any one letter.
	bool search(std::string word) 
	{
		return trie.search(word);
	}

private:
	Trie trie;
};

// Your WordDictionary object will be instantiated and called as such:
// WordDictionary wordDictionary;
// wordDictionary.addWord("word");
// wordDictionary.search("pattern");