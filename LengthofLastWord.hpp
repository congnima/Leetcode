//Length of Last Word
//
//Given a string s consists of upper / lower - case alphabets and empty space characters ' ', 
//return the length of last word in the string.
//
//If the last word does not exist, return 0.
//
//Note: A word is defined as a character sequence consists of non - space characters only.
//
//	  For example,
//	  Given s = "Hello World",
//	  return 5.

#include <cstdlib>

class Solution {
public:
	int lengthOfLastWord(const char *s) {
		if (NULL == s)
			return 0;

		size_t len_str = strlen(s);

		int len_last_world = 0;

		while (' ' == s[len_str - 1])
		{
			len_str--;
		}

		while (len_str != 0 && s[len_str - 1] != ' ')
		{
			len_last_world++;
			len_str--;
		}

		return len_last_world;
	}
};