//Pow(x, n)
//
//Implement pow(x, n).


class Solution 
{
public:
	double myPow(double x, int n) 
	{
		if (0 == n)
			return 1;
		
		bool bNegative = false;

		if (n < 0)
		{
			bNegative = true;
			n = -1 * n;
		}

		if (1 == x)
			return 1;
		else if (0 == x && !bNegative)
			return x;
		else if (0 == x && bNegative)
			return -1;//return fault
		else if (-1 == x)
		{
			if (0 == n % 2)
				return 1;
			else
				return -1;
		}

		double res = 1;

		while (n)
		{
			if (n & 0x01)
				res *= x;

			if (n == 0x01)
				break;

			x *= x;
			n = n >> 1;
		}

		if (bNegative)
			return 1 / res;
		else
			return res;
	}
};