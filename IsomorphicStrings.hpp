//Isomorphic Strings
//
//Given two strings s and t, determine if they are isomorphic.
//
//Two strings are isomorphic if the characters in s can be replaced to get t.
//
//All occurrences of a character must be replaced with another character 
//while preserving the order of characters.No two characters may map to 
//the same character but a character may map to itself.
//
//For example,
//Given "egg", "add", return true.
//
//Given "foo", "bar", return false.
//
//Given "paper", "title", return true.
//
//Note:
//You may assume both s and t have the same length.


#include <string>
#include <map>
#include <assert.h>
using namespace std;

class Solution 
{
public:
	bool isIsomorphic(string s, string t) 
	{
		if (s.empty() && t.empty())
			return true;

		std::map<char,char> mp;

		for (int i = 0; i < s.size(); i++)
		{
			auto it = mp.find(s[i]);

			if (it != mp.end() && it->second != t[i])
				return false;
			else if (it == mp.end() && findSecondVal(mp, t[i]))
				return false;
			else if (it == mp.end())
				mp[s[i]] = t[i];
		}

		return true;
	}

	bool findSecondVal(std::map<char, char>& mp, char val)
	{
		for (auto it = mp.begin(); it != mp.end(); it++)
		{
			if (it->second == val)
				return true;
		}
		return false;
	}
};