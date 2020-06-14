//https://leetcode.com/problems/shortest-unsorted-continuous-subarray/

/*
Given an integer array, you need to find one continuous subarray that if you only sort this subarray in ascending order, then the whole array will be sorted in ascending order, too.

You need to find the shortest such subarray and output its length.

Example 1:
Input: [2, 6, 4, 8, 10, 9, 15]
Output: 5
Explanation: You need to sort [6, 4, 8, 10, 9] in ascending order to make the whole array sorted in ascending order.
Note:
Then length of the input array is in range [1, 10,000].
The input array may contain duplicates, so ascending order here means <=.

*/

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int low = nums[0],r=-1,high=nums[nums.size()-1],l=-1;
        for(int i =1;i<nums.size();i++)
        {
            if(nums[i]<low)
                r=i;
            low = max(low,nums[i]);
        }
        for(int i=nums.size()-2;i>=0;i--){
            if(nums[i]>high)
                l=i;            
            high=min(high,nums[i]);
        }
        return (r>l)? (r-l+1):0;
    }
};
