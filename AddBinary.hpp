//Add Binary

//Given two binary strings, return their sum (also a binary string).

//For example,
//a = "11"
//b = "1"
//Return "100".

#include <string>

using namespace std;

class Solution {
public:
	string addBinary(string a, string b) {

		if (0 == a.size() && 0 == b.size())
			return "";

		if (0 == a.size())
			return b;
		if (0 == b.size())
			return a;

		while ('0' == a[0])
			a.erase(0, 1);

		while ('0' == b[0])
			b.erase(0, 1);

		if (0 == a.size() && 0 == b.size())
			return "0";

		if (0 == a.size())
			return b;
		if (0 == b.size())
			return a;

		while (a.size() < b.size())
		{
			a.insert(0,"0");
		}

		while (b.size() < a.size())
		{
			b.insert(0, "0");
		}

		bool carry = false;
		std::string str_result;

		for (int i = a.size() - 1; i >= 0; i--)
		{
			if ('1' == a[i] && '1' == b[i] && !carry)
			{
				str_result.insert(0,"0");
				carry = true;
			}
			else if ('1' == a[i] && '1' == b[i] && carry)
			{
				str_result.insert(0, "1");
				carry = true;
			}
			else if (('1' == a[i] && '0' == b[i]) ||
				('0' == a[i] && '1' == b[i]))
			{
				if (carry)
					str_result.insert(0, "0");
				else
					str_result.insert(0, "1");
			}
			else if ('0' == a[i] && '0' == b[i])
			{
				if (carry)
				{
					str_result.insert(0, "1");
					carry = false;
				}
				else
					str_result.insert(0, "0");
			}
		}

		if (carry)
			str_result.insert(0, "1");

		while ('0' == str_result[0])
			str_result.erase(0, 1);

		return str_result;
	}
};