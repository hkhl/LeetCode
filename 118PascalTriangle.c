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
    int i=0;    
    int j=0;

    if(numRows == 0)
    return 0;

    int ** returnArray = (int **)malloc(sizeof(int *) * numRows);
    for(i = 0; i < numRows; i++)
    {
        returnArray[i] = (int *)malloc(sizeof(int) * (i+1));
    }

    *columnSizes = (int *)malloc(sizeof(int)*numRows);

    for(i=0; i<numRows; i++)
    {
        (*columnSizes)[i] = i+1;
        for(j=0; j<i+1; j++)
        {
            if( (0 != j)  && (i != j) )
            returnArray[i][j] = returnArray[i-1][j-1] + returnArray[i-1][j];
        }
        returnArray[i][0] = returnArray[i][i] = 1;
    }

    return returnArray;

}

int main()
{
    int **p = NULL;
    int *columnSizes;
    p = generate(N, &columnSizes);


    printf("\n");
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < columnSizes[i]; j++)
        {
            printf("%d ", p[i][j]);
        }
        printf("\n");
    }
    return 0;
}
