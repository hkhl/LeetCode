/*************************************************************************
	> File Name: 485. Max Consecutive Ones.cpp
	> Author: wang
	> Mail: dhkhl235@gmail.com
	> Created Time: 2018年04月13日 星期五 00时06分00秒
 ************************************************************************/

#include <iostream>
using namespace std;


/*Given a binary array, find the maximum number of consecutive 1s in this array.

Example 1:
Input: [1,1,0,1,1,1]
Output: 3
Explanation: The first two digits or the last three digits are consecutive 1s.
    The maximum number of consecutive 1s is 3.
Note:

The input array will only contain 0 and 1.
The length of input array is a positive integer and will not exceed 10,000
* */












class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) 
    {
        int max = 0;
        int len = 0;
        int i = 0;
       
        while(i < nums.size())
        {
            if(nums[i] == 0)
                len = 0;
            if(nums[i] == 1)
                len++;
            if(max < len)
                max = len;
            i++;
        }
        return max;
    }
};
