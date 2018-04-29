/*
 *Given a 32-bit signed integer, reverse digits of an integer.
 *
 *Example 1:
 *
 *Input: 123
 *Output: 321
 *Example 2:
 *
 *Input: -123
 *Output: -321
 *Example 3:
 *
 *Input: 120
 *Output: 21
 *Note:
 *Assume we are dealing with an environment which could only store integers within the 32-bit signed integer range: [−231,  231 − 1]. For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.
 */


pclass Solution {
public:
    //唯一问题是逆转后数字溢出的问题
    //符号 0什么的都不需要管， 自动帮你做好
    //符号看（%左侧操作数）

    int reverse(int x)
    {
        int res = 0;
        int temp = 0;
        while(x)
        {
            temp = res;
            res *= 10;
            res += x%10;
            if((res - x%10) / 10 != temp)
                return 0;
            x /= 10;
        }
        return res;
    }
};

