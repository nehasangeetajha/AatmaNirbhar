//https://leetcode.com/problems/longest-common-prefix/
/*
Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

Example 1:

Input: ["flower","flow","flight"]
Output: "fl"
Example 2:

Input: ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.
Note:

All given inputs are in lowercase letters a-z.
*/


class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size()==0)
            return "";
        for(int i =0;i<strs[0].size();i++)
        {
            for(int j = 1;j<strs.size();j++)
            {
                if(i>=strs[j].length() || strs[j][i] != strs[j-1][i])
                    return strs[0].substr(0,i);
            }
        }
        return strs[0];
    }
};
