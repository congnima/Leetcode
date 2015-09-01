//Regular Expression Matching
//
//
//Implement regular expression matching with support for '.' and '*'.
//
//'.' Matches any single character.
//'*' Matches zero or more of the preceding element.
//
//The matching should cover the entire input string(not partial).
//
//The function prototype should be :
//bool isMatch(const char *s, const char *p)
//
//Some examples :
//isMatch("aa", "a") ¡ú false
//isMatch("aa", "aa") ¡ú true
//isMatch("aaa", "aa") ¡ú false
//isMatch("aa", "a*") ¡ú true
//isMatch("aa", ".*") ¡ú true
//isMatch("ab", ".*") ¡ú true
//isMatch("aab", "c*a*b") ¡ú true


class Solution {
public:
	bool isMatch(const char *s, const char *p) 
	{
		if (*s == '\0' && *p == '\0')
		{
			return true;
		}
		else if (*p != '\0' && *(p + 1) == '*')
		{
			if (isMatch(s, p + 2))
				return true;
			else if (*s != '\0' && (*s == *p || *p == '.'))
				return isMatch(++s, p);
			else
				return false;
		}
		else if (*s == *p || (*s != '\0' && *p == '.'))
		{
			return isMatch(++s, ++p);
		}
		else
		{
			return false;
		}
	}
};