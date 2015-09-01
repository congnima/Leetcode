//Repeated DNA Sequences
//
//All DNA is composed of a series of nucleotides abbreviated as 
//A, C, G, and T, for example: "ACGAATTCCG".
//When studying DNA, it is sometimes useful 
//to identify repeated sequences within the DNA.
//
//Write a function to find all the 10 - letter - long sequences(substrings) 
//that occur more than once in a DNA molecule.
//
//For example,
//
//Given s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT",
//
//Return:
//["AAAAACCCCC", "CCCCCAAAAA"].


#include <vector>
#include <string>
#include <map>
#include <unordered_map>

class Solution 
{
public:
	std::vector<std::string> findRepeatedDnaSequences(std::string s)
	{
		std::unordered_map<int, int> mp;
		std::vector<std::string> res;

		int letter = 0;
		int i = 0;
		int size = s.size();

		while (i < size)
			if (mp[letter = (letter << 3 | s[i++] & 7) & 0x3FFFFFFF]++ == 1)
				res.push_back(s.substr(i - 10, 10));

		return res;
	}

	std::vector<std::string> findRepeatedDnaSequences1(std::string s) 
	{
		std::vector<std::string> res;

		if (s.size() < 10)
			return res;

		std::map<std::string, int> mp;

		for (size_t i = 0; i <= s.size() - 10; i++)
		{
			std::string str = s.substr(i, 10);

			if (mp.count(str) > 0) //str exist
				res.push_back(str);
			else // str doesn't exist
				mp[str];
		}

		return res;
	}
};