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

int CMedium::myAtoi(std::string s)
{// 8. String to Integer (atoi)
    int len = int(s.size());
    long num = 0;
    int i = 0;

    while (i < len && s[i] == ' ')
    {
        i++;
    }
    bool negative = s[i] == '-';

    if (s[i] == '+' || s[i] == '-')
    {
        i++;
    }
    while (i < len && isdigit(s[i]))
    {// minus '0' = convert the digit and add 0 on it
        num = num * 10 + (s[i] - '0');

        if (num > INT_MAX || (negative && -num < INT_MIN))
        {
            return negative ? INT_MIN : INT_MAX;
        }
        i++;
    }
    return negative ? -num : num;
}


int CMedium::maxArea(std::vector<int>& height)
{// 11. Container With Most Water
    int nlen = int(height.size());
    int nRes = 0;
    int b1 = 0;
    int b2 = nlen - 1;
    while (b1 < b2)
    {
        if (height[b1] > height[b2])
        {
            nRes = std::max(nRes, (b2 - b1) * height[b2]);
            b2--;
        }
        else
        {
            nRes = std::max(nRes, (b2 - b1) * height[b1]);
            b1++;
        }
    }
    return nRes;

}

std::string CMedium::intToRoman(int num) 
{// 12. Integer to Roman
    // there's some tips on coverting.
    // Eg1 4 need to use '-' such as IV = 5-1 =4
    // Eg2 9 need to use '-' such as IX = 10-1 = 9
    // So only 2 scenarios requires to use minus/'-' 
    std::string ones[] = { "","I","II","III","IV","V","VI","VII","VIII","IX" };
    std::string tens[] = { "","X","XX","XXX","XL","L","LX","LXX","LXXX","XC" };
    std::string hrns[] = { "","C","CC","CCC","CD","D","DC","DCC","DCCC","CM" };
    std::string ths[] = { "","M","MM","MMM" };

    return ths[num / 1000] + hrns[(num % 1000) / 100] + tens[(num % 100) / 10] + ones[num % 10];
}

int CMedium::romanToInt(std::string s)
{// 13. Roman to Integer
    int ans = 0;
    std::unordered_map <char, int> mp{
    {'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000} };

    for (int i = 0; i < s.size(); i++) {
        if (mp[s[i]] < mp[s[i + 1]]) 
        {
            //for cases such as IV,CM, XL, etc...
            // Eg IV = 1st col < 2nd col
            ans = ans - mp[s[i]];
        }
        else 
        {
            ans = ans + mp[s[i]];
        }
    }
    return ans;
}