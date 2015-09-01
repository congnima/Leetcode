//Maximum Gap
//
//Given an unsorted array, find the maximum difference between the successive 
//elements in its sorted form.
//
//Try to solve it in linear time / space.
//
//Return 0 if the array contains less than 2 elements.
//
//You may assume all elements in the array are non - negative integers and 
//fit in the 32 - bit signed integer range.


#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;

class Solution {
public:
	int maximumGap(vector<int>& nums) 
	{
		std::sort(nums.begin(), nums.end());

		int maxGap = 0;

		for (int i = 1; i < nums.size(); i++)
		{
			maxGap = std::max<int>(nums[i] - nums[i - 1], maxGap);
		}

		return maxGap;
	}
};