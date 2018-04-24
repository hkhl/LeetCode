/*************************************************************************
	> File Name: 665. Non-decreasing Array.cpp
	> Author: wang
	> Mail: dhkhl235@gmail.com
	> Created Time: 2018年04月24日 星期二 17时14分27秒
 ************************************************************************/

#include <iostream>
using namespace std;

/*
 *Given an array with n integers, your task is to check if it could become non-decreasing by modifying at most 1 element.

We define an array is non-decreasing if array[i] <= array[i + 1] holds for every i (1 <= i < n).

Example 1:
Input: [4,2,3]
Output: True
Explanation: You could modify the first 4 to 1 to get a non-decreasing array.
Example 2:
Input: [4,2,1]
Output: False
Explanation: You can't get a non-decreasing array by modify at most one element.
Note: The n belongs to [1, 10,000].

 */





class Solution {
public:
    //题意： 修改数组中一个数字 ，能让其变为升序 返回true 否则返回false
    bool checkPossibility(vector<int>& nums) 
    {
        //比较前一个比当前这个大的话记录加1， 在比较前两个是否比当前这个大， 大的话，将当前这个赋值为前一个
        int cnt = 0;                                                                    //the number of changes
        for(int i = 1; i < nums.size() && cnt<=1 ; i++)
        {
            if(nums[i-1] > nums[i])
            {
                cnt++;
                if(i-2 >= 0 && nums[i-2] > nums[i])
                    nums[i] = nums[i-1];                                                //have to modify nums[i]
            }
        }
        return cnt<=1;
    }
};

           



