
/*
 *Given an arbitrary ransom note string and another string containing letters from all the magazines, write a function that will return true if the ransom note can be constructed from the magazines ; otherwise, it will return false.
 *
 *Each letter in the magazine string can only be used once in your ransom note.
 *
 *Note:
 *You may assume that both strings contain only lowercase letters.
 *
 *canConstruct("a", "b") -> false
 *canConstruct("aa", "ab") -> false
 *canConstruct("aa", "aab") -> true
 */


class Solution {
public:
    /*
    给定一个赎金信 (ransom) 字符串和一个杂志(magazine)字符串，判断第一个字符串ransom能不能由第二个字符串magazines里面的字符构成。如果可以构成，返回 true ；否则返回 false。
    */
    //strchr 一个字符的找， 找到两边都删除         较差
    //hash
    bool canConstruct(string ransomNote, string magazine)
    {/*
        int *alphabet = new int[26]();       //()初始化 0
        for (int i = 0; i < magazine.length(); i++)
        {
            alphabet[magazine[i] - 'a']++;
        }

        for (int i = 0; i < ransomNote.length(); i++)
        {
            alphabet[ransomNote[i] - 'a']--;
            if (alphabet[ransomNote[i] - 'a'] < 0)
            {
                delete[] alphabet;
                return false;
            }
        }
        delete[] alphabet;
        return true;
        */

        //map

        unordered_map<char, int> alphabet;
        for (int i = 0; i < magazine.length(); i++)
        {
            alphabet[magazine[i]]++;
        }

        for (int i = 0; i < ransomNote.length(); i++)
        {
            alphabet[ransomNote[i]]--;
            if (alphabet[ransomNote[i]] < 0)
                return false;
        }
        return true;
    }
};
