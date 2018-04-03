/*************************************************************************
	> File Name: 118PascalTriangle.c
	> Author: wang
	> Mail: dhkhl235@gmail.com
	> Created Time: 2018年04月03日 星期二 11时15分06秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#define N 10
/**
 * Return an array of arrays.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** generate(int numRows, int** columnSizes) 
{
    columnSizes = (int **)malloc(sizeof(int *) * numRows);
    if(columnSizes == NULL)
        return NULL;
    for(int i = 0; i < numRows; i++)
    {
        columnSizes[i] = (int *)malloc(sizeof(int) * (i+1));
        if(columnSizes[i] == NULL)
            return NULL;
    }
 
    for(int i = 0; i < numRows; i++)
    {
        for(int j = 0; j <= i; j++)
        {
            if(j != 0 && j != i)
            {
                columnSizes[i][j] = columnSizes[i-1][j] + columnSizes[i-1][j-1];
            }
        }
        columnSizes[i][0] = columnSizes[i][i] = 1;
    }
 
    return columnSizes;
}




int main()
{
    int **p = NULL;
    p = generate(N, p);
    
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j <= i; j++)
        {
              printf("%d ", p[i][j]);
         }
    printf("\n");
    }
    return 0;
}
