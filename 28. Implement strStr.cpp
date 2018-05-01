#include <iostream>
#include <iostream>


/*
 *Implement strStr().
 *
 *Return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.
 *
 *Example 1:
 *
 *Input: haystack = "hello", needle = "ll"
 *Output: 2
 *Example 2:
 *
 *Input: haystack = "aaaaa", needle = "bba"
 *Output: -1
 *Clarification:
 *
 *What should we return when needle is an empty string? This is a great question to ask during an interview.
 *
 *For the purpose of this problem, we will return 0 when needle is an empty string. This is consistent to C's strstr() and Java's indexOf().
 */

class Solution {
public:
    int strStr(string haystack, string needle)
    {
       /*
        string::size_type position;
        position = haystack.find(needle);
        if (position == haystack.npos)
        {
            return -1;
        }
        return position;
    */
        if (needle.empty())
            return 0;
        int i, j = 0;
        for(i = 0; i < haystack.size(); i++)
        {
            if(haystack[i] == needle[j])
            {
                j++;
            }
            else
            {
                i = i-j;
                j = 0;
            }
            if(j == needle.size())
            {
                return i - j + 1;
            }
        }
        return -1;
    }
};
