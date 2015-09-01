//Find Peak Element
//
//A peak element is an element that is greater than its neighbors.
//
//Given an input array where num[i] ¡Ù num[i + 1], find a peak element 
//and return its index.
//
//The array may contain multiple peaks, in that case return the index 
//to any one of the peaks is fine.
//
//You may imagine that num[-1] = num[n] = -¡Þ.
//
//For example, in array[1, 2, 3, 1], 3 is a peak element and your 
//function should return the index number 2.
//
//click to show spoilers.
//
//Note:
//Your solution should be in logarithmic complexity.
//
//Credits :
//Special thanks to @ts for adding this problem and creating all test cases.


#include <vector>
using namespace std;

class Solution
{
public:
	int findPeakElement(const vector<int> &num)
	{
		std::size_t l = 0;
		std::size_t u = num.size() - 1;

		while (l < u)
		{
			std::size_t m = (l + u) / 2;

			if (num[m] > num[m + 1])
				u = m;
			else
				l = m + 1;
		}

		return l;
	}
};