//https://leetcode.com/problems/valid-parentheses/
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
    bool isValid(string s) {
        stack<char>st;
        for(int i =0;i<s.size();i++)
        {
            if(s[i]=='(' || s[i]=='{' || s[i] == '[')
            {
                st.push(s[i]);
                continue;
            }
            if(st.empty())
                return false;
            
            char top = st.top();
            if(s[i]=='}' && top=='{')
                st.pop();
            else if(s[i]==']' && top=='[')
                st.pop();
            else if(s[i]==')' && top=='(')
                st.pop();
            else return false;
        }
        return(st.empty());
    }
};

/*
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Valid Parentheses.
Memory Usage: 6.2 MB, less than 74.26% of C++ online submissions for Valid Parentheses.
*/
