//Longest Consecutive Sequence
//
//Given an unsorted array of integers, find the length 
//of the longest consecutive elements sequence.
//
//For example,
//Given[100, 4, 200, 1, 3, 2],
//The longest consecutive elements sequence is[1, 2, 3, 4].Return its length : 4.
//
//Your algorithm should run in O(n) complexity.

#include <vector>
#include <algorithm>
#include <map>
using namespace std;

class Solution 
{
public:
	int longestConsecutive(vector<int>& nums) 
	{
		std::size_t max_len = 0;
		
		if (nums.empty())
			return max_len;

		std::map<int, int> mp;

		for (size_t i = 0; i < nums.size(); i++)
		{
			mp[nums[i]] = 0;
		}

		for (size_t i = 0; i < nums.size(); i++)
		{
			if (mp.count(nums[i]) > 0 && -1 == mp[nums[i]])
				continue;

			std::size_t len = 1;
			int num = nums[i] - 1;

			while (mp.count(num) > 0)
			{
				++len;
				mp[num--] = -1;
			}

			num = nums[i] + 1;

			while (mp.count(num) > 0)
			{
				++len;
				mp[num++] = -1;
			}

			max_len = std::max(len, max_len);
		}

		return max_len;
	}
};