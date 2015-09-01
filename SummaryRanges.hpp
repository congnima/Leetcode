//Summary Ranges
//
//Given a sorted integer array without duplicates, return the summary of its ranges.
//
//For example, given[0, 1, 2, 4, 5, 7], return["0->2", "4->5", "7"].


#include <string>
#include <vector>
class Solution 
{
public:
	std::vector<std::string> summaryRanges(std::vector<int>& nums) 
	{
		std::vector<std::string> res;

		if (0 == nums.size())
			return res;

		std::size_t start = 0;
		std::size_t end = -1;

		for (size_t i = 1; i < nums.size(); i++)
		{
			if (nums[i] != nums[i - 1] + 1)
			{
				end = i - 1;

				char buffer[20];
				
				if (start == end)
					sprintf(buffer, "%d", nums[end]);
				else
					sprintf(buffer, "%d->%d", nums[start], nums[end]);

				std::string str(buffer);
				res.push_back(str);

				start = i;
				end = -1;
			}
		}

		if (-1 == end)
			end = nums.size() - 1;

		char buffer[20];

		if (start == end)
			sprintf(buffer, "%d", nums[end]);
		else
			sprintf(buffer, "%d->%d", nums[start], nums[end]);

		std::string str(buffer);
		res.push_back(str);

		return res;
	}
};