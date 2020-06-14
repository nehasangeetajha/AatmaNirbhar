//https://leetcode.com/problems/decrypt-string-from-alphabet-to-integer-mapping/
/*
Given a string s formed by digits ('0' - '9') and '#' . We want to map s to English lowercase characters as follows:

Characters ('a' to 'i') are represented by ('1' to '9') respectively.
Characters ('j' to 'z') are represented by ('10#' to '26#') respectively. 
Return the string formed after mapping.

It's guaranteed that a unique mapping will always exist.

 

Example 1:

Input: s = "10#11#12"
Output: "jkab"
Explanation: "j" -> "10#" , "k" -> "11#" , "a" -> "1" , "b" -> "2".
*/

class Solution {
public:
    string freqAlphabets(string s) {
        string b="";
        int i = 0;
        while(i<s.length()-2)
        {
            if(s[i+2]=='#')
            {
                int x = ((s[i]-'0')*10) + (s[i+1]-'0');
                b+=(x+96);
                i+=3;
            }
            else
            {
                b+=(s[i]-'0'+96);
                i++;
            }
        }
        while(i<s.length())
        {
            b+=(s[i]-'0'+96);
            i++;
        }
        return b;
    }
};
