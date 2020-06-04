//https://leetcode.com/problems/find-lucky-integer-in-an-array/

class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int,int>up;
        for(int i =0;i<arr.size();i++)
            up[arr[i]]++;
        int res = -1;
        for (auto i : up)
        {
            if(i.first==i.second)
            {
                res = max(res,i.first);
            }
        }
        return res;
    }
};
