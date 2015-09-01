//Roman to Integer 

//Given a roman numeral, convert it to an integer.
//
//Input is guaranteed to be within the range from 1 to 3999.

//http://en.wikipedia.org/wiki/Roman_numerals

#include <iostream>
#include <map>
#include <stack>

class Solution {
public:
	int romanToInt(std::string s) {
		if (s.empty())
			return 0;

		std::map<char, int> romanNumerals;
		romanNumerals.insert(std::make_pair('I', 1));
		romanNumerals.insert(std::make_pair('V', 5));
		romanNumerals.insert(std::make_pair('X', 10));
		romanNumerals.insert(std::make_pair('L', 50));
		romanNumerals.insert(std::make_pair('C', 100));
		romanNumerals.insert(std::make_pair('D', 500));
		romanNumerals.insert(std::make_pair('M', 1000));

		std::stack<int> sequence;

		for (auto x : s)
		{
			if (sequence.empty())
			{
				sequence.push(romanNumerals[x]);
				continue;
			}
				

			if (romanNumerals[x] > sequence.top())
			{
				int res = sequence.top();
				sequence.pop();

				sequence.push(romanNumerals[x] - res);
			}
			else
			{
				sequence.push(romanNumerals[x]);
			}
		}

		int result = 0;
		while (!sequence.empty())
		{
			result += sequence.top();
			sequence.pop();
		}

		return result;
	}
};
