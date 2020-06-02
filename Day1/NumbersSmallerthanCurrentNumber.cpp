//https://leetcode.com/problems/how-many-numbers-are-smaller-than-the-current-number/

class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> copy = nums;
        sort(copy.begin(), copy.end());
        vector<int> v;
        auto it = copy.begin();
        
        for(auto i : nums)
        {
            it = lower_bound(copy.begin(), copy.end(), i);
            v.push_back(it-copy.begin());
        }
        return v;
    }
};
