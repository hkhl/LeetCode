/*************************************************************************
	> File Name: 414. Third Maximum Number.cpp
	> Author: wang
	> Mail: dhkhl235@gmail.com
	> Created Time: 2018年04月10日 星期二 11时46分56秒
 ************************************************************************/

#include <iostream>
#include <vector>
#include <set>
using namespace std;


class Solution {
public:
    int thirdMax(vector<int>& nums)
    {  
        set<int> top3;
        for (int num : nums) 
        {
            top3.insert(num);
            if (top3.size() > 3)
            {
                cout << *top3.begin() <<endl;
                top3.erase(top3.begin());
            }
        }
        
        return top3.size() == 3 ? *top3.begin() : *top3.rbegin();
    }
};
/*
class Solution {
public:
    int thirdMax(vector<int>& nums)
    {  
        //用set做好一些
        if(nums.size() == 1)
        {
            return nums[0];
        }
        else if(nums.size() == 2)
        {
            return max(nums[0], nums[1]);
        }
        long long a, b, c;   //最大 次大 第三大
        a = b = c = LONG_MIN;
        
        for(auto num : nums)
        {
            if(num > a)
            {
                c = b;
                b = a;
                a = num;
            }
            else if(num < a && num > b)
            {
                c = b;
                b = num;
            }
            else if(num < b && num > c)
            {
                c = num;
            }
        }
        cout <<  c << " " << b << " "  << a << endl;
        //if(c == b)
           // return a;
        return c == LONG_MIN ? a : c;
    }
};
*/
