/*************************************************************************
	> File Name: 136. Single Number.cpp
	> Author: wang
	> Mail: dhkhl235@gmail.com
	> Created Time: 2018年04月06日 星期五 19时05分10秒
 ************************************************************************/
/*
 *
*Given an array of integers, every element appears twice except for one. Find that single one.

Note:
Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
找惟一一个不重复的元素, O(n) 不用额外空间
*
* */

#include <iostream>
#include <vector>
using namespace std;

/* 神一样的答案 */
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        
        int res = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            res ^= nums[i];
        }
        return res;
    }
};


