/*************************************************************************
	> File Name: 268. Missing Number.cpp
	> Author: wang
	> Mail: dhkhl235@gmail.com
	> Created Time: 2018年04月10日 星期二 10时36分44秒
 ************************************************************************/

#include <iostream>
using namespace std;
/*
*Given an array containing n distinct numbers taken from 0, 1, 2, ..., n, find the one that is missing from the array.

Example 1

Input: [3,0,1]
Output: 2
Example 2

Input: [9,6,4,2,3,5,7,0,1]
Output: 8

找出0~size 没有的那一个数字
* */

class Solution {
public:
    int missingNumber(vector<int>& nums) {
       
        //0~size没有那个数字
        int rst = 0;
        int i = 0;
        while(i <= nums.size())
        {
            rst += i;
            if(i < nums.size())
            {
                rst -= nums[i];
            }
            i++;
        }
        return rst;
    }
    /* 异或解法
    for(int i = 0; i < nums.size(); i++)
    {
        xor ^= i ^ nums[i];
    }
    return xor ^ i;
    */
};
