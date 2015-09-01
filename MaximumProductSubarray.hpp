//Maximum Product Subarray
//
//
//Find the contiguous subarray 
//within an array(containing at least one number) which has the largest product.
//
//For example, given the array[2, 3, -2, 4],
//the contiguous subarray[2, 3] has the largest product = 6.


#include <vector>
#include <algorithm>

class Solution 
{
public:
	int maxProduct(std::vector<int>& nums) 
	{
		if (nums.empty())
			return 0;

		std::vector<int> res;
		res.push_back(nums[0]);

		for (std::size_t i = 1; i < nums.size(); i++)
		{
			int max = res[i - 1];
			int maxsofar = 1;

			for (size_t j = i; j < nums.size(); j--)
			{
				maxsofar *= nums[j];
				max = std::max<int>(max, maxsofar);
			}

			res.push_back(max);
		}

		return res.back();
	}
};