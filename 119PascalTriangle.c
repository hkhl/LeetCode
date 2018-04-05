/*************************************************************************
	> File Name: 119PascalTriangle2.c
	> Author: wang
	> Mail: dhkhl235@gmail.com
	> Created Time: 2018年04月05日 星期四 09时57分37秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>

/*
Given an index k, return the kth row of the Pascal's triangle.

For example, given k = 3,
Return [1,3,3,1].
*/
/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* getRow(int rowIndex, int* returnSize) {
    int i, j;
    int** returnarray = (int**)malloc((rowIndex+1)*sizeof(int*));
    for(i=0; i< rowIndex+1; i++)
    {
        *(returnarray+i) = (int*)malloc((i+1) * sizeof(int));
        for(j = 0; j <= i; j++)
        {
            if(j != 0 && j != i) 
            {
                *(*(returnarray+i)+j)=*(*(returnarray+i-1)+j-1)+*(*(returnarray+i-1)+j);
            }
        }
        returnarray[i][0] = returnarray[i][i] = 1;
    }
    
    *returnSize=rowIndex+1;
    return *(returnarray+rowIndex);
}
