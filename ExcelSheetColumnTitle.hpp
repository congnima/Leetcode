//Excel Sheet Column Title
//
//Given a positive integer, return its corresponding column title as appear in an Excel sheet.
//
//For example :
//
//1->A
//2->B
//3->C
//...
//26->Z
//27->AA
//28->AB

#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
	string convertToTitle(int n) {
		std::string title;

		//26^7,26^6,26^5,26^4,26^3,26^2,26,1
		std::size_t weight[8] = { 8031810176, 308915776, 11881376, 456976, 17576, 676, 26, 1 };
		//weights={weight[0]+...+weight[7],weight[1]+...+weight[7],weight[2]+...+weight[7],...,weight[7]}
		std::size_t weights[8] = { 8353082586, 321272410, 12356634, 475258, 18279, 703, 27, 1 };

		for (int i = 0; i < 8; i++)
		{
			if (n >= weights[i])
			{
				if (0 == n % weight[i] && i != 7)
				{
					title.push_back('A' - 1 + n / weight[i] - 1);
					n -= weight[i] * (n / weight[i] - 1);

				}
				else
				{
					title.push_back('A' - 1 + n / weight[i]);
					n -= weight[i] * (n / weight[i]);

				}
				
			}
			if (1 == n && 7 == i)
			{
				title.push_back('A');
			}
		}

		return title;
	}
};