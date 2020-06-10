//https://leetcode.com/problems/permutation-in-string/
/*
Given two strings s1 and s2, write a function to return true if s2 contains the permutation of s1. In other words, one of the first string's permutations is the substring of the second string.

 

Example 1:

Input: s1 = "ab" s2 = "eidbaooo"
Output: True
Explanation: s2 contains one permutation of s1 ("ba").
Example 2:

Input:s1= "ab" s2 = "eidboaoo"
Output: False
 

Constraints:

The input strings only contain lower case letters.
The length of both given strings is in range [1, 10,000].
*/

//Sliding Window
class Solution {
public:
        
    bool checkInclusion(string s1, string s2) {
        if(s1.length()>s2.length())
            return false;
        
        vector<int>s1map(26,0);
        vector<int>s2map(26,0);

        for(int i = 0;i<s1.length();i++)
        {
            s1map[s1[i]-'a']++;
            s2map[s2[i]-'a']++;
        }
        
        bool flag = true;
        for(int i = 0;i<26;i++)
        {
            if(s1map[i]!=s2map[i])
            {
                flag =false;
                break;
            }
        }
        if(flag==true)
            return true;
        
        for(int i =s1.length();i<s2.length();i++)
        {
            s2map[s2[i-s1.length()]-'a']--;
            s2map[s2[i]-'a']++;
            flag=true;
            for(int i=0;i<26;i++){
                if(s1map[i]!=s2map[i]){
                    flag=false;
                    break;
                }
            }
            if(flag==true) return true;
        }
        return false;
    }
};
