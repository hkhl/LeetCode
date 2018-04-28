/*************************************************************************
	> File Name: 697. Degree of an Array.cpp
	> Author: wang
	> Mail: dhkhl235@gmail.com
	> Created Time: 2018年04月28日 星期六 17时08分23秒
 ************************************************************************/

#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
using namespace std;
/*
Given a non-empty array of non-negative integers nums, the degree of this array is defined as the maximum frequency of any one of its elements.

Your task is to find the smallest possible length of a (contiguous) subarray of nums, that has the same degree as nums.

Example 1:
Input: [1, 2, 2, 3, 1]
Output: 2
Explanation: 
The input array has a degree of 2 because both elements 1 and 2 appear twice.
Of the subarrays that have the same degree:
[1, 2, 2, 3, 1], [1, 2, 2, 3], [2, 2, 3, 1], [1, 2, 2], [2, 2, 3], [2, 2]
The shortest length is 2. So return 2.
Example 2:
Input: [1,2,2,3,1,4,2]
Output: 6
Note:

nums.length will be between 1 and 50,000.
nums[i] will be an integer between 0 and 49,999.
*/



class Solution {
public:
    //找具有相同度（最大频率数）的最短子数组
    int findShortestSubArray(vector<int>& nums) 
    {
        //找到最长的度        
        //用map  将数组元素插入
        //找的过程中记录最长度的起始位置， 结束位置， 长度则是 end-start+1
        
        
        //以下解法的思想： 哈希表
        //将每个元素看作一个槽（键），相同的元素，不同的下标，放进同一个槽中（数组存放连接起来）（值）
        //也就是说 mp->first 是某个元素的值，  mp->second  是具有这个值的不同下标
        //将存放下标最多的槽进行计算
        //用最后一个元素（下标） 减去第一个下标， 再加1就是数组最大度的最短子数组
        
      
        unordered_map<int, vector<int>> mp;
        for(int i = 0; i < nums.size(); i++)
            mp[nums[i]].push_back(i);

        int degree = 0;
        for(auto it = mp.begin(); it != mp.end(); it++)
            degree = max(degree, (int)it->second.size());  //转换类型
        
        int shortest = nums.size();
        for(auto it = mp.begin(); it != mp.end(); it++)
        {
            if(degree == it->second.size())
            {
                shortest = min(shortest, it->second.back() - it->second[0] + 1); //.back（）  返回最后一个元素
            }
        }
        return shortest;
           
            
        
        /*
        //或者这样做：
     
        unordered_map<int, int> mp;
        for(int i = 0; i < nums.size(); i++)
            ++mp[nums[i]];          //nums[i] 是键， 当出现重复的建 对其值++操作
        
        int degree = 0;
        int bac = 0;
        int maxd = 0;
        for(const auto &m : mp)
        {
            bac = degree;
            degree = max(degree, m.second); //记录最大度
            if(bac != degree)
            {
                maxd = m.first;              //记录最大度对应的值   
                // *********有错误*************** 当有多个相同度， 则需要保存每个度的值， 对每个度都进行计算，计算最短路径
            }
        }
        
        cout<< "maxd = " << maxd << endl;
        //找到maxd第一次出现的和最后一次出现的下标 做差 加 1
    
        int first = -1;
        int last = -1;
        
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] == maxd && first == -1)
            {
                first = i;
            }
            if(nums[nums.size()-1-i] == maxd && last == -1)
            {
                cout << "i = " << i << endl;
                last = nums.size()-1-i;
            }
        }
        cout << first << " " << last << endl;
        
        return last-first+1;
        */
     
    }
};


优质解法？
        int findShortestSubArray(vector<int>& nums) {
        unordered_map<int, int> counter, first;
        int res = 0, degree = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (first.count(nums[i]) == 0) first[nums[i]] = i;
            if (++counter[nums[i]] > degree) {
                degree = counter[nums[i]];
                res = i - first[nums[i]] + 1;
            } else if (counter[nums[i]] == degree)
                res = min(res, i - first[nums[i]] + 1);
        }
        return res;




int main()
{
    
    vector<int> nums;
    nums.push_back(9);
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(3);
    nums.push_back(2);
    nums.push_back(2);


    unordered_map<int, int> mp;
    for(int i = 0; i < nums.size(); i++)
        ++mp[nums[i]];
    for(auto it = mp.begin(); it != mp.end(); it++)
    {
        cout << it->first << " " << it->second << endl;
    }
}


//统计单词个数
/*
    vector<string> str;
    str.push_back("asd");
    str.push_back("ads");
    str.push_back("qwe");
    str.push_back("asd");
    str.push_back("123");
    str.push_back("asd");

    unordered_map<string, int> mp;
    for(int i = 0; i < nums.size(); i++)
        ++mp[str[i]];

    for(auto it = mp.begin(); it != mp.end(); it++)
    {
        cout << it->first << " ";
        cout << it->second << endl;
    }
*/
