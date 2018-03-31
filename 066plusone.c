/*************************************************************************
	> File Name: 066plusone.c
	> Author: wang
	> Mail: dhkhl235@gmail.com
	> Created Time: 2018年03月31日 星期六 12时14分07秒
 ************************************************************************/

/*
给定一个非负整数组成的非空数组，给整数加一。

可以假设整数不包含任何前导零，除了数字0本身。

最高位数字存放在列表的首位。


例: {9,9,9}   结果为{1,0,0,0}
    {8,9,9}   结果为{9,9,9}
    数组每一位存储一个数字
* */
#include <stdio.h>
#include <stdlib.h>

int* plusOne(int* a, int digitsSize, int* returnSize)
{   
    *returnSize = digitsSize;
    a[digitsSize-1] += 1;
    //末尾不等于10 直接return
    if(a[digitsSize-1] != 10)
    {
        return a;
    }
    else   //末尾等于10
    {
        for(int i = digitsSize-1; i >= 0; i--)
        {
            //如果其中某一位等于10，进行进位处理， 否则直接返回
            if(a[i] == 10)
            {
                a[i] = 0;           //进位处理： 当前位为0， 前一位+1
                if(i > 0)
                    a[i-1] += 1;
                else                //当i等于0时，且a[0] = 10, 则需开辟空间
                {
                    //注意申请空间大小不可以是sizeof(a)。  因为被弱化为指针， 
                    //sizeof求的是指针的大小 开辟的空间不够用
                    int *newa = (int *)malloc(sizeof(int) * (digitsSize + 1));
                    newa[0] = 1;   
                    for(int j = 0; j < digitsSize; j++)
                    {
                        newa[j+1] = a[j];
                    }
                    *returnSize = digitsSize+1;
                    return newa;
                }       
            }   
            else
            {
                return a;
            }
                
        }
    }
    return NULL;
}
