//https://leetcode.com/problems/backspace-string-compare/
/*
Given two strings S and T, return if they are equal when both are typed into empty text editors. # means a backspace character.

Note that after backspacing an empty text, the text will continue empty.

Example 1:

Input: S = "ab#c", T = "ad#c"
Output: true
Explanation: Both S and T become "ac".
Example 2:

Input: S = "ab##", T = "c#d#"
Output: true
Explanation: Both S and T become "".
Example 3:

Input: S = "a##c", T = "#a#c"
Output: true
Explanation: Both S and T become "c".
Example 4:

Input: S = "a#c", T = "b"
Output: false
Explanation: S becomes "c" while T becomes "b".
Note:

1 <= S.length <= 200
1 <= T.length <= 200
S and T only contain lowercase letters and '#' characters.
Follow up:

Can you solve it in O(N) time and O(1) space?
*/

class Solution {
public:
    bool backspaceCompare(string S, string T) {
        stack<char>ss;
        stack<char>tt;
        
        for(int i = 0;i<S.size();i++)
        {
            if(ss.empty()&&S[i]!='#')
                ss.push(S[i]);
            else if(!ss.empty()&&S[i]=='#')
                ss.pop();
            else if(S[i]!='#')
                ss.push(S[i]);
            
        }
        
        for(int i = 0;i<T.size();i++)
        {
            if(tt.empty()&&T[i]!='#')
                tt.push(T[i]);
            else if(!tt.empty()&&T[i]=='#')
                tt.pop();
            else if(T[i]!='#')
                tt.push(T[i]);
            
        }
        
        string s1="",t1="";
        while(!ss.empty())
        {
            s1+=string(1,ss.top());
            ss.pop();
        }
        while(!tt.empty())
        {
            t1+=string(1,tt.top());
            tt.pop();
        }
        return s1==t1;
        
    }
};
