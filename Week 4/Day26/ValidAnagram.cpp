//https://leetcode.com/problems/valid-anagram/
/*
Given two strings s and t , write a function to determine if t is an anagram of s.

Example 1:

Input: s = "anagram", t = "nagaram"
Output: true
Example 2:

Input: s = "rat", t = "car"
Output: false
Note:
You may assume the string contains only lowercase alphabets.

Follow up:
What if the inputs contain unicode characters? How would you adapt your solution to such case?
*/

class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int>map1,map2;
        for(int i=0;i<s.size();i++)
            map1[s[i]]++;
        for(int i=0;i<t.size();i++)
        {
             if(!map1[t[i]])
                return false;
            map2[t[i]]++;
        }
        return map1==map2;
    }
};
