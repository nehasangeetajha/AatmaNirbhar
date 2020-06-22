//https://leetcode.com/problems/add-strings/
/*
Given two non-negative integers num1 and num2 represented as string, return the sum of num1 and num2.

Note:

The length of both num1 and num2 is < 5100.
Both num1 and num2 contains only digits 0-9.
Both num1 and num2 does not contain any leading zero.
You must not use any built-in BigInteger library or convert the inputs to integer directly.
*/

class Solution {
public:
    string addStrings(string num1, string num2) {
        int n1, n2, carry = 0, sum, i = num1.length() -1, j = num2.length() -1;
        string s;
        while(i >= 0 || j >= 0 )
        {
            n1 = i >= 0? num1[i--] - 48: 0; // convert ascii to number 
            n2 = j >= 0? num2[j--] - 48: 0;  // convert ascii to number           
            sum = n1 + n2 + carry;
            carry = sum /10;
            s += (char) sum %10 + 48;   // convert number back to ascii then character          
        }       
        if(carry != 0)s += "1";
        reverse(s.begin(), s.end());
        return s;
    }
};
