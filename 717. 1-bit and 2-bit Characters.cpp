/*************************************************************************
	> File Name: 717. 1-bit and 2-bit Characters.cpp
	> Author: wang
	> Mail: dhkhl235@gmail.com
	> Created Time: 2018年04月26日 星期四 22时37分06秒
 ************************************************************************/

#include <iostream>
using namespace std;

/*
We have two special characters. The first character can be represented by one bit 0. The second character can be represented by two bits (10 or 11).

Now given a string represented by several bits. Return whether the last character must be a one-bit character or not. The given string will always end with a zero.

Example 1:
Input: 
bits = [1, 0, 0]
Output: True
Explanation: 
The only way to decode it is two-bit character and one-bit character. So the last character is one-bit character.
Example 2:
Input: 
bits = [1, 1, 1, 0]
Output: False
Explanation: 
The only way to decode it is two-bit character and two-bit character. So the last character is NOT one-bit character.
Note:

1 <= len(bits) <= 1000.
bits[i] is always 0 or 1.

*/


class Solution {
public:
    //题意: 有10  11  0 三种情况， 末尾一定是0；
    //如果组合10 11 最后剩下单独一个0 返回 true
    //例如 11100 返回true   11 10 0 最后是单独的0
    //例如 1110  返回false  11 10   最后是10
    
    
    bool isOneBitCharacter(vector<int>& bits) 
    {
        int n = bits.size(), i;
    
        //对去掉0的剩下n-1个数字计算，
        //如果是1的话，i+2， 跳过两个数字 10、11
        //如果是0的话，i+1， 跳过当前的0
        // ......             ......
        //无论怎样跳， 如果最后跳了两次，说明最后的组合一定是10（返回false 最后的结合一定是10）
        //如果最后跳了1次，返回true
        
        for(i = 0; i < n-1; i++)
            if(bits[i])
                i++;
        return i == n-1;
    }
};




