/*
 *Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.
 *
 *Symbol       Value
 *I             1
 *V             5
 *X             10
 *L             50
 *C             100
 *D             500
 *M             1000
 *For example, two is written as II in Roman numeral, just two one's added together. Twelve is written as, XII, which is simply X + II. The number twenty seven is written as XXVII, which is XX + V + II.
 *
 *Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is not IIII. Instead, the number four is written as IV. Because the one is before the five we subtract it making four. The same principle applies to the number nine, which is written as IX. There are six instances where subtraction is used:
 *
 *I can be placed before V (5) and X (10) to make 4 and 9. 
 *X can be placed before L (50) and C (100) to make 40 and 90. 
 *C can be placed before D (500) and M (1000) to make 400 and 900.
 *Given a roman numeral, convert it to an integer. Input is guaranteed to be within the range from 1 to 3999.
 *
 *Example 1:
 *Input: "III"
 *Output: 3

 *Example 2:
 *Input: "IV"
 *Output: 4

 *Example 3:
 *Input: "IX"
 *Output: 9

 *Example 4:
 *Input: "LVIII"
 *Output: 58
 *Explanation: C = 100, L = 50, XXX = 30 and III = 3.

 *Example 5:
 *Input: "MCMXCIV"
 *Output: 1994
 *Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.
 */


class Solution {
public:
    //解析罗马数字， 给一个罗马数字， 解析成阿拉伯数字
    int romanToInt(string s) 
    {
        map<char, int> mp;
        mp['I'] = 1;
        mp['V'] = 5;
        mp['X'] = 10;
        mp['L'] = 50;
        mp['C'] = 100;
        mp['D'] = 500;
        mp['M'] = 1000;
        

        /*
        I can be placed before V (5) and X (10) to make 4 and 9. 
        X can be placed before L (50) and C (100) to make 40 and 90. 
        C can be placed before D (500) and M (1000) to make 400 and 900.
        */
        
        //如果V X L C 左边有I  减两个I
        
        int sum = 0;
        for (auto ch : s)
        {
            sum += mp[ch];
        }
        for (int i = 1; i < s.size(); i++)
        {
          if(s[i-1] == 'I' && (s[i] == 'V' || s[i] == 'X'))
                sum -= 2*mp['I'];
            if(s[i-1] == 'X' && (s[i] == 'L' || s[i] == 'C'))
                sum -= 2*mp['X'];
            if(s[i-1] == 'C' && (s[i] == 'D' || s[i] == 'M'))
                sum -= 2*mp['C'];
        }

        //另一种方法 抓住问题的本质， 只要左边小于右边， 就减去左边的数字
        sum = 0;
        for (int i = 1; i < s.size(); i++)
        {
            if (mp[s[i-1]] >= mp[s[i]])
                sum += mp[s[i-1]];
            else
                sum -= mp[s[i-1]];
        }
        return sum+mp[s[s.size()-1]];
    }
};

