//Count and Say
//
//The count - and - say sequence is the sequence of integers beginning as follows :
//1, 11, 21, 1211, 111221, ...
//
//1 is read off as "one 1" or 11.
//11 is read off as "two 1s" or 21.
//21 is read off as "one 2, then one 1" or 1211.
//Given an integer n, generate the nth sequence.
//
//Note: The sequence of integers will be represented as a string.


#include <string>
#include <iostream>
using namespace std;

class Solution 
{
public:
	std::string countAndSay(int n) 
	{
		std::string res;
		
		if (n <= 0)
			return res;		

		std::string tmp = "1";
		res = tmp;
		--n;

		while (n--)
		{
			tmp = countAndSay(tmp);
			res = tmp;
		}

		return res;
	}

	std::string countAndSay(std::string& strNum)
	{
		std::string res;
		std::size_t cnt = 1;

		for (size_t i = 1; i < strNum.size(); i++)
		{
			if (strNum[i] != strNum[i - 1])
			{
				res += myitoa(cnt);
				res.push_back(strNum[i - 1]);

				cnt = 1;
			}
			else
				++cnt;
		}

		res += myitoa(cnt);
		res.push_back(strNum.back());

		return res;
	}

	std::string myitoa(int n)
	{
		char buffer[11];
		memset(buffer, sizeof(buffer), 0);
		//_itoa(n, buffer, 10);
		sprintf(buffer, "%d", n);

		return std::string(buffer);
	}
};