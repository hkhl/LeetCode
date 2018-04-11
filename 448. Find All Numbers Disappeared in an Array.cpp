/*************************************************************************
	> File Name: 448. Find All Numbers Disappeared in an Array.cpp
	> Author: wang
	> Mail: dhkhl235@gmail.com
	> Created Time: 2018年04月11日 星期三 19时58分26秒
 ************************************************************************/

#include <iostream>
using namespace std;

/*
* Given an array of integers where 1 ≤ a[i] ≤ n (n = size of array), some elements appear twice and others appear once.

Find all the elements of [1, n] inclusive that do not appear in this array.

Could you do it without extra space and in O(n) runtime? You may assume the returned list does not count as extra space.

Example:

Input:
[4,3,2,7,8,2,3,1]

Output:
[5,6]

给定范围是1-size(数组长度)
数组中有重复元素, 找出数组中相比 1-n 而没有出现的数字
*/

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) 
    {

        vector<int> retvec;

        //假设下标 0 到 n 个位置对应坐的数字分别是 1 ~ n+1
        //例如 0~7 对应的数字是1~8 刚好没有重复
        //我们从0号位置开始遍历， 假设a[0]对应的数字 7，  则说明a[6]是被人拥有的了
        //那么将a[6]的值设置为负的，  最终发现谁的值依旧是正数， 那么说明没有那个位置本应该坐的数字
        //遍历的时候需要注意的是， 对大于0的数字才取负， 小于0的数字不管。  
        
        int val;
        for(int i = 0; i < nums.size(); i++)
        {
            val = abs(nums[i]) - 1;  //计算本应该坐的下标位置，  带绝对值防止某些数字已经被更改为负数了
            if(nums[val] > 0)
            {
                nums[val] = -nums[val];
            }
        }
        
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] > 0)
            {
                retvec.push_back(i+1);    //i号座位没人， 那说明对应的数字是i+1
            }
        }
        
        return retvec;
    }
};

