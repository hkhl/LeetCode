/*************************************************************************
	> File Name: 674. Longest Continuous Increasing Subsequence.cpp
	> Author: wang
	> Mail: dhkhl235@gmail.com
	> Created Time: 2018年04月25日 星期三 10时54分56秒
 ************************************************************************/

#include <iostream>
using namespace std;

/*
Given an unsorted array of integers, find the length of longest continuous increasing subsequence (subarray).

Example 1:
Input: [1,3,5,4,7]
Output: 3
Explanation: The longest continuous increasing subsequence is [1,3,5], its length is 3. 
Even though [1,3,5,7] is also an increasing subsequence, it's not a continuous one where 5 and 7 are separated by 4. 
Example 2:
Input: [2,2,2,2,2]
Output: 1
Explanation: The longest continuous increasing subsequence is [2], its length is 1. 
*/


class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) 
    {
        if(nums.size() == 0)
            return 0;
        int  maxlen = 0;
        int templen = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            if(i == 0 || nums[i-1] < nums[i])
            {
                templen++;
                maxlen = max(maxlen, templen);
            }
            else
                templen = 1;
        }
        return maxlen;
    }
};

