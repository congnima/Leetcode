//Excel Sheet Column Number
//
//Related to question Excel Sheet Column Title
//
//Given a column title as appear in an Excel sheet, return its corresponding column number.
//
//For example :
//
//A -> 1
//B -> 2
//C -> 3
//...
//Z -> 26
//AA -> 27
//AB -> 28


#include <string>
using namespace std;

class Solution {
public:
	int titleToNumber(string s) {

		std::size_t size = s.size();
		std::size_t weight = 1;
		std::size_t number = 0;

		for (int i = size - 1; i >= 0; i--)
		{
			if (i != size - 1)
				weight = weight * 26;
			number += (s[i] - 'A' + 1) * weight;
		}

		return number;
	}
};