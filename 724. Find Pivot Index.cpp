/*************************************************************************
	> File Name: 724. Find Pivot Index.cpp
	> Author: wang
	> Mail: dhkhl235@gmail.com
	> Created Time: 2018年04月26日 星期四 23时27分32秒
 ************************************************************************/

#include <iostream>
using namespace std;

/*
Given an array of integers nums, write a method that returns the "pivot" index of this array.

We define the pivot index as the index where the sum of the numbers to the left of the index is equal to the sum of the numbers to the right of the index.

If no such index exists, we should return -1. If there are multiple pivot indexes, you should return the left-most pivot index.

Example 1:
Input: 
nums = [1, 7, 3, 6, 5, 6]
Output: 3
Explanation: 
The sum of the numbers to the left of index 3 (nums[3] = 6) is equal to the sum of numbers to the right of index 3.
Also, 3 is the first index where this occurs.
Example 2:
Input: 
nums = [1, 2, 3]
Output: -1
Explanation: 
There is no index that satisfies the conditions in the problem statement.
Note:

The length of nums will be in the range [0, 10000].
Each element nums[i] will be an integer in the range [-1000, 1000].

*/






class Solution {
public:
    //题意： 返回数组的中心索引。 使得左边和等于右边和， 如果无， 返回-1
    //思路：  (XXXXXXXXXX 思路不可取， 若数字均是负数， 则不成立)
    //左边 == 右边 返回中间，
    //左边 > 右边 左边+1
    //    <      右边+1
    //
    
    //求总和，  求左侧和。
    //总和减去左侧和减去nums[i] 等于 左侧和
    //i值是中心索引
    int pivotIndex(vector<int>& nums) 
    {
        if(nums.size() == 0)
            return -1;

        int left = 0;
        int leftsum = 0;
        int sum = 0;
        for(auto num : nums)
            sum += num;
        
        for(int i = 0; i < nums.size(); i++)
        {
            if(leftsum == sum - leftsum - nums[i])
                return i;
            leftsum += nums[i];
        }
        return -1;   
    }
};
