//Two Sum
//
//Given an array of integers, find two numbers such that they add up to a specific target number.
//
//The function twoSum should return indices of the two numbers such that they add up to the target, 
//where index1 must be less than index2.Please note that your returned answers(both index1 and index2) 
//are not zero - based.
//
//You may assume that each input would have exactly one solution.
//
//Input: numbers = { 2, 7, 11, 15 }, target = 9
//   Output : index1 = 1, index2 = 2


#include <vector>
#include <algorithm>
#include <map>

using namespace std;

class Solution {
public:
	vector<int> twoSum(vector<int> &numbers, int target) {
		
		std::map<int, int> hs_mp;

		for (int i = 0; i < numbers.size(); i++)
		{
			hs_mp.insert(std::make_pair(numbers[i], i));
		}

		std::map<int, int>::iterator p;
		for (int i = 0; i < numbers.size(); i++)
		{
			if ((p = hs_mp.find(target - numbers[i])) != hs_mp.end())
			{
				int j = p->second;
				if (i == j)
					continue;
				else
				return	(i >= j) ? std::vector<int>({j + 1, i + 1}) :
					std::vector<int>({ i + 1, j + 1});
			}
		}

		return std::vector<int>({ -1, -1 });
	}
};