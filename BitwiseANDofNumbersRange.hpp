//Bitwise AND of Numbers Range
//
//Given a range[m, n] where 0 <= m <= n <= 2147483647, 
//return the bitwise AND of all numbers in this range, inclusive.
//
//For example, given the range[5, 7], you should return 4.


class Solution {
public:
	int rangeBitwiseAnd(int m, int n)
	{
		if (m == n)
			return m;

		int span = n - m;
		int res = 0;

		int weight[33] = { -1, 1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 
			1024, 2048, 4096, 8192, 16384, 32768, 65536, 131072, 262144,
			524288, 1048576, 2097152, 4194304, 8388608, 16777216, 33554432,
			67108864, 134217728, 268435456, 536870912, 1073741824, 2147483648 };

		size_t bit_cnt = 

		while (true)
		{

		}

	}

	int rangeBitwiseAnd_test(int m, int n)
	{
		if (m == n)
			return m;
		int res = m;
		while (m < n)
		{
			res &= ++m;
		}
		return res;
	}
};