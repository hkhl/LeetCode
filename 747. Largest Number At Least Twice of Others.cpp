/*************************************************************************
	> File Name: 747. Largest Number At Least Twice of Others.cpp
	> Author: wang
	> Mail: dhkhl235@gmail.com
	> Created Time: 2018年04月28日 星期六 17时01分11秒
 ************************************************************************/

#include <iostream>
using namespace std;
/*
In a given integer array nums, there is always exactly one largest element.

Find whether the largest element in the array is at least twice as much as every other number in the array.

If it is, return the index of the largest element, otherwise return -1.

Example 1:

Input: nums = [3, 6, 1, 0]
Output: 1
Explanation: 6 is the largest integer, and for every other number in the array x,
6 is more than twice as big as x.  The index of value 6 is 1, so we return 1.
 

Example 2:

Input: nums = [1, 2, 3, 4]
Output: -1
Explanation: 4 isn't at least as big as twice the value of 3, so we return -1.
 

Note:

nums will have a length in the range [1, 50].
Every nums[i] will be an integer in the range [0, 99].
 */





class Solution {
public:
    //题意： 找最大的数字， 是其他所有数字的二倍返回下标
    //否则返回-1
    
    //思路： 找到最大和次大 比较是否大于二倍
    int dominantIndex(vector<int>& nums) 
    {
        if(nums.size() < 1)
            return -1;
        else if(nums.size() == 1)
            return 0;
        int maxnum = 0, secmaxnum = 0;
        int index = 0;
        maxnum = max(nums[0], nums[1]);
        secmaxnum = min(nums[0], nums[1]);
        
        nums[0] > nums[1] ? index = 0 : index = 1;
        
        for(int i = 2; i  < nums.size(); i++)
        {
            if(nums[i] > maxnum)
            {
                index = i;
                secmaxnum = maxnum;
                maxnum = nums[i]; 
            }
            else if(nums[i] <= maxnum && nums[i] > secmaxnum)
            {
                secmaxnum = nums[i];
            }
        }
        cout << maxnum << " " << secmaxnum << endl;
        if(maxnum >= secmaxnum*2 )
            return index;
        return -1;
    }
};
