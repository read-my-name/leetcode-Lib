#include "CMedium.h"

CMedium::CMedium()
{

}

CMedium::~CMedium()
{

}

std::string CMedium::convert(std::string s, int numRows) 
{// 6. Zigzag Conversion
    if (numRows <= 1 || numRows > 1000) 
    {// base case return
        return s;
    }
    std::vector<std::string> list(numRows, "");
    int icurRow = 0;
    bool isEdge = true;

    for (int i = 0; i < s.length(); ++i) 
    {
        if (icurRow == 0 || icurRow == numRows - 1)
        {// use a pointer to check the limit of row
            isEdge = !isEdge;
        }
        list.at(icurRow) += s.at(i);
        if (!isEdge)
        {
            icurRow++;
        }
        else 
        {
            icurRow--;
        }
    }

    std::string sRes;
    for (int i = 0; i < numRows; ++i) 
    {
        sRes += list.at(i);
    }
    return sRes;
}

int CMedium::reverse(int iNum)
{ //7. Reverse Integer
    if (iNum / 10 == 0)
    {// if the input is one digit
        return iNum;
    }

    int iRem = 0;
    // if use integer will exceed the limit
    long lTemp = 0;
    while (iNum) // if more than 0 will always true
    {// get the last digit by finding the remainder, times 10 and add into lTemp
        iRem = iNum % 10;
        lTemp = lTemp * 10 + iRem;
        iNum /= 10;
    }

    if (lTemp > INT_MAX || lTemp < INT_MIN)
    {// if exceed return 0
        return 0;
    }

    return lTemp;
}
