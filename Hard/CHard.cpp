#include "CHard.h"

CHard::CHard()
{

}

CHard::~CHard()
{

}

double CHard::findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2)
{   //4. Median of Two Sorted Arrays
	double dRes = 0.0;

	int iMin = INT_MIN;
	int iMax = INT_MAX;
    
    // Initilaization of some neccessary variables
    int n1 = int(nums1.size());
    int n2 = int(nums2.size());
    int n = n1 + n2;

    if (n1 > n2)
    {
        return findMedianSortedArrays(nums2, nums1);
    }
    // When length is even, let's say 10 then left half length should be: (10+1)/2 =>5
    // When length is odd, let's say 11 then left half length should be: (11+1)/2 =>6
    // This mean that this formula gonna work in both condition
    int partition = (n + 1) / 2;


    // if empty exist
    if (n1 == 0)
        return n2 % 2 ? nums2[n2 / 2] : (nums2[n2 / 2] + nums2[n2 / 2 - 1]) / 2.0;

    if (n2 == 0)
        return n1 % 2 ? nums1[n1 / 2] : (nums1[n1 / 2] + nums1[n1 / 2 - 1]) / 2.0;

    // Now do Partioning
    int left1 = 0;
    int right1 = n1;
    int m1, m2;
    int l1, r1, l2, r2;
    int iCount = 1;
    do
    {
        
        // initialise 'm1' and 'm2'
        m1 = (left1 + right1) / 2;
        m2 = partition - m1;
        char cRes[100], cl1[100], cl2[100], cr1[100], cr2[100];
        sprintf_s(cRes, "The count %d left1=%d right1=%d partition=%d m1=%d m2=%d\n", iCount, left1, right1, partition, m1, m2);
        std::cout << cRes;

        // Calculation for l1
        l1 = m1 == 0 ? INT_MIN : nums1[m1 - 1];
        sprintf_s(cl1, "The l1 %d \n", l1);
        
        // Calculation for l2
        l2 = m2 == 0 ? INT_MIN : nums2[m2 - 1];
        sprintf_s(cl2, "The l2 %d \n", l2);
        
        // Calculation for r1
        r1 = m1 >= n1 ? INT_MAX : nums1[m1];
        sprintf_s(cr1, "The r1 %d \n", r1);
        
        // Calculation for r2
        r2 = m2 >= n2 ? INT_MAX : nums2[m2];
        sprintf_s(cr2, "The r2 %d \n", r2);

        std::cout << cl1;
        std::cout << cr1;
        std::cout << cl2;
        std::cout << cr2;

        if (l1 <= r2 && l2 <= r1)
        {
            // Return Result
            return n % 2 ? std::max(l1, l2) : (std::max(l1, l2) + std::min(r1, r2)) / 2.0;
        }
        else
        {
            if (l1 > r2)
            {// shorten right side
                right1 = m1 - 1;
            }
            else
            {// increase left side
                left1 = m1 + 1;
            }
        }
        iCount++;
    } while (left1 <= right1);

	return dRes;
}