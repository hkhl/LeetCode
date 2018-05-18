
/*
 *Given a positive integer, return its corresponding column title as appear in an Excel sheet.
 *
 *For example:
 *
 *    1 -> A
 *    2 -> B
 *    3 -> C
 *    ...
 *    26 -> Z
 *    27 -> AA
 *    28 -> AB
 *    ...
 *Example 1:
 *
 *Input: 1
 *Output: "A"
 *Example 2:
 *
 *Input: 28
 *Output: "AB"
 *Example 3:
 *
 *Input: 701
 *Output: "ZY"
 */

class Solution {
public:
    //26进制
    string convertToTitle(int n)
    {
        string str = "";
        char ch;
        while(n)
        {
            n--;
            ch = n%26 + 'A';   //0-25 + 'A'  == 'A' - 'Z'
            str += ch;
            n = n/26;
        }
        reverse(str.begin(), str.end());
        return str;
    }
};
