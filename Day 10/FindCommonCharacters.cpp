//https://leetcode.com/problems/find-common-characters/

/*
Given an array A of strings made only from lowercase letters, return a list of all characters that show up in all strings within the list (including duplicates).  For example, if a character occurs 3 times in all strings but not 4 times, you need to include that character three times in the final answer.

You may return the answer in any order.

Example 1:

Input: ["bella","label","roller"]
Output: ["e","l","l"]
Example 2:

Input: ["cool","lock","cook"]
Output: ["c","o"]
 

Note:

1 <= A.length <= 100
1 <= A[i].length <= 100
A[i][j] is a lowercase letter
*/

class Solution {
public:
    vector<string> commonChars(vector<string>& A) {
       vector<int> up1(26,0);
        vector<int> up2(26,0);
        int n = A.size();
        for(auto ch : A[0]) {
            up1[ch-'a']++;
        }
        
        for(int i =1;i<n;i++)
        {
            for(auto ch : A[i]) {
                up2[ch-'a']++;
            }
            for(int k=0;k<26;k++) {
                up1[k] = min(up1[k], up2[k]);
                up2[k]=0;
            }
        }
        
        vector<string> v; 
        for(int i = 0; i<26;i++)
            if(up1[i]>0) {
                int count = up1[i];
                while(count--) {
                    char x = i+'a';
                    string ans;
                    ans = x;
                    v.push_back(ans);
                }     
            }
        return v;
    }
};
