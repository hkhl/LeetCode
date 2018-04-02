/*************************************************************************
	> File Name: 088MergeSortedArray.c
	> Author: wang
	> Mail: dhkhl235@gmail.com
	> Created Time: 2018年04月02日 星期一 23时02分38秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>

void merge(int* nums1, int m, int* nums2, int n) 
{
 
    //int s = m + n;
    //可以从后考虑，每次都先填写最大的值， 依次向前填写，
    //比下面的方法更好， 因为不需要开辟空间，。
    int i, j, k;
    i = j = k = 0;
    int *temparr = (int *)malloc(sizeof(int) * (m + n));
    
    while(i < m && j < n)
    {
        if(nums1[i] > nums2[j])           
        {
            temparr[k++] = nums2[j++];
        }
        else
        {
            temparr[k++] = nums1[i++];
        }
    }
    
    while(i < m)
    {
        temparr[k++] = nums1[i++];
    }
    while(j < n)
    {
        temparr[k++] = nums2[j++];
    }
    for(int i = 0; i < k; i++)
    {
        nums1[i] = temparr[i];
    }
    
    free(temparr);
    
}

