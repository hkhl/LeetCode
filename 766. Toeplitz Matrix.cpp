/*************************************************************************
	> File Name: 1.c
	> Author: wang
	> Mail: dhkhl235@gmail.com
	> Created Time: 2018年04月27日 星期五 21时29分14秒
 ************************************************************************/

#include <stdio.h>



/*
 A matrix is Toeplitz if every diagonal from top-left to bottom-right has the same element.

Now given an M x N matrix, return True if and only if the matrix is Toeplitz.
 

Example 1:

Input: matrix = [[1,2,3,4],[5,1,2,3],[9,5,1,2]]
Output: True
Explanation:
1234
5123
9512

In the above grid, the diagonals are "[9]", "[5, 5]", "[1, 1, 1]", "[2, 2, 2]", "[3, 3]", "[4]", and in each diagonal all elements are the same, so the answer is True.
Example 2:

Input: matrix = [[1,2],[2,2]]
Output: False
Explanation:
The diagonal "[1, 2]" has different elements.
Note:

matrix will be a 2D array of integers.
matrix will have a number of rows and columns in range [1, 20].
matrix[i][j] will be integers in range [0, 99].
 
*/


class Solution {
public:
    //处于统一斜线的值都相等返回true 否则返回flase
    bool isToeplitzMatrix(vector<vector<int>>& matrix) 
    {
        int flag = 1;
        for(int i = 0; i < matrix.size()-1; i++)
        {
            for(int j = 0; j < matrix[0].size()-1; j++)
            {
                if(matrix[i][j] != matrix[i+1][j+1])
                {
                    flag = 0;
                    break;
                }
            }
        }
        return flag;
    }
};
