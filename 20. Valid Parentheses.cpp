/*
Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Note that an empty string is also considered valid.

Example 1:

Input: "()"
Output: true
Example 2:

Input: "()[]{}"
Output: true
Example 3:

Input: "(]"
Output: false
Example 4:

Input: "([)]"
Output: false
Example 5:

Input: "{[]}"
Output: true
*/
class Solution {
public:
    bool isValid(string s)
    {
        stack<char> st;

        for(auto ch : s)
        {
            if(ch == '(' || ch == '[' || ch == '{')
                st.push(ch);
            else
            {
                if(st.empty())
                    return false;
                else
                {
                    if(ch == ')' && st.top() == '(' || ch == ']' && st.top() == '[' ||  ch == '}' && st.top() == '{')
                        st.pop();
                    else
                        return false;
                }
            }
        }
        return st.empty();
    }
};

