/*************************************************************************
	> File Name: 661. Image Smoother.cpp
	> Author: wang
	> Mail: dhkhl235@gmail.com
	> Created Time: 2018年04月24日 星期二 12时58分52秒
 ************************************************************************/

#include <iostream>
using namespace std;

/*
Given a 2D integer matrix M representing the gray scale of an image, you need to design a smoother to make the gray scale of each cell becomes the average gray scale (rounding down) of all the 8 surrounding cells and itself. If a cell has less than 8 surrounding cells, then use as many as you can.

Example 1:
Input:
[[1,1,1],
 [1,0,1],
 [1,1,1]]
Output:
[[0, 0, 0],
 [0, 0, 0],
 [0, 0, 0]]
Explanation:
For the point (0,0), (0,2), (2,0), (2,2): floor(3/4) = floor(0.75) = 0
For the point (0,1), (1,0), (1,2), (2,1): floor(5/6) = floor(0.83333333) = 0
For the point (1,1): floor(8/9) = floor(0.88888889) = 0
Note:
The value in the given matrix is in the range of [0, 255].
The length and width of the given matrix are in the range of [1, 150].

*/





/*笨方法处理这道题  分特殊情况特殊处理*/

class Solution {
public:
    //题意： 计算矩阵中某个点的平均值，  
    //具体求法是这个点加上与这个点直接相邻（上下左右斜）的各个点的和的平均值
    vector<vector<int>> imageSmoother(vector<vector<int>>& M) 
    {
        int row = M.size();
        int column = M[0].size();
        if(row == 1 && column == 1)        //1个元素直接返回
            return M;
        
        vector<vector<int> > W(row, vector<int>(column, 0));
     
        
     
        
        for(int i = 1; i < row-1; i++)         //处理中间的元素， 每个点周围都有8个点
        {
            for(int j = 1; j < column-1; j++)
            {
                W[i][j] = (M[i][j] + M[i-1][j-1] + M[i-1][j] + M[i-1][j+1] + M[i][j-1] + M[i][j+1] + M[i+1][j-1] + M[i+1][j] + M[i+1][j+1])/9;
            }
        }
        
        //处理首位两行
        for(int i = 1; i < column-1; i++)
        {
            if(row >= 2)
            {
                W[0][i] = (M[0][i] + M[0][i-1] + M[0][i+1] + M[1][i] + M[1][i-1] + M[1][i+1])/6;
                W[row-1][i] = (M[row-1][i] + M[row-1][i-1] + M[row-1][i+1] + M[row-2][i] + M[row-2][i-1] + M[row-2][i+1])/6;       
            }
            else
            {
                W[0][i] = (M[0][i-1] + M[0][i+1] + M[0][i])/3;
            }
        }
        
        //处理最前后两列
        for(int i = 1; i < row-1; i++)
        {
            if(column >= 2)
            {
                W[i][0] = (M[i][0] + M[i-1][0] + M[i+1][0] + M[i][1]+ M[i-1][1]+ M[i+1][1])/6;
                W[i][column-1] = (M[i][column-1]+M[i-1][column-1]+M[i+1][column-1]+M[i][column-2]+M[i-1][column-2]+M[i+1][column-2])/6;
            }
            else
            {
                W[i][0] = (M[i-1][0] + M[i+1][0] + M[i][0])/3;
            }
        }
        
        //处理四个角
        if(row >= 2 && column >= 2)
        {
            W[0][0] = (M[0][1] + M[1][0] + M[1][1] + M[0][0])/4;
            W[0][column-1] = (M[0][column-2] + M[1][column-1] + M[1][column-2] + M[0][column-1])/4;    
            W[row-1][0] = (M[row-2][0] + M[row-1][1] + M[row-2][1] + M[row-1][0])/4;
            W[row-1][column-1] = (M[row-1][column-2] + M[row-2][column-1] + M[row-2][column-2] + M[row-1][column-1])/4;    
        }
        else if(row == 1)
        {
            W[0][0] = (M[0][0] + M[0][1])/2;
            W[0][column-1] = (M[0][column-1] + M[0][column-2])/2;
        }
        else
        {
            W[0][0] = (M[0][0] + M[1][0])/2;
            W[row-1][0] = (M[row-1][0] + M[row-2][0])/2;
        }
        return W;
        
    }
};
