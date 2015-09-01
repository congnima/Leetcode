//Best Time to Buy and Sell Stock
//
//Say you have an array for 
//which the ith element is the price of a given stock on day i.
//
//If you were only permitted to complete at most one transaction
//(ie, buy one and sell one share of the stock), 
//design an algorithm to find the maximum profit.

#include <vector>
#include <algorithm>

class Solution 
{
public:
	int maxProfit(std::vector<int>& prices) 
	{
		if (prices.size() == 0)
			return 0;

		int min = prices[0];
		int max = 0;

		for (size_t i = 1; i < prices.size();)
		{
			(prices[i - 1] < prices[i]) ?
				min = std::min<int>(prices[i - 1], min),
				max = std::max<int>(prices[i], max)
				: min = std::min<int>(prices[i], min),
				max = std::max<int>(prices[i - 1], max);

			if (i + 2 < prices.size())
				i += 2;
			else
				++i;
		}

		return max - min;
	}
};