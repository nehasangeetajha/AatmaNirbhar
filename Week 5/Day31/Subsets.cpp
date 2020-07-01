//https://leetcode.com/problems/subsets/

/*
Given a set of distinct integers, nums, return all possible subsets (the power set).

Note: The solution set must not contain duplicate subsets.

Example:

Input: nums = [1,2,3]
Output:
[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]
*/

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        result.push_back(vector<int>());
        
        for(int num:nums)
        {
            vector<vector<int>>newSubsets;
            for(vector<int>curr : result)
            {
                curr.push_back(num);
                newSubsets.push_back(curr);
            }
            for(vector<int>curr : newSubsets)
            {
                result.push_back(curr);
            }
        }
        return result;
    }
};
