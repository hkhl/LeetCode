/*************************************************************************
	> File Name: 026RemoveDuplicatesfromSortedArray.c
	> Author: wang
	> Mail: dhkhl235@gmail.com
	> Created Time: 2018年03月26日 星期一 22时43分38秒
 ************************************************************************/

#include <stdio.h>
#define N 5

int removeDuplicates(int* nums, int numsSize) 
{
    int newlen  = numsSize;

    for(int i = 1; i < numsSize; i++)
    {
        if(nums[i] == nums[i-1])
        {
            newlen--;
        }
    }

    for(int i = 1; i < numsSize; i++)
    {
        if(nums[i] == nums[i-1])
        {
            for(int j = i; j < numsSize - 1; j++)
            {
                nums[j] = nums[j+1];
            }
            numsSize--;
            i--;
        }
    }    
    return newlen;
}

int main()
{
    int a[N] = {1,1,1,2,3};
    // 测试数据
    // int a[N] ={1,1,2};
    // int a[N] ={1,1,1};
    // int a[N] ={1,1,1,2};
                
    int len = removeDuplicates(a, N);

    for(int i = 0 ; i < len; i++)
        printf("%d\n", a[i]);
}
