//https://leetcode.com/problems/sort-characters-by-frequency/
/*
Given a string, sort it in decreasing order based on the frequency of characters.

Example 1:

Input:
"tree"

Output:
"eert"

Explanation:
'e' appears twice while 'r' and 't' both appear once.
So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.
Example 2:

Input:
"cccaaa"

Output:
"cccaaa"

Explanation:
Both 'c' and 'a' appear three times, so "aaaccc" is also a valid answer.
Note that "cacaca" is incorrect, as the same characters must be together.
Example 3:

Input:
"Aabb"

Output:
"bbAa"

Explanation:
"bbaA" is also a valid answer, but "Aabb" is incorrect.
Note that 'A' and 'a' are treated as two different characters.
*/

class Solution {
public:
    string frequencySort(string s) {
        map<char, int> mymap; 
        for(int i = 0;i<s.size();i++)
            mymap[s[i]]++;
        
        string res;
        
        vector<pair<char,int>>v(mymap.begin(),mymap.end());
        sort(v.begin(),v.end(),[](pair<char, int> p1, pair<char, int> p2){ return p1.second >= p2.second;});
        int freq;
        for(int i=0;i<v.size();i++)
        {
            while(v[i].second)
            {
                res+=v[i].first;
                v[i].second--;
            }
        }
        return res;
    }
};
