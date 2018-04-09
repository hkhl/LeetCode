/*************************************************************************
	> File Name: 217. Contains Duplicate.cpp
	> Author: wang
	> Mail: dhkhl235@gmail.com
	> Created Time: 2018年04月09日 星期一 19时27分39秒
 ************************************************************************/

#include <iostream>
#include <vector>
#include <set>
using namespace std;
/*
Given an array of integers, find if the array contains any duplicates. Your function should return true if any value appears at least twice in the array, and it should return false if every element is distinct.
*/

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) 
    {
        //排序 比较前后两个是否有重复 O（NlgN）
        //O(n^2) 双重循环比较
        
        //set去重
        return nums.size() > set<int>(nums.begin(), nums.end()).size();        
    }
};
