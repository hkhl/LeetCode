/*************************************************************************
	> File Name: 89. Gray Code.cpp
	> Author: wang
	> Mail: dhkhl235@gmail.com
	> Created Time: 2018年04月21日 星期六 11时57分23秒
 ************************************************************************/

#include <iostream>
using namespace std;


/*
 *
The gray code is a binary numeral system where two successive values differ in only one bit.

Given a non-negative integer n representing the total number of bits in the code, print the sequence of gray code. A gray code sequence must begin with 0.

For example, given n = 2, return [0,1,3,2]. Its gray code sequence is:

00 - 0
01 - 1
11 - 3
10 - 2
Note:
For a given n, a gray code sequence is not uniquely defined.

For example, [0,2,3,1] is also a valid gray code sequence according to the above definition.

For now, the judge is able to judge based on one instance of gray code sequence. Sorry about that.

 */





/******便于理解,可以先看c代码如何打印的格雷编码********/
class Solution {
    //格雷编码，连续的编码内只有一位有差别   第一位一定是0
    //例如： 00 01 11 10  或者  00 10 11 01
    //递归实现 
    // 1. 对n位的操作 相当于对n-1位进行操作 
    // 2. 将自己所在位置反转 
    // 3. 再次对n-1位进行操作    
    void utils(bitset<32>& bits, vector<int>& result, int k){
        if (k==0) {
            result.push_back(bits.to_ulong());  //将二进制位转换为整数
        }
        else {
            utils(bits, result, k-1);
            bits.flip(k-1);
            utils(bits, result, k-1);
        }
    }
public:
    vector<int> grayCode(int n) {
        bitset<32> bits;
        vector<int> result;
        utils(bits, result, n);
        return result;
    }
    
};

