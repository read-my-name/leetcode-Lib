#pragma once
#include "include.h"

class CMedium
{
public:
	CMedium();
	~CMedium();

public:
	std::string convert(std::string s, int numRows);
	int reverse(int x);
	int myAtoi(std::string s);
	int maxArea(std::vector<int>& height);
	std::string intToRoman(int num);
	int romanToInt(std::string s);
	std::vector<std::vector<int>> threeSum(std::vector<int>& nums);
	int threeSumClosest(std::vector<int>& nums, int target);
	std::vector<std::string> letterCombinations(std::string digits);
};

