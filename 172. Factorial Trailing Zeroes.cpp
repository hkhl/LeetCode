/*
 *Given an integer n, return the number of trailing zeroes in n!.
 *
 *Example 1:
 *
 *Input: 3
 *Output: 0
 *Explanation: 3! = 6, no trailing zero.
 *Example 2:
 *
 *Input: 5
 *Output: 1
 *Explanation: 5! = 120, one trailing zero.
 */


class Solution {
public:
    //求阶乘， 再求0的个数
    /*不可取，  13！就已经溢出了， 无法计算
    int ZeroNum(int x)
    {
        int count = 0;
        while (x%10 == 0)
        {
            count++;
            x /= 10;
        }
        return count;
    }

    int trailingZeroes(int n)
    {
        int res = 1;
        while (n)
        {
            res *= n;
            n--;
        }
        cout << res<<endl;
        cout << INT_MAX<< endl;

        return ZeroNum(res);
    }
    */

    //实际本题类似于找规律， 不妨试着输入0-4的阶乘。 5-9的阶乘， 10-14的阶乘 ，可以发现其规律
    int trailingZeroes(int n)
    {
        int count = 0;
        while (n = n/5)
            count += n;
        return count;
    }

};
