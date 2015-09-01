//Basic Calculator
//
//Implement a basic calculator to evaluate a simple expression string.
//
//The expression string may contain open(and closing parentheses), 
//the plus + or minus sign - , non - negative integers and empty spaces .
//
//You may assume that the given expression is always valid.
//
//Some examples :
//"1 + 1" = 2
//" 2-1 + 2 " = 3
//"(1+(4+5+2)-3)+(6+8)" = 23
//Note : Do not use the eval built-in library function.

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

		std::vector<std::string> stackOP;
		std::vector<int> stackOPNo;

		std::string str;
		while ((str = getElement(s)) != "")
		{
			if (str == "("
				|| str == "+"
				|| str == "-"
				)
				stackOP.push_back(str);
			else if (str == ")")
			{

			}
			else    //numbers
				stackOPNo.push_back(atoi(str.c_str()));
		}

		return;
	}



	std::string getElement(std::string &str)
	{
		static std::size_t index = 0;

		if (index >= str.size())
			return "";

		std::string tmp;

		if (str[index] == ' ')
		{
			++index;
			return getElement(str);
		}
		else if (str[index] == '('
			|| str[index] == '+'
			|| str[index] == '-'
			|| str[index] == ')')
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

};