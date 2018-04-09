/*************************************************************************
	> File Name: 219. Contains Duplicate II.cpp
	> Author: wang
	> Mail: dhkhl235@gmail.com
	> Created Time: 2018年04月09日 星期一 19时29分55秒
 ************************************************************************/

#include <iostream>
#include <vector>
#include <set>
using namespace std;

/*Given an array of integers and an integer k, find out whether there are two distinct indices i and j in the array such that nums[i] = nums[j] and the absolute difference between i and j is at most k.
*/




class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) 
    {
        set<int> cand;
        //如果i>k 那么开始删除前面的元素
        //如果插入失败， 返回true（有重复）
        for (int i = 0; i < nums.size(); i++)
        {
            if (i > k) 
                cand.erase(nums[i-k-1]);
            if (!cand.insert(nums[i]).second) 
                return true;
        }
        return false;
    }
};
