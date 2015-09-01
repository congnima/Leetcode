//Anagrams
//
//Given an array of strings, return all groups of strings that are anagrams.
//
//Note: All inputs will be in lower - case.

#include <vector>
#include <map>
using namespace std;

class Solution
{
public:
	vector<string> anagrams(vector<string>& strs)
	{
		std::string str;
		std::map<std::string, int> mp;
		std::vector<std::string> res;

		for (std::size_t i = 0; i < strs.size(); ++i)
		{
			str = strs[i];
			std::sort(str.begin(), str.end());

			if (mp.find(str) == mp.end())
			{
				mp[str] = i;
			}
			else if (mp[str] >= 0)
			{
				res.push_back(strs[mp[str]]);
				res.push_back(strs[i]);
				mp[str] = -1;
			}
			else
				res.push_back(strs[i]);
		}

		return res;
	}
};