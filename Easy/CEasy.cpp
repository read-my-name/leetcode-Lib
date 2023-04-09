#include "CEasy.h"

CEasy::CEasy()
{

}

CEasy::~CEasy()
{

}

bool CEasy::isPalindrome(int iX)
{// 9. Palindrome Number
	bool bRes = false;
	if (iX <= 0 || iX%10 == 0)
	{
		return bRes;
	}
	int iBack = 0;
	while (iX > iBack) 
	{
		//check the remainder
		int irem = iX % 10; 
		// sum up from the last digit using *10 + rem
		iBack = iBack * 10 + irem;
		//reduce the length of input number
		iX /= 10;
	}
	// iX == iBack if it is an even digit
	// iX == iBack/10 remove the iBack's last digit by using /10
	return (iX == iBack || iX == iBack / 10);
}
