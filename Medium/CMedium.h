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
};

