//https://leetcode.com/problems/intersection-of-two-arrays/submissions/


class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,bool>up;
        vector<int>v;
        for(int i =0;i<num1.size();i++)
            up[nums1[i]]=true;
        for(int i = 0;i<nums2.size();i++)
        {
            if(up[nums2[i]]==true)
            {
                v.push_back(nums2[i]);
                up[nums2[i]]=false;
            }
        }
        return v;
    }
};
