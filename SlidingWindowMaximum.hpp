//Sliding Window Maximum
//
//Given an array nums, 
//there is a sliding window of size k 
//which is moving from the very left of the array to the very right.
//You can only see the k numbers in the window.
//Each time the sliding window moves right by one position.
//
//For example,
//Given nums = [1, 3, -1, -3, 5, 3, 6, 7], and k = 3.
//
//Window position                Max
//-------------- - ---- -
//[1  3 - 1] - 3  5  3  6  7       3
//1[3 - 1 - 3] 5  3  6  7       3
//1  3[-1 - 3  5] 3  6  7       5
//1  3 - 1[-3  5  3] 6  7       5
//1  3 - 1 - 3[5  3  6] 7       6
//1  3 - 1 - 3  5[3  6  7]      7
//Therefore, return the max sliding window as[3, 3, 5, 5, 6, 7].
//
//Note:
//You may assume k is always valid, 
//ie : 1 ¡Ü k ¡Ü input array's size for non-empty array.


#include <vector>
#include <algorithm>
class Solution 
{
public:
	std::vector<int> maxSlidingWindow(std::vector<int>& nums, int k)
	{
		std::size_t i = 0;

		std::vector<int> res;
		int max = 0;

		for (size_t j = i + k - 1; j < nums.size(); i++, j++)
		{
			if (i == 0 || nums[i - 1] == max)
			{
				std::vector<int> tmp(nums.begin() + i, nums.begin() + j + 1);

				std::make_heap(tmp.begin(), tmp.end());
				max = tmp.front();
			}
			else if (nums[j] > max)
				max = nums[j];

			res.push_back(max);
		}

		return res;
	}

	//time limit exceeded
	std::vector<int> maxSlidingWindow1(std::vector<int>& nums, int k) 
	{
		std::size_t i = 0;

		std::vector<int> res;

		for (size_t j = i + k; j < nums.size(); i++,j++)
		{
			std::vector<int> tmp(nums.begin() + i, nums.begin() + j);

			std::make_heap(tmp.begin(), tmp.end());
			res.push_back(tmp.front());
		}

		return res;
	}
};