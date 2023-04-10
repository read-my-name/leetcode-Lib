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
};

