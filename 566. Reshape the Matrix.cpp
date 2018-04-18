/*************************************************************************
	> File Name: 566. Reshape the Matrix.cpp
	> Author: wang
	> Mail: dhkhl235@gmail.com
	> Created Time: 2018年04月18日 星期三 22时35分22秒
 ************************************************************************/

#include <iostream>
using namespace std;

/*
*
In MATLAB, there is a very useful function called 'reshape', which can reshape a matrix into a new one with different size but keep its original data.

You're given a matrix represented by a two-dimensional array, and two positive integers r and c representing the row number and column number of the wanted reshaped matrix, respectively.

The reshaped matrix need to be filled with all the elements of the original matrix in the same row-traversing order as they were.

If the 'reshape' operation with given parameters is possible and legal, output the new reshaped matrix; Otherwise, output the original matrix.

Example 1:
Input: 
nums = 
[[1,2],
 [3,4]]
r = 1, c = 4
Output: 
[[1,2,3,4]]
Explanation:
The row-traversing of nums is [1,2,3,4]. The new reshaped matrix is a 1 * 4 matrix, fill it row by row by using the previous list.
Example 2:
Input: 
nums = 
[[1,2],
 [3,4]]
r = 2, c = 4
Output: 
[[1,2],
 [3,4]]
Explanation:
There is no way to reshape a 2 * 2 matrix to a 2 * 4 matrix. So output the original matrix.
Note:
The height and width of the given matrix is in range [1, 100].
The given r and c are all positive.
* */

/*题意一堆废话, 就是将二维数组变成r行c列的新的二维数组, 如果不能变, 则返回原数组*/


class Solution {
public:
    //给一个矩阵 重新排列程r行c列    如果不可行，输出原先的矩阵
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) 
    {
        //不做错误判断了
        int row = nums.size();       //行的大小
        int column = nums[0].size(); //列的大小
        
        if(row * column != r * c)    //不符合要求返回源数组
        {
            return nums;
        }
        
        //符合要求  创建一个r行c列的二维数组填充元素返回则ok
        vector<vector<int> > vec(r, vector<int>(c));   
        
        for(int i = 0; i < r*c; i++)
        {
            vec[i/c][i%c] = nums[i/column][i%column];   //遍历nums 填充
        }
        return vec;
    }
};



