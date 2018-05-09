
/*
 *Given two binary strings, return their sum (also a binary string).
 *
 *The input strings are both non-empty and contains only characters 1 or 0.
 *
 *Example 1:
 *
 *Input: a = "11", b = "1"
 *Output: "100"
 *Example 2:
 *
 *Input: a = "1010", b = "1011"
 *Output: "10101"
 */

//大牛的答案
string addBinary(string a, string b)
{
    string s = "";

    int c = 0, i = a.size() - 1, j = b.size() - 1;
    while(i >= 0 || j >= 0 || c == 1)
    {
        c += i >= 0 ? a[i --] - '0' : 0;
        c += j >= 0 ? b[j --] - '0' : 0;
        s = char(c % 2 + '0') + s;
        c /= 2;
    }

    return s;
}

//自己的答案
class Solution {
public:
    //题意： 字符串二进制加减法
    string addBinary(string a, string b)
    {
        string rst;

        //rst 填充 反转
        int i = a.length()-1;
        int j = b.length()-1;
        int jinwei = 0;
        while (i >= 0 && j >= 0)
        {
            if(a[i] == b[j])
            {
                if(jinwei == 1)
                    rst += "1";
                else
                    rst += "0";

                if(a[i] == '1')
                    jinwei = 1;
                else
                    jinwei = 0;
            }
            else
            {
                if(jinwei == 1)
                    rst += "0";
                else
                    rst += "1";
            }
            i--;
            j--;
        }
        while(i >= 0)
        {
            if(jinwei == 1)
            {
                if(a[i] == '0')
                {
                    rst += "1";
                    jinwei = 0;
                }
                else
                {
                    rst += "0";
                    jinwei = 1;
                }
            }
            else
            {
                if(a[i] == '1')
                    rst += "1";
                else
                    rst += "0";
            }
            i--;
        }

        while(j >= 0)
        {
            if(jinwei == 1)
            {
                if(b[j] == '0')
                {
                    rst += "1";
                    jinwei = 0;
                }
                else
                {
                    rst += "0";
                    jinwei = 1;
                }
            }
            else
            {
                if(b[j] == '1')
                    rst += "1";
                else
                    rst += "0";
            }
            j--;
        }

        if(jinwei == 1)
        {
            rst += "1";
        }
        reverse(rst.begin(), rst.end());

        return rst;
    }
};
