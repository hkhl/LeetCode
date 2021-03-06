
/*
Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

Example 1:

Input: ["flower","flow","flight"]
Output: "fl"
Example 2:

Input: ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.
Note:

All given inputs are in lowercase letters a-z.
*/



class Solution {
    //找前缀
public:
    string longestCommonPrefix(vector<string>& strs)
    {
        string prestr = "";

        for (int idx = 0; strs.size() > 0 && idx < strs[0].size() ; prestr += strs[0][idx], idx++)
        {
            for(int i = 1; i < strs.size(); i++)
            {
                if(strs[i-1][idx] != strs[i][idx])
                    return prestr;
            }

        }
        return prestr;
    }
};
