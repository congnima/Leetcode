//Climbing Stairs
//
//You are climbing a stair case.It takes n steps to reach to the top.
//
//Each time you can either climb 1 or 2 steps.In how many distinct ways 
//can you climb to the top ?


#include <climits>

class Solution {
public:
	int climbStairs(int n) {
		/*if (1 == n)
			return 1;
		else if (2 == n)
			return 2;
		else
		return climbStairs(n - 1) + climbStairs(n - 2);*/

		if (1 == n)
			return 1;
		else if(2 == n)
			return 2;

		int prev = 1;
		int res = 2;

		n = n - 2;
		while (n-- > 0)
		{
			res = prev + res;
			if (res < 0)
				return -1;
			prev = res - prev;
		}

		return res;
	}
};