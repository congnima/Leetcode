//Compare Version Numbers
//
//Compare two version numbers version1 and version1.
//If version1 > version2 return 1, if version1 < version2 return -1, otherwise return 0.
//
//You may assume that the version strings are non - empty and contain only digits and the.character.
//The.character does not represent a decimal point and is used to separate number sequences.
//For instance, 2.5 is not "two and a half" or "half way to version three", it is the fifth 
//second - level revision of the second first - level revision.
//
//Here is an example of version numbers ordering :
//
//0.1 < 1.1 < 1.2 < 13.37

#include <string>
using namespace std;

class Solution {
public:
	int compareVersion(string version1, string version2) {

		std::size_t i = 0;
		std::size_t j = 0;
		int ver1 = 0;
		int ver2 = 0;

		while (true)
		{		
			while (i < version1.size() && version1[i] != '.')
				ver1 += ver1 * 10 + version1[i++] - '0';

			while (j < version2.size() && version2[j] != '.')
				ver2 += ver2 * 10 + version2[j++] - '0';

			if (ver1 > ver2)
				return 1;
			else if (ver1 < ver2)
				return -1;
			else if (i == version1.size() && j == version2.size()
				&& ver1 == ver2)
				return 0;
			else
			{
				ver1 = 0;
				ver2 = 0;
				i++;
				j++;
				if (i > version1.size())
					i = version1.size();
				if (j > version2.size())
					j = version2.size();
			}
		}

	}
};