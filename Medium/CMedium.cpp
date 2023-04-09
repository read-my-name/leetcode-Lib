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
