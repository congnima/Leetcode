//Evaluate Reverse Polish Notation
//
//Evaluate the value of an arithmetic expression in Reverse Polish Notation.
//
//Valid operators are + , -, *, 
/// .Each operand may be an integer or another expression.
//
//Some examples :
//["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
//["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6


#include <vector>
#include <string>
#include <stack>
using namespace std;

class Solution {
public:
	int evalRPN(vector<string>& tokens)
	{
		if (tokens.empty())
			return 0;

		std::stack<int> stack;
		int lhs = 0;
		int rhs = 0;

		for (string x : tokens)
		{
			if (x == "+")
			{
				rhs = stack.top();
				stack.pop();
				lhs = stack.top();
				stack.pop();

				stack.push(lhs + rhs);
			}
			else if (x == "-")
			{
				rhs = stack.top();
				stack.pop();
				lhs = stack.top();
				stack.pop();

				stack.push(lhs - rhs);
			}
			else if (x == "*")
			{
				rhs = stack.top();
				stack.pop();
				lhs = stack.top();
				stack.pop();

				stack.push(lhs * rhs);
			}
			else if (x == "/")
			{
				rhs = stack.top();
				stack.pop();
				lhs = stack.top();
				stack.pop();

				stack.push(lhs / rhs);
			}
			else
				stack.push(atoi(x.c_str()));
		}

		if (!stack.empty())
			return stack.top();
	}
};
