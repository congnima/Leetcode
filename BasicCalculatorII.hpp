//Basic Calculator II
//
//Implement a basic calculator to evaluate a simple expression string.
//
//The expression string contains only non - negative integers, +, -, *, /
//operators and empty spaces.The integer division should truncate toward zero.
//
//You may assume that the given expression is always valid.
//
//Some examples :
//"3+2*2" = 7
//" 3/2 " = 1
//" 3+5 / 2 " = 5
//Note : Do not use the eval built - in library function.

#include <string>
#include <vector>
using namespace std;

class Solution 
{
public:
	int calculate(string s) 
	{
		if (s.empty())
			return 0;

		std::vector<int> stackOPNo;
		std::vector<std::string> stackOP;

		index = 0;
		std::string str;
		while ("" != (str = getElement(s)))
		{
			if ("+" == str
				|| "-" == str)
				stackOP.push_back(str);
			else if ("*" == str
				|| "/" == str)
			{
				int val = ("*" == str) ?
					stackOPNo.back() * atoi(getElement(s).c_str()) 
					: stackOPNo.back() / atoi(getElement(s).c_str());
				stackOPNo.pop_back();
				stackOPNo.push_back(val);
			}
			else
			{
				stackOPNo.push_back(atoi(str.c_str()));
			}
		}

		while (!stackOP.empty())
		{
			std::string strOP = stackOP.front();

			int val = ("+" == strOP) ?
				stackOPNo[0] + stackOPNo[1]
				: stackOPNo[0] - stackOPNo[1];

			stackOPNo.erase(stackOPNo.begin(),stackOPNo.begin()+1);
			stackOPNo.insert(stackOPNo.begin(), val);
			stackOP.pop_back();
		}

		return stackOPNo.front();
	}

	std::string getElement(std::string &str)
	{

		if (index >= str.size())
			return "";

		std::string tmp;

		if (str[index] == ' ')
		{
			++index;
			return getElement(str);
		}
		else if (str[index] == '+'
			|| str[index] == '-'
			|| str[index] == '*'
			|| str[index] == '/')
		{
			tmp += str[index++];
		}
		else
		{
			while (isdigit(str[index]))
				tmp += str[index++];
		}

		return tmp;
	}// end of getElement()

private:
	std::size_t index;
};