/*************************************************************************
	> File Name: 561. Array Partition I.cpp
	> Author: wang
	> Mail: dhkhl235@gmail.com
	> Created Time: 2018年04月18日 星期三 22时00分51秒
 ************************************************************************/

#include <iostream>
using namespace std;

/*
 *
Given an array of 2n integers, your task is to group these integers into n pairs of integer, say (a1, b1), (a2, b2), ..., (an, bn) which makes sum of min(ai, bi) for all i from 1 to n as large as possible.

Example 1:
Input: [1,4,3,2]

Output: 4
Explanation: n is 2, and the maximum sum of pairs is 4 = min(1, 2) + min(3, 4).
Note:
n is a positive integer, which is in the range of [1, 10000].
All the integers in the array will be in the range of [-10000, 10000].
 *
 * */



class Solution {
public:
    int arrayPairSum(vector<int>& nums) 
    {
        //题意 将数组分成若干个2个成员的分组， 每个分组取最小值， 最后求分组最小值的最大和
        int j = 0;
        int sum = 0;
        int n = nums.size()/2;  //一共n个分组
        
        
        //排序
        sort(nums.begin(), nums.end());
        
        for(int i = 0; i < nums.size(); i += 2)
        {
            nums[j++] = min(nums[i], nums[i+1]); //找出每两个中间最小的元素一次放在数组的前n个下标
        }
        
        for(int i = 0; i < n; i++)
        {
            sum += nums[i]; //求和
        }
        return sum;
    }
};



/*  看了下答案, 发现上面傻了个B, 排序好 每两个元素的前一个本来就是最小的
*  不需要求最小的元素了*/
class Solution {
public:
    int arrayPairSum(vector<int>& nums) 
    {
        int sum = 0;
        sort(nums.begin(), nums.end());
        
        for(int i = 0; i < nums.size(); i += 2)
        {
            sum += nums[i];
        }
        return sum;
    }
};
