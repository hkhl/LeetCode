/*************************************************************************
	> File Name: 746. Min Cost Climbing Stairs.cpp
	> Author: wang
	> Mail: dhkhl235@gmail.com
	> Created Time: 2018年04月27日 星期五 21时24分44秒
 ************************************************************************/

#include <iostream>
using namespace std;

/*
On a staircase, the i-th step has some non-negative cost cost[i] assigned (0 indexed).

Once you pay the cost, you can either climb one or two steps. You need to find minimum cost to reach the top of the floor, and you can either start from the step with index 0, or the step with index 1.

Example 1:
Input: cost = [10, 15, 20]
Output: 15
Explanation: Cheapest is start on cost[1], pay that cost and go to the top.
Example 2:
Input: cost = [1, 100, 1, 1, 1, 100, 1, 1, 100, 1]
Output: 6
Explanation: Cheapest is start on cost[0], and only step on 1s, skipping cost[3].
Note:
cost will have a length in the range [2, 1000].
Every cost[i] will be an integer in the range [0, 999].

*/



class Solution {
public:
    /*
     题意：
     
     数组的每个索引做为一个阶梯，第 i个阶梯对应着一个非负数的体力花费值 cost[i](索引从0开始)。

     每当你爬上一个阶梯你都要花费对应的体力花费值，然后你可以选择继续爬一个阶梯或者爬两个阶梯。      

     您需要找到达到楼层顶部的最低花费。在开始时，你可以选择从索引为 0 或 1 的元素作为初始阶梯。
    */
 
    /*
    解题： 动态规划 DP
    1. 重叠子问题
    2. 最优子结构
    
    爬到顶端，有两种爬法， 
    从最后一个上来， 或者从最后一个的前一个台阶上来， 选择其中花费小的台阶（最优）
    而最后一个，或者前一个台阶， 每一个爬法又是两个，  （重叠子问题）

    只需要知道爬上最后一个阶梯的最优解法 或者 爬上最后一个阶梯的前一个阶梯的最优解法 ok
    
    */
    int minCostClimbingStairs(vector<int>& cost) 
    {
        int n = cost.size();
        vector<int> dp(n);
        dp[0] = cost[0];
        dp[1] = cost[1];
        
        for(int i = 2; i < n; i++)
        {
            dp[i] = cost[i] + min(dp[i-1], dp[i-2]);  //记录爬每个阶梯的最优解
        }
        
        return min(dp[n-1], dp[n-2]);
    }
};
/*
space（1）解法，直接存原数组
 public int minCostClimbingStairs(int[] cost) {   
        for(int i = 2; i<cost.length; i++){
            cost[i] = cost[i]+Math.min(cost[i-1],cost[i-2]);
        }
        return Math.min(cost[cost.length-1],cost[cost.length-2]);
    }
*/

//同上解法， a代表最后爬上去的top  
//          b代表最后一个台阶， 
//          c代表前一个台阶
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int b=cost[1],c=cost[0];
        for (int i=2,a; i<cost.size(); ++i,c=b,b=a) 
            a=cost[i]+min(b,c);
        return min(b,c);
    }
};



