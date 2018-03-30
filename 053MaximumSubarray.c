/*************************************************************************
	> File Name: 053MaximumSubarray.c
	> Author: wang
	> Mail: dhkhl235@gmail.com
	> Created Time: 2018年03月30日 星期五 23时28分02秒
 ************************************************************************/
/*
* Find the contiguous subarray within an array (containing at least one number) which has the largest sum.

For example, given the array [-2,1,-3,4,-1,2,1,-5,4],
the contiguous subarray [4,-1,2,1] has the largest sum = 6.

click to show more practice.

More practice:
If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.
* */

#include <stdio.h>

/* 时间复杂度O(n) */
int maxSubArray1(int* a, int numsSize) 
{
    int max, presentmax;

    max = presentmax = a[0];
    for(int i = 1; i < numsSize; i++)
    {
        /* 如果前面子串和小于等于0, 那么选取当前下标为最大值 */
        if(presentmax <= 0)
        {
            presentmax = a[i];       
        }
        else
        {
            presentmax += a[i]; //如果前面字串大于0, 那么加上现在的下标数    
        }

        //如果前面字串和大于记录的最大字串和 替换
        if(presentmax > max)  
        {
            max = presentmax;      
        }
    }
    return max;
}


/* 暴力破解法 O(n^2) */
//双重for循环, 从第一个下标开始向后求和,记录其中的最大值

