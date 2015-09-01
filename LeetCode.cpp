// LeetCode.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include "Tree.hpp"
#include "LinkList.hpp"

#include "MaximumProductSubarray.hpp"

template <class T>
void printElement(T& a)
{
	T::iterator it = a.begin();

	std::cout << "[ ";

	for (; it != a.end(); it++)
	{
		std::cout << *it << ",";
	}

	std::cout << " ]" << std::endl;
}

int _tmain(int argc, _TCHAR* argv[])
{

	//Solution sol;

	//LinkList lst1("{}");
	//LinkList lst2("{1}");
	//LinkList lst3("{3,1,2,7,9}");

	//ListNode* head = sol.sortList(lst.IniList());
	//LinkList::PrintList(head);

	//std::vector<int> preorder = { 1, 2, 4, 5, 3, 6, 7 };
	//std::vector<int> inorder = { 4, 2, 5, 1, 6, 3, 7 };

	//TreeNode* root = sol.buildTree(preorder, inorder);

	/*int array[2] = { 1, 3 };
	TreeNode* root =
	sol.sortedArrayToBST(std::vector<int>(array,array+2));*/

	/*std::vector<string> PolishNotation1({ "2", "1", "+", "3", "*" });
	std::vector<string> PolishNotation2({ "4", "13", "5", "/", "+" });
	std::cout << sol.evalRPN(PolishNotation1) << std::endl;
	std::cout << sol.evalRPN(PolishNotation2) << std::endl;*/

	//LinkList::PrintList(sol.reverseBetween(lst1.IniList(),3,5));
	//LinkList::PrintList(sol.reverseBetween(lst2.IniList(),1,1));
	//LinkList::PrintList(sol.reverseBetween(lst3.IniList(),1,2));
	//LinkList::PrintList(sol.reverseBetween(lst3.Reset(), 1, 3));
	//LinkList::PrintList(sol.reverseBetween(lst3.Reset(), 1, 4));
	//LinkList::PrintList(sol.reverseBetween(lst3.Reset(), 1, 5));


	/*std::cout << sol.hammingWeight(10);*/

	//std::cout << sol.rangeBitwiseAnd_test(16, 16) << std::endl;
	//std::cout << sol.rangeBitwiseAnd_test(5, 7) << std::endl;
	//std::cout << sol.rangeBitwiseAnd_test(4, 16) << std::endl;

	//std::cout << sol.myPow(2, -1) << std::endl
	//	<< sol.myPow(2, -2) << std::endl
	//	<< sol.myPow(2, -3) << std::endl
	//	<< sol.myPow(2, -4) << std::endl
	//	<< sol.myPow(2, -5) << std::endl
	//	<< sol.myPow(2, -6) << std::endl
	//	<< sol.myPow(2, -7) << std::endl
	//	<< sol.myPow(2, -8) << std::endl;
	//std::cout << sol.myPow(2, 0) << std::endl
	//	<< sol.myPow(2, 1) << std::endl
	//	<< sol.myPow(2, 2) << std::endl
	//	<< sol.myPow(2, 3) << std::endl
	//	<< sol.myPow(2, 4) << std::endl
	//	<< sol.myPow(2, 5) << std::endl
	//	<< sol.myPow(2, 6) << std::endl
	//	<< sol.myPow(2, 7) << std::endl
	//	<< sol.myPow(2, 8) << std::endl;

	//test for
	//ContainsDuplicate.hpp
	//std::vector<int> vec = { 1 };
	//std::vector<int> vec1 = { 1, 2 };
	//std::vector<int> vec2 = { 1, 1 };
	//std::vector<int> vec3 = { 1, 2, 3 };
	//std::vector<int> vec4 = { 1, 2, 2, 3 };
	//std::vector<int> vec5 = { 1, 2, 3, 4 };
	//std::vector<int> vec6 = {};
	//std::cout.setf(std::ios::boolalpha);
	//std::cout << sol.containsDuplicate(vec) << std::endl;
	//std::cout << sol.containsDuplicate(vec1) << std::endl;
	//std::cout << sol.containsDuplicate(vec2) << std::endl;
	//std::cout << sol.containsDuplicate(vec3) << std::endl;
	//std::cout << sol.containsDuplicate(vec4) << std::endl;
	//std::cout << sol.containsDuplicate(vec5) << std::endl;
	//std::cout << sol.containsDuplicate(vec6) << std::endl;

	//test for
	//Implement Trie(Prefix Tree)
	//Trie trie;
	//std::cout.setf(std::ios::boolalpha);
	//std::cout << "Does 'hello' exist? :" << trie.search("hello") << std::endl;
	//std::cout << "' '? :" << trie.search("") << std::endl;

	//trie.insert("hello");
	//std::cout << "after insert 'hello', search 'hello' :" << trie.search("hello") << std::endl;
	//std::cout << "search 'hehe' :" << trie.search("hehe") << std::endl;
	//trie.insert("hehe");
	//std::cout << "after insert 'hehe', search 'hello' :" << trie.search("hello") << std::endl;
	//std::cout << "search 'he' :" << trie.search("he") << std::endl;
	//std::cout << "Does prefix ' ' exist? :" << trie.startsWith(" ") << std::endl;
	//std::cout << "Does prefix 'h' exist? :" << trie.startsWith("h") << std::endl;
	//std::cout << "Does prefix 'he' exist? :" << trie.startsWith("he") << std::endl;
	//std::cout << "Does prefix 'heh' exist? :" << trie.startsWith("heh") << std::endl;
	//std::cout << "Does prefix 'hehe' exist? :" << trie.startsWith("hehe") << std::endl;
	//std::cout << "Does prefix 'hello' exist? :" << trie.startsWith("hello") << std::endl;
	//std::cout << "Does prefix 'helloj' exist? :" << trie.startsWith("helloj") << std::endl;


	//test for BasicCalculator
	//std::cout.setf(std::ios::boolalpha);
	//std::cout << (sol.calculate("") == 0 )<< std::endl;
	//std::cout << (sol.calculate("1+1") == 2)<< std::endl;
	//std::cout << (sol.calculate(" 1 + 1") == 2)<< std::endl;
	//std::cout << (sol.calculate(" 2-1 + 2 ") == 3)<< std::endl;
	//std::cout << (sol.calculate("(1+(4+5+2)-3)+(6+8)") == 23 )<< std::endl;

	//test for BasicCalculatorII
	//std::cout.setf(std::ios::boolalpha);
	//std::cout << (sol.calculate("") == 0) << std::endl;
	//std::cout << (sol.calculate("3+2*2") == 7) << std::endl;
	//std::cout << (sol.calculate(" 3/2 ") == 1) << std::endl;
	//std::cout << (sol.calculate(" 3+5 / 2 ") == 5) << std::endl;
	//std::cout << (sol.calculate("1") == 1) << std::endl;

	//test for PowerofTwo
	//std::cout.setf(std::ios::boolalpha);
	//std::cout << sol.isPowerOfTwo(-1) << std::endl;//false
	//std::cout << sol.isPowerOfTwo(-2) << std::endl;//false
	//std::cout << sol.isPowerOfTwo(0) << std::endl;//false
	//std::cout << sol.isPowerOfTwo(1) << std::endl;//true
	//std::cout << sol.isPowerOfTwo(1024) << std::endl;//true
	//std::cout << sol.isPowerOfTwo(1025) << std::endl;//false
	//std::cout << sol.isPowerOfTwo(2048) << std::endl;//true
	//std::cout << sol.isPowerOfTwo(10) << std::endl;//false
	//std::cout << sol.isPowerOfTwo(1073741824) << std::endl;//true
	//std::cout << sol.isPowerOfTwo(1073741825) << std::endl;//false

	//test for KthLargestElementinanArray
	//std::vector<int> vec = { 3, 4, 2, 1 };
	//std::cout << sol.findKthLargest(vec, 2) << std::endl;//3
	//std::cout << sol.findKthLargest(vec, 1) << std::endl;//4
	//std::cout << sol.findKthLargest(vec, 3) << std::endl;//2
	//std::cout << sol.findKthLargest(vec, 4) << std::endl;//1

	//test for IsomorphicString
	//std::cout.setf(std::ios::boolalpha);
	//std::cout << sol.isIsomorphic("", "") << std::endl;//true	
	//std::cout << sol.isIsomorphic("egg","add") << std::endl;//true
	//std::cout << sol.isIsomorphic("abc","def") << std::endl;//true
	//std::cout << sol.isIsomorphic("abc","abd") << std::endl;//true
	//std::cout << sol.isIsomorphic("abc","abc") << std::endl;//true
	//std::cout << sol.isIsomorphic("abb","abc") << std::endl;//false
	//std::cout << sol.isIsomorphic("foo","bar") << std::endl;//false
	//std::cout << sol.isIsomorphic("paper","title") << std::endl;//true
	//std::cout << sol.isIsomorphic("ab", "aa") << std::endl;//false

	//test for MaximjmSubarray
	//std::vector<int> nums = { -2, 1, -3, 4, -1, 2, 1, -5, 4 };
	//std::cout << sol.maxSubArray(nums) << std::endl;
	//nums = { -1 };
	//std::cout << sol.maxSubArray(nums) << std::endl;
	//nums = { -1, -2 };
	//std::cout << sol.maxSubArray(nums) << std::endl;

	//test for PlusOne
	//std::vector<int> nums = {};
	//sol.plusOne(nums);
	//printElement(nums);// 

	//nums = {7,8,9};
	//sol.plusOne(nums);
	//printElement(nums);//7,9,0

	//nums = {7,8,8};
	//sol.plusOne(nums);
	//printElement(nums);//7,8,9

	//nums = {9,9,9};
	//sol.plusOne(nums);
	//printElement(nums);//1,0,0,0

	//nums = {1};
	//sol.plusOne(nums);
	//printElement(nums);//2

	//nums = {2,0,1,4};
	//sol.plusOne(nums);
	//printElement(nums);//2,0,1,5

	//nums = {0,0,1};
	//sol.plusOne(nums);
	//printElement(nums);//0,0,2

	////nums = {};
	////sol.plusOne(nums);
	////printElement(nums);

	//test for ReverseBits
	//std::cout << sol.reverseBits(1) << std::endl;// 2147483648
	//std::cout << sol.reverseBits(0) << std::endl;// 0
	//std::cout << sol.reverseBits(43261596) << std::endl; // 964176192

	//test for RemoveLinkedListElements
	//LinkList lst1("{}");
	//LinkList lst2("{1}");
	//LinkList lst3("{3,1,2,7,9}");
	//LinkList::PrintList(sol.removeElements(lst1.IniList(), 1));//nullptr
	//LinkList::PrintList(sol.removeElements(lst2.IniList(), 1));//nullptr
	//LinkList::PrintList(sol.removeElements(lst2.IniList(), 2));//{1}
	//LinkList::PrintList(sol.removeElements(lst3.IniList(), 3));//{1,2,7,9}
	//LinkList::PrintList(sol.removeElements(lst3.IniList(), 2));//{3,1,7,9}
	//LinkList::PrintList(sol.removeElements(lst3.IniList(), 9));//{3,1,2,7}
	//LinkList::PrintList(sol.removeElements(lst3.IniList(), 5));//{3,1,2,7,9}

	//test for Anagrams
	//std::vector<std::string> strs
	//	= { "aba", "aa", "a", "", "abc","cba","bca","bac"};

	//printElement(sol.anagrams(strs));//abc,cba,bca,bac

	//strs = { "" };

	//printElement(sol.anagrams(strs));//""


	//test for CountandSay
	//for (std::size_t i = 0; i < 11; i++)
	//{
	//	std::cout << sol.countAndSay(i) << std::endl;
	//}

	//test for Search2DMatrix
	//std::vector<std::vector<int>> vct = { { 1, 3, 5, 7 },
	//{ 10, 11, 16, 20 }, { 20, 30, 34, 50 } };
	//
	//std::cout.setf(std::ios::boolalpha);
	//std::cout << sol.searchMatrix(vct, 3) << std::endl;//true
	//std::cout << sol.searchMatrix(vct, 1) << std::endl;//true
	//std::cout << sol.searchMatrix(vct, 50) << std::endl;//true
	//std::cout << sol.searchMatrix(vct, 10) << std::endl;//true
	//std::cout << sol.searchMatrix(vct, 20) << std::endl; // true
	//std::cout << sol.searchMatrix(vct, 22) << std::endl; //false
	//std::cout << sol.searchMatrix(vct, 16) << std::endl; //true
	//std::cout << sol.searchMatrix(vct, 34) << std::endl;//true
	//std::cout << sol.searchMatrix(vct, -1) << std::endl; //false
	//std::cout << sol.searchMatrix(vct, 19) << std::endl; // false

	//test for Search2DMatrixII
	//std::vector<std::vector<int>> vct = { { 1, 1 } };
	//std::cout.setf(std::ios::boolalpha);
	//std::cout << sol.searchMatrix(vct, 0);

	//test for SingleNumber
	//std::vector<int> vct = { 1, 1, 2, 3, 4, 5, 3, 4, 5 };//2
	//std::vector<int> vct1 = {};//0
	//std::vector<int> vct2 = { 2 };
	//std::vector<int> vct3 = { 1, 1, 2, 2, 3, 3, 4, 5, 5, 6, 6 };//4

	//std::cout << sol.singleNumber(vct) << std::endl;
	//std::cout << sol.singleNumber(vct1) << std::endl;
	//std::cout << sol.singleNumber(vct2) << std::endl;
	//std::cout << sol.singleNumber(vct3) << std::endl;

	//test for KthSmallestElementinaBST
	//Tree tree("{2,1,#}");
	//int k = 1;
	//std::cout << sol.kthSmallest(tree.IniTree(), k) << std::endl;


	//test for BinarySearchTreeIterator
	//Tree tree("{5,2,7,1,3,6,8}");
	//Tree tree("{1}");
	//Tree tree("{}");
	//Tree tree("{5,2,7,1,#,#,8}");
	//BSTIterator it(tree.IniTree());
	//while (it.hasNext())
	//	std::cout << it.next() << ", ";

	//test for Triangle
	//std::vector<std::vector<int>> vct =
	//{ { 2 },
	//{ 3, 4 },
	//{ 6, 5, 7 },
	//{ 4, 1, 8, 3 } };

	//std::cout << sol.minimumTotal(vct);

	//test for SearchforaRange
	//std::vector<int> vct = {};
	//std::vector<int> vct1 = { 1 };
	//std::vector<int> vct2 = { 1, 2, 3 };
	//std::vector<int> vct3 = { 1, 1, 1, 1 };
	//std::vector<int> vct4 = { 1, 2, 2, 3, 3 };
	//std::vector<int> vct5 = { 1, 1, 2, 2, 2, 4 };

	//printElement(sol.searchRange(vct, 1));//null
	//printElement(sol.searchRange(vct1, 1));//[0,0]
	//printElement(sol.searchRange(vct1, 2));//[-1,-1]
	//printElement(sol.searchRange(vct1, 3));//[-1,-1]
	//printElement(sol.searchRange(vct2, 1));//[0,0]
	//printElement(sol.searchRange(vct2, 2));//[1,1]
	//printElement(sol.searchRange(vct2, 3));//[2,2]
	//printElement(sol.searchRange(vct2, 5));//[-1,-1]
	//printElement(sol.searchRange(vct3, 1));//[0,3]
	//printElement(sol.searchRange(vct3, 11));//[-1,-1]
	//printElement(sol.searchRange(vct4, 2));//[1,2]
	//printElement(sol.searchRange(vct4, 3));//[3,4]
	//printElement(sol.searchRange(vct4, 1));//[0,0]
	//printElement(sol.searchRange(vct4, 33));//[-1,-1]
	//printElement(sol.searchRange(vct5, 1));//[0,1]
	//printElement(sol.searchRange(vct5, 2));//[2,4]
	//printElement(sol.searchRange(vct5, 3)); //[-1, -1]
	//printElement(sol.searchRange(vct5, 4));//[5,5]


	//test for add and search word-data structure design
	//WordDictionary wd;
	//wd.addWord("word");

	//std::cout.setf(std::ios::boolalpha);
	//std::cout << wd.search("he") << std::endl;//false
	//std::cout << wd.search("word") << std::endl;//true
	//std::cout << wd.search("wo") << std::endl;//false
	//std::cout << wd.search("w..d") << std::endl;//true
	//std::cout << wd.search("w.") << std::endl;//false
	//std::cout << wd.search("wo.") << std::endl;//false
	//std::cout << wd.search(".ord") << std::endl;//true
	//std::cout << wd.search("wor.") << std::endl; //true
	//std::cout << wd.search("....") << std::endl;//true


	//test for Search in Rotate Sorted Array
	//Solution sol;
	//std::vector<int> vec = {};
	//std::vector<int> vec1 = { 1, 2, 3, 4, 5 };
	//std::vector<int> vec2 = { 2, 3, 4, 5, 1 };
	//std::vector<int> vec3 = { 3, 4, 5, 1, 2 };
	//
	//std::cout << sol.search(vec,1) << std::endl; //-1

	//std::cout << std::endl;

	//std::cout << sol.search(vec1, 1) << std::endl;//0
	//std::cout << sol.search(vec1, 5) << std::endl;//4
	//std::cout << sol.search(vec1, 3) << std::endl;//2

	//std::cout << std::endl;

	//std::cout << sol.search(vec2, 2) << std::endl;//0
	//std::cout << sol.search(vec2, 1) << std::endl;//4
	//std::cout << sol.search(vec2, 4) << std::endl;//2

	//std::cout << std::endl;

	//std::cout << sol.search(vec3, 3) << std::endl;//0
	//std::cout << sol.search(vec3, 4) << std::endl;//1
	//std::cout << sol.search(vec3, 1) << std::endl;//3
	//std::cout << sol.search(vec3, 2) << std::endl;//4
	//std::cout << sol.search(vec3, 5) << std::endl;//2

	//test for Maximum Product Subarray
	Solution sol;

	std::vector<int> vec = { 2, 3, -2, 4 };
	std::vector<int> vec1 = { -2, 3, 6, 4 };
	std::vector<int> vec2 = {};
	std::vector<int> vec3 = { 1, 2, 3, 4, 5 };
	std::vector<int> vec4 = { 1 };
	std::vector<int> vec5 = { 1, -2, 3, -4, 5 };
	std::vector<int> vec6 = { 1, 2, 3, -4, -5 };
	std::vector<int> vec7 = { 1, -2, 3, -4, -5 };


	std::cout << sol.maxProduct(vec) << std::endl;//6
	std::cout << sol.maxProduct(vec1) << std::endl;//72
	std::cout << sol.maxProduct(vec2) << std::endl;//0
	std::cout << sol.maxProduct(vec3) << std::endl;//120
	std::cout << sol.maxProduct(vec4) << std::endl;//1
	std::cout << sol.maxProduct(vec5) << std::endl;//120
	std::cout << sol.maxProduct(vec6) << std::endl;//120
	std::cout << sol.maxProduct(vec7) << std::endl;//60

	std::cin.get();

	return 0;
}