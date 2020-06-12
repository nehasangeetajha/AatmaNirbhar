//https://leetcode.com/problems/longest-palindromic-substring/
/*
Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.

Example 1:

Input: "babad"
Output: "bab"
Note: "aba" is also a valid answer.
Example 2:

Input: "cbbd"
Output: "bb"
*/

//Manacher's Algorithm
class Solution {
public:
    string longestPalindrome(string s) {
        if(s.empty())
            return "";
        string prep = "|";
        for(auto ch:s){prep+=ch;prep+="|";};
        const int sizep = prep.size();
        vector<int>dp(sizep,0);
        int center = 0,cur=0;
        for(int i=0;i<sizep;i++)
        {
            int mirror = center-(i-center);
            dp[i] = cur<=i? 0 : min(cur-i,dp[mirror]);
            int start = i-dp[i],end = i+dp[i];
            while(start>0 && end<=sizep&&prep[start-1]==prep[end+1])
            {
                --start;
                ++end;
                ++dp[i];
            }
            if(i+dp[i]>cur)
            {
                cur = i+dp[i];
                center = i;
            }
        }
        center = max_element(dp.begin(), dp.end()) - dp.begin();
    return s.substr((center - dp[center])/2, dp[center]);
    }
};
