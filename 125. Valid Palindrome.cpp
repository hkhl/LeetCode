
/*
 *Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.
 *
 *Note: For the purpose of this problem, we define empty string as valid palindrome.
 *
 *Example 1:
 *
 *Input: "A man, a plan, a canal: Panama"
 *Output: true
 *Example 2:
 *
 *Input: "race a car"
 *Output: false
 */

class Solution {
public:
    //考虑是否是回文。只看字母或者数字
    //对字母数字进行筛选， 其余过滤掉，再判断回文

    bool isPalindrome(string s)
    {
        string str = "";

        for (auto ch : s)
            if (ch >= 'a' && ch <= 'z' || ch >= 'A' && ch <= 'Z' || ch >= '0' && ch <= '9')
            {
                ch = tolower(ch);
                str += ch;
            }

        cout << str << endl;
        return equal(str.begin(), str.end(), str.rbegin());
    }
};
