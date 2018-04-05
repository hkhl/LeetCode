/*************************************************************************
	> File Name: 121. Best Time to Buy and Sell Stock.cpp
	> Author: wang
	> Mail: dhkhl235@gmail.com
	> Created Time: 2018年04月05日 星期四 10时53分09秒
 ************************************************************************/
/*
*Say you have an array for which the ith element is the price of a given stock on day i.

If you were only permitted to complete at most one transaction (ie, buy one and sell one share of the stock), design an algorithm to find the maximum profit.

Example 1:
Input: [7, 1, 5, 3, 6, 4]
Output: 5

max. difference = 6-1 = 5 (not 7-1 = 6, as selling price needs to be larger than buying price)
Example 2:
Input: [7, 6, 4, 3, 1]
Output: 0

In this case, no transaction is done, i.e. max profit = 0.
* */

#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;


class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        int minprices = INT_MAX; 
        int maxpro = 0;
       
        for(int i = 0; i < prices.size(); i++)
        {
            minprices = min(minprices, prices[i]);
            maxpro = max(maxpro, prices[i] - minprices);
        }
        return maxpro;
    }
};
