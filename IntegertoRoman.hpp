//Integer to Roman
//
//Given an integer, convert it to a roman numeral.
//
//Input is guaranteed to be within the range from 1 to 3999.

//Algorithm
//http://www.rapidtables.com/convert/number/how-number-to-roman-numerals.htm
//Decimal number to roman numerals conversion
//For decimal number x :
//From the following table, find the highest decimal value v that is less than or equal to the 
//decimal number x
//and its corresponding roman numeral n :
//
//Decimal value(v)	Roman numeral(n)
//1						I
//4						IV
//5						V
//9						IX
//10					X
//40					XL
//50					L
//90					XC
//100					C
//400					CD
//500					D
//900					CM
//1000					M
//
//Write the roman numeral n that you found and subtract its value v from x :
//x = x - v
//Repeat stages 1 and 2 until you get zero result of x.

#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
	string intToRoman(int num) {
		int dec_val[13] = { 1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000 };
		char* roman_str[13] = { "I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M" };

		std::string str_res;

		for (int i = 12; i >= 0; )
		{
			if (num >= dec_val[i])
			{
				str_res.append(roman_str[i]);
				num -= dec_val[i];
			}
			else
			{
				i--;
			}
		}

		return str_res;
	}
};