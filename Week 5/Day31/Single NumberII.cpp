//https://leetcode.com/problems/single-number-ii/
/*
Given a non-empty array of integers, every element appears three times except for one, which appears exactly once. Find that single one.

Note:

Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

Example 1:

Input: [2,2,3,2]
Output: 3
Example 2:

Input: [0,1,0,1,0,1,99]
Output: 99
*/

//Bit Manipulation
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ones = 0,twos=0,threes=0;
        for(int i = 0;i<nums.size();i++)
        {
            twos |= ones & nums[i];
            ones^=nums[i];  
            threes  = ones & twos;
            
            ones &= ~threes;
            twos &= ~threes;
        }
        return ones;
    }
};
//Runtime: 12 ms, faster than 95.39% of C++ online submissions for Single Number II.
//Memory Usage: 9.7 MB, less than 49.83% of C++ online submissions for Single Number II.


//unordered_map
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(int i =0;i<nums.size();i++)
        {
            mp[nums[i]]++;
        }
        for(auto it:mp)
        {
            if(it.second==1)
                return it.first;
        }
        return 0;
    }
};

//Runtime: 20 ms
//Memory Usage: 10.4 MB
