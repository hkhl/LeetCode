/*************************************************************************
	> File Name: 169. Majority Element.cpp
	> Author: wang
	> Mail: dhkhl235@gmail.com
	> Created Time: 2018年04月08日 星期日 16时56分20秒
 ************************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
 *
Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.

You may assume that the array is non-empty and the majority element always exist in the array.

Credits:
Special thanks to @ts for adding this problem and creating all test cases.

 * */


 /* this is my idea*/
class Solution {
public:
    int majorityElement(vector<int>& nums) 
    {
        sort(nums.begin(), nums.end());
    
        return nums[nums.size()/2];
    }
};


/*this is master's idea O(n) */
public class Solutionw {
    public int majorityElement(int[] num) {

        int major=num[0], count = 1;
        for(int i=1; i<num.length;i++){
            if(count==0){
                count++;
                major=num[i];
            }else if(major==num[i]){
                count++;
            }else count--;
            
        }
        return major;
    }
}
