//Contains Duplicate
//
//Given an array of integers, find if the array contains any duplicates.
//Your function should return true if any value appears at least twice 
//in the array, and it should return false if every element is distinct.

#include <vector>
#include <bitset>
using namespace std;

class Solution {
public:
	//bool containsDuplicate(vector<int>& nums)
	//{
	//	if (nums.empty() || 1 == nums.size())
	//		return false;

	//	std::bitset<4294967296> bitSet;

	//	for (auto x : nums)
	//	{
	//		if (bitSet.test(x))
	//			return true;
	//		else
	//			bitSet.set(x);
	//	}

	//	return false;
	//}
	bool containsDuplicate(vector<int>& nums)
	{
		size_t len = nums.size();
		if (0 == len || 1 == len)
			return false;

		std::sort(nums.begin(), nums.end());
				
		for (int i = 0; i < len - 1; i++)
		{
			if (nums[i] == nums[i + 1])
				return true;
		}

		return false;
	}
};