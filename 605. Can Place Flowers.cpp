/*************************************************************************
	> File Name: 605. Can Place Flowers.cpp
	> Author: wang
	> Mail: dhkhl235@gmail.com
	> Created Time: 2018年04月20日 星期五 11时24分10秒
 ************************************************************************/

#include <iostream>
using namespace std;
/*
Suppose you have a long flowerbed in which some of the plots are planted and some are not. However, flowers cannot be planted in adjacent plots - they would compete for water and both would die.

Given a flowerbed (represented as an array containing 0 and 1, where 0 means empty and 1 means not empty), and a number n, return if n new flowers can be planted in it without violating the no-adjacent-flowers rule.

Example 1:
Input: flowerbed = [1,0,0,0,1], n = 1
Output: True
Example 2:
Input: flowerbed = [1,0,0,0,1], n = 2
Output: False
Note:
The input array won't violate no-adjacent-flowers rule.
The input array size is in the range of [1, 20000].
n is a non-negative integer which won't exceed the input array size.

*/
class Solution {
public:
    //种花问题， 花圃给好， 且中了些花儿（1表示种花， 0表示空地）
    //花不能种在相临的地方 否则会死
    //现在要种n朵花， 在已有的空地能否不违反规则(相邻不种花)的情况种花
    //输入的数组， 不会违反规则
    bool canPlaceFlowers(vector<int>& bed, int n) 
    {
        //巧妙的答案往往代码都很简单,看起来颇具有艺术感。
        //
        //解法1: 给头和尾都添加一个0. 让其符合每3个0中间写一个1的条件
        
        bed.insert(bed.begin(), 0);
        bed.push_back(0);
        
        for(int i = 1; i < bed.size() - 1; i++)
        {
            if(bed[i-1] + bed[i] + bed[i+1] == 0)
            {
                n--;
                i++;
            }
        }
        return n <= 0;
    }
};


class Solution2 {
public:
    bool canPlaceFlowers(vector<int>& bed, int n) 
    {
        //巧妙的答案往往代码都很简单,看起来颇具有艺术感。
        //
        //解法2: 强逻辑判断, 在符合规则的bed[i]填充1
        
        for(int i = 0; i < bed.size(); i++)
        {
            if(!bed[i] && (i == 0 || !bed[i-1]) && (i == bed.size()-1 || !bed[i+1])) //巧妙的语句 巧妙的截断
            {
                n--;
                bed[i] = 1;
            }
        }
        return n <= 0;
    }
};


