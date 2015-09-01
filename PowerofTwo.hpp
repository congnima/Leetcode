//Power of Two
//
//Given an integer, write a function to determine if it is a power of two.

#include <vector>

class Solution
{
public:
	bool isPowerOfTwo(int n)
	{
		return (n > 0) && (n & n - 1) == 0;
	}

	bool isPowerOfTwo2(int n)
	{
		if (n <= 0)
			return false;

		std::size_t cnt = 0;

		while (n)
		{
			n &= n - 1;
			if (++cnt > 1)
				return false;
		}
		if (1 == cnt)
			return true;
	}

	bool isPowerOfTwo1(int n)
	{
		if (n <= 0)
			return false;

		static int weight[] = { 1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048
			, 4096, 8192, 16384, 32768, 65536, 131072, 262144
			, 524288, 1048576, 2097152, 4194304, 8388608, 16777216
			, 33554432, 67108864, 134217728, 268435456, 536870912, 1073741824 };

		if (n > weight[30])
			return false;

		std::size_t l = 0;
		std::size_t e = sizeof(weight) / sizeof(int) - 1;

		while (l < e)
		{
			std::size_t m = (l + e) / 2;

			if (weight[m] == n)
				return true;
			else if (weight[m] < n)
				l = m + 1;
			else if (weight[m] > n)
				e = m - 1;
		}

		// l==e
		if (weight[l] == n)
			return true;
		else
			return false;
	}
};