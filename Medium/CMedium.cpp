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
    int currentLine = 0;
    bool reachedEdge = true;

    for (int i = 0; i < s.length(); ++i) 
    {
        if (currentLine == 0 || currentLine == numRows - 1) 
        {
            reachedEdge = !reachedEdge;
        }
        list.at(currentLine) += s.at(i);
        if (!reachedEdge) 
        {
            currentLine++;
        }
        else 
        {
            currentLine--;
        }
    }

    std::string result;
    for (int i = 0; i < numRows; ++i) 
    {
        result += list.at(i);
    }
    return result;
}
