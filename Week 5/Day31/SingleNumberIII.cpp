//https://leetcode.com/problems/single-number-iii/
/*
Given an array of numbers nums, in which exactly two elements appear only once and all the other elements appear exactly twice. Find the two elements that appear only once.

Example:

Input:  [1,2,1,3,2,5]
Output: [3,5]
Note:

The order of the result is not important. So in the above example, [5, 3] is also correct.
Your algorithm should run in linear runtime complexity. Could you implement it using only constant space complexity?
*/

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int x = 0;
        //xor so that duplicates get cancelled
        for(int curr : nums)
            x^=curr;
        
        //find any bit in x that is set
        // if no bit is set mean no unique numbers
        int bit = -1;
        for(int i = 0;i<32;i++)
        {
            if(x&(1<<i))
            {
                bit=i;
                break;
            }
        }
        
        //a has bit set
        //b doesnt have bit set
        //xor all numbers with bit set
        //duplicates cancel
        //only a will remain , b will not be included
        
        int a = 0;
        for(int curr:nums)
        {
            if(curr &(1<<bit))
                a^=curr;
        }
        
        //we knw x = a^b so b = a^x
        int b = a^x;
        
        return {a,b};
    }
};
