/*************************************************************************
	> File Name: 122. Best Time to Buy and Sell Stock2.cpp
	> Author: wang
	> Mail: dhkhl235@gmail.com
	> Created Time: 2018年04月05日 星期四 11时16分52秒
 ************************************************************************/

/*
*Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete as many transactions as you like (ie, buy one and sell one share of the stock multiple times). However, you may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
* 可以买入卖出进行多次操作
* */
#include <iostream>
#include <vector>
using namespace std;



class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0;
        for(int i = 1; i < prices.size(); i++){
            res += max(prices[i]- prices[i-1], 0);           
        }
        return res;
    }
};


