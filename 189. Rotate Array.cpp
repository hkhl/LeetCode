/*************************************************************************
	> File Name: 189. Rotate Array.cpp
	> Author: wang
	> Mail: dhkhl235@gmail.com
	> Created Time: 2018年04月08日 星期日 17时00分42秒
 ************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) 
    {
        vector<int> numbac;
        for(int i = 0; i < nums.size(); i++)
        {
            numbac.push_back(nums[i]);
        }
        
        for(int i = 0; i < nums.size(); i++)
        {
            nums[(i+k)%nums.size()] = numbac[i];
        }
    }
};

