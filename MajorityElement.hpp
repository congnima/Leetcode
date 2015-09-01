//Majority Element
//
//Given an array of size n, find the majority element.
//The majority element is the element that appears more than ⌊ n / 2 ⌋ times.
//
//You may assume that the array is non - empty 
//and the majority element always exist in the array.
//
//Credits:
//Special thanks to @ts for adding this problem and creating all test cases.


#include <vector>
using namespace std;

class Solution 
{
public:
	int majorityElement(vector<int>& nums) 
	{
		int index = 0;
		int cnt = 0;

		for (int i = 1; i < nums.size(); i++)
		{
			if (nums[i] == nums[index])
				cnt++;
			if (nums[i] != nums[index])
			{
				if (!cnt)
					index = ++i;
				else
					--cnt;
			}
		}

		return nums[index];
	}
};