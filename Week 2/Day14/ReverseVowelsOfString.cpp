//https://leetcode.com/problems/reverse-vowels-of-a-string/

/*
Write a function that takes a string as input and reverse only the vowels of a string.

Example 1:

Input: "hello"
Output: "holle"
Example 2:

Input: "leetcode"
Output: "leotcede"
Note:
The vowels does not include the letter "y".
*/

class Solution {
public:
    bool isVowel(char c) {
        c = tolower(c);
        return (c == 'a') || (c == 'e') ||(c == 'i') ||(c == 'o') ||(c == 'u');
    }
    string reverseVowels(string s) {
        int  i =0,j=s.size()-1;
        while(i<j)
        {
            while(i<s.size() && !isVowel(s[i]))
                i++;
            while(j && !isVowel(s[j]))
                j--;
            if(i<j)
                swap(s[i++],s[j--]);
        }
        return s;
    }
};
