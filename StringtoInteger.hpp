//String to Integer (atoi) 

//Implement atoi to convert a string to an integer.

#include <stdlib.h>
#include <string>
#include <ctype.h>
using namespace std;

class Solution {
public:
	int atoi(string str) {

		size_t pos = str.find_first_not_of(" ");
		str.erase(0, pos);

		if (str.empty())
			return 0;
		
		int sum = 0;

		for (int i = 0; i < str.size(); i++)
		{

		}

		return sum;
	}
};