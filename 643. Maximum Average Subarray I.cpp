/*************************************************************************
	> File Name: 643. Maximum Average Subarray I.cpp
	> Author: wang
	> Mail: dhkhl235@gmail.com
	> Created Time: 2018年04月23日 星期一 22时52分18秒
 ************************************************************************/

#include <iostream>
using namespace std;


Given an array consisting of n integers, find the contiguous subarray of given length k that has the maximum average value. And you need to output the maximum average value.

Example 1:
Input: [1,12,-5,-6,50,3], k = 4
Output: 12.75
Explanation: Maximum average is (12-5-6+50)/4 = 51/4 = 12.75
Note:
1 <= k <= n <= 30,000.
Elements of the given array will be in the range [-10,000, 10,000].




class Solution {
public:
    //题意：给定一个K值， 然后根据k值，找出连续k的最大数，
    //在求平均
    //思路： 俩指针， 一个前一个后， 每次对两个指针范围内的求和， 求最大
    double findMaxAverage(vector<int>& nums, int k) 
    {
        int max = INT_MIN;
        int sum  = 0;
        int m = 0, n = k;
        int flag = 0;
        
        for(int i = 0; i <= nums.size() - k; i++)
        {
            m = i;
            n = i + k;
            sum = 0;
            
            for(int j = m; j < n; j++)
            {
                sum += nums[j]; 
            }
            
            if(max < sum)
            {
                max = sum;
                flag = m;
            }            
        }
        
        double db = max / (double)k;
        return db;
    }
};
