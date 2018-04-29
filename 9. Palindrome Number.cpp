
/*
 *Determine whether an integer is a palindrome. An integer is a palindrome when it reads the same backward as forward.
 *
 *Example 1:
 *
 *Input: 121
 *Output: true
 *Example 2:
 *
 *Input: -121
 *Output: false
 *Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.
 *Example 3:
 *
 *Input: 10
 *Output: false
 *Explanation: Reads 01 from right to left. Therefore it is not a palindrome.
 */

//回文数



class Solution {
public:
    bool isPalindrome(int x)
    {
        if(x < 0)
            return false;
        else
        {
            //这里将数字变为字符， 然后通过equal函数检测是否回文
            stringstream  ss;
            ss << x;
            string str = ss.str();
            return equal(str.begin(), str.end(), str.rbegin());
        }
        //另一种方法就是数字反转 判断与原数字是否相等
    }
};
