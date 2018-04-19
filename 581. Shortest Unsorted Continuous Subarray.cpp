/*************************************************************************
	> File Name: 581. Shortest Unsorted Continuous Subarray.cpp
	> Author: wang
	> Mail: dhkhl235@gmail.com
	> Created Time: 2018年04月19日 星期四 16时47分39秒
 ************************************************************************/

#include <iostream>
using namespace std;


/*
Given an integer array, you need to find one continuous subarray that if you only sort this subarray in ascending order, then the whole array will be sorted in ascending order, too.

You need to find the shortest such subarray and output its length.

Example 1:
Input: [2, 6, 4, 8, 10, 9, 15]
Output: 5
Explanation: You need to sort [6, 4, 8, 10, 9] in ascending order to make the whole array sorted in ascending order.
Note:
Then length of the input array is in range [1, 10,000].
The input array may contain duplicates, so ascending order here means <=.

*/



class Solution {
public:
    //题意： 找到最短的可以一个子数组， 只要这个子数组是有序的， 那么整个数组就是有序的
    int findUnsortedSubarray(vector<int>& nums) 
    {
        //不做错误处理
        int n = nums.size();
        int beg = -1, end = -2;   //初始化wei -2 -1 当虚列有序的话， 返回 -2 - (-1) + 1 = 0;
        int minnum = nums[n-1];
        int maxnum = nums[0];
        
        //记录 max = a[0]   min = a[n-1]
        //循环遍历 记录其中最大的 max 和最小的 min
        //当有数字比 max 小的时候 ， 记录其下标
        //当有数字比 min 大的时候 ， 记录其下标
        //其中的思想是 ：
        //遍历一边， 找到 右边 比 左边最大的数字还要小 的那个数字的下标
        //找到左边比右边最小的数字还要大的数字的下标 进行记录
        //对这个范围内的数据进行长度统计
        
        for (int i=1;i<n;i++) 
        {
            maxnum = max(maxnum, nums[i]);
            minnum = min(minnum, nums[n-1-i]);
            if (nums[i] < maxnum) 
                end = i;
            if (nums[n-1-i] > minnum) 
                beg = n-1-i; 
        }
        return end - beg + 1;
    }
};




