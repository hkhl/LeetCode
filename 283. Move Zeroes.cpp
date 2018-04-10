/*************************************************************************
	> File Name: 283. Move Zeroes.cpp
	> Author: wang
	> Mail: dhkhl235@gmail.com
	> Created Time: 2018年04月10日 星期二 10时41分30秒
 ************************************************************************/

#include <iostream>
using namespace std;


/*
 *Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.

For example, given nums = [0, 1, 0, 3, 12], after calling your function, nums should be [1, 3, 12, 0, 0].

Note:
You must do this in-place without making a copy of the array.
Minimize the total number of operations.

将0移动到后方, 同时不改变原来数组的顺序
 * */



class Solution {
public:
    void moveZeroes(vector<int>& nums) 
    {
        int pi = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            //这里条件不可以为(nums[i] != 0 && i != pi)
            //如果加上i!=pi , 那么输入数组 [1], 不会发生交换 pi不会++
            //输出为0 错误.
            if(nums[i] != 0)
            {
                swap(nums[i], nums[pi++]);
            }
        }
    }
};
