﻿//Maximum Subarray
//
//Find the contiguous subarray within an 
//array(containing at least one number) which has the largest sum.
//
//For example, given the array[−2, 1, −3, 4, −1, 2, 1, −5, 4],
//the contiguous subarray[4, −1, 2, 1] has the largest sum = 6.
//
//click to show more practice.
//
//More practice :
//If you have figured out the O(n) solution, try coding another 
//solution using the divide and conquer approach, which is more subtle.


#include <vector>
#include <algorithm>
using namespace std;

class Solution 
{
public:
	int maxSubArray(vector<int>& nums) 
	{
		int maxSofar = 0;
		int max = 0;

		for (int i = 0; i < nums.size(); i++)
		{
			max = std::max(max + nums[i], 0);
			maxSofar = std::max(max, maxSofar);
		}

		if (0 == maxSofar) // all numbers are negative
			return *std::max_element(nums.begin(), nums.end());
		else
			return maxSofar;
	}
};