//Plus One
//
//Given a non - negative number represented as an array of digits,
//plus one to the number.
//
//The digits are stored such that the most significant digit is 
//at the head of the list.


#include <vector>
using namespace std;

class Solution 
{
public:
	vector<int> plusOne(vector<int>& digits) 
	{

		if (digits.empty())
			return digits;

		int index = digits.size() - 1; 
		std::size_t carry = 0;

		digits[index] += 1;

		for (; index >= 0; index--)
		{
			digits[index] += carry;

			carry = digits[index] / 10;
			digits[index] = digits[index] - (digits[index] / 10) * 10;

			if (0 == carry)
				break;
			else if (0 == index && 0 != carry)
				digits.insert(digits.begin(), carry);
		}

		return digits;
	}
};