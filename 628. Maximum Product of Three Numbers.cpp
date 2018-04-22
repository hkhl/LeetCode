/*************************************************************************
	> File Name: 628. Maximum Product of Three Numbers.cpp
	> Author: wang
	> Mail: dhkhl235@gmail.com
	> Created Time: 2018年04月22日 星期日 15时15分40秒
 ************************************************************************/

#include <iostream>
using namespace std;

/*
Given an integer array, find three numbers whose product is maximum and output the maximum product.

Example 1:
Input: [1,2,3]
Output: 6
Example 2:
Input: [1,2,3,4]
Output: 24
Note:
The length of the given array will be in range [3,104] and all elements are in the range [-1000, 1000].
Multiplication of any three numbers in the input won't exceed the range of 32-bit signed integer.
 */



/*大佬们的答案*/
//1 排序到也想过可以, 不过没想用排序来解决这个问题
int maximumProduct(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int n = nums.size();
    int temp1 = nums[n-1]*nums[n-2]*nums[n-3];
    int temp2 = nums[0]*nums[1]*nums[n-1];
    return temp1>temp2?temp1:temp2;
}


//牛逼解法(java) 
//返回最大的三个数 或者 2个负数和一个正数乘积  这两个数中较大的数

   public int maximumProduct(int[] nums) {
        int max1 = Integer.MIN_VALUE, max2 = Integer.MIN_VALUE, max3 = Integer.MIN_VALUE, min1 = Integer.MAX_VALUE, min2 = Integer.MAX_VALUE;
        for (int n : nums) {
            if (n > max1) {
                max3 = max2;
                max2 = max1;
                max1 = n;
            } else if (n > max2) {
                max3 = max2;
                max2 = n;
            } else if (n > max3) {
                max3 = n;
            }

            if (n < min1) {
                min2 = min1;
                min1 = n;
            } else if (n < min2) {
                min2 = n;
            }
        }
        return Math.max(max1*max2*max3, max1*min1*min2);
    }



 //以下为我自己的答案, 毫无疑问 被虐哭le  写了110行才解决问题,效率并不高
 //
 class Solution {
    /*******借鉴上边代码, 这两个函数代码可以合并*************/
    int findmax(vector<int>& nums)
    {
        vector<int> recvet(3);
        
        recvet[0] = recvet[1] = recvet[2] = INT_MIN;
        for(int i = 0; i < nums.size(); i++)
        {
            if(recvet[2] < nums[i])
            {
                recvet[0] = recvet[1];
                recvet[1] = recvet[2];
                recvet[2] = nums[i];
            }
            else if(nums[i] > recvet[1] && nums[i] <= recvet[2])
            {
                recvet[0] = recvet[1];
                recvet[1] = nums[i];
            }
            else if(nums[i] > recvet[0] && nums[i] <= recvet[1])
            {
                recvet[0] = nums[i];
            }
        }
        return recvet[0]*recvet[1]*recvet[2];
    }
    
    int findmaxabs(vector<int>& nums) //只能选择两个负数
    {  
        vector<int> recvet(3);
        recvet[0] = recvet[1] = recvet[2] = INT_MIN;
        
        
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] > recvet[2])
            {
                recvet[2] = nums[i];
            }
            
            if(nums[i] < 0)
            {
                int temp = -nums[i];
                if(temp > recvet[1])
                {
                    recvet[0] = recvet[1];
                    recvet[1] = temp;
                }
                else if(temp > recvet[0] && temp <= recvet[1])
                {
                    recvet[0] = temp;
                }
            }
        }
        
        return recvet[0]*recvet[1]*recvet[2];
    }
    
public:
    //题意： 从数组中找3个数， 且这3个数乘积最大
    int maximumProduct(vector<int>& nums) 
    {
        if(nums.size() == 3)
        {
            return nums[0]*nums[1]*nums[2];
        }
        else
        {
            //判断数组中元素类型
            //如果全是正数   （或者全是负数）            返回3个最大值
            // 负数1个    正数多个                      返回3个最大值
            // 如果正数1个 负数多个（大于等于3个），，，  返回2负1正
            // 多个负数 多个正数                        返回2父1正  和  3个最大值里面 找最大
      
            /*这里完全可以总结一下, 
            * 返回3个最大的数乘积 和 返回2负1正的乘积中较大的数字
            * 而不需要管其他细节*/
            
            /**************注释掉废代码*****************************
            int negative = 0, positive = 0;
            for(int i = 0; i < nums.size(); i++)
            {
                if(nums[i] >= 0)
                {
                    positive++;
                }
                else
                {
                    negative++;
                }
            }
            
            if(positive == 0 || negative == 0 || negative == 1)
            {
                //找最大
                return findmax(nums);
            }
            else if(positive == 1)
            {
                //2fu  1 zheng   //绝对值最大的3个数
                return findmaxabs(nums);
            }
            else****************************************************/
            {
                //2 fu 1 zheng  负数里绝对值最大的2个数 和+数最大的数字
                // 3 zheng      正数里绝对值最大的数
                //比对 找最大
                return findmaxabs(nums) > findmax(nums) ? findmaxabs(nums):findmax(nums);
            }
        }
        
    }
};
