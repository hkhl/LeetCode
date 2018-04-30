/*************************************************************************
	> File Name: 167. Two Sum II - Input array is sorted.cpp
	> Author: wang
	> Mail: dhkhl235@gmail.com
	> Created Time: 2018年04月08日 星期日 01时18分17秒
 ************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

/*
 *Given an array of integers that is already sorted in ascending order, find two numbers such that they add up to a specific target number.

The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.

You may assume that each input would have exactly one solution and you may not use the same element twice.

Input: numbers={2, 7, 11, 15}, target=9
Output: index1=1, index2=2
 * */

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) 
    {
        int lo = 0;
        int hi = numbers.size()-1;
        while(numbers[lo] + numbers[hi] != target)
        {
            if(numbers[lo] + numbers[hi] < target)
                lo++;
            else 
                hi--;
        }
        return vector<int>({lo+1, hi+1});
    }
};