/*
 *You are climbing a stair case. It takes n steps to reach to the top.
 *
 *Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
 *
 *Note: Given n will be a positive integer.
 *
 *Example 1:
 *
 *Input: 2
 *Output: 2
 *Explanation: There are two ways to climb to the top.
 *1. 1 step + 1 step
 *2. 2 steps
 *Example 2:
 *
 *Input: 3
 *Output: 3
 *Explanation: There are three ways to climb to the top.
 *1. 1 step + 1 step + 1 step
 *2. 1 step + 2 steps
 *3. 2 steps + 1 step
 */
class Solution {
public:
    //题意： 爬n太阶的方法有多少总   类似于斐波纳妾
    int climbStairs(int n)
    {
        //爬n个阶梯的方法，等于爬n-1个阶梯的方法  加上 n-2个阶梯的方法 + 1
      /*
        if (n == 1)
            return 1;
        else if (n == 2)
            return 2;
        else
            return climbStairs(n-1) + climbStairs(n-2);
        不ok ， 当n比较大时， 将会超时
    */
       /*
        int a = 1;
        int b = 1;
        int rst = 1;

        for(int i = 2; i <= n; i++)
        {
            rst = a + b;
            a = b;
            b = rst;
        }
        return rst;
        */

        //DP
        vector<int> dp(n);

        dp[0] = 1;
        dp[1] = 2;
        for(int i = 2; i < n; i++)
        {
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n-1];
    }
};
