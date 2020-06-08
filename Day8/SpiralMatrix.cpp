//https://leetcode.com/problems/spiral-matrix/
/*
Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.

Example 1:

Input:
[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
Output: [1,2,3,6,9,8,7,4,5]
Example 2:

Input:
[
  [1, 2, 3, 4],
  [5, 6, 7, 8],
  [9,10,11,12]
]
Output: [1,2,3,4,8,12,11,10,9,5,6,7]
*/

class Solution {
public:
    
    void helper(vector<vector<int>>&m,int sx,int sy,int h, int w,vector<int>&res)
    {
        if(h<=0 || w<=0)
            return;
        if(h ==1){
            for(int i=sx;i<sx+w;i++)
                res.push_back(m[sy][i]);
            return;
        }
        if(w==1){
            for(int i=sy;i<sy+h;i++)
                res.push_back(m[i][sx]);
            return;
        }
        
        // top row
        for (int i = sx; i < sx + w; i++)
            res.push_back(m[sy][i]);
        res.pop_back();
        // right column
        for (int i = sy; i < sy + h; i++)
            res.push_back(m[i][sx + w - 1]);
        res.pop_back();
        // bottow row
        for (int i = sx + w - 1; i >= sx; i--)
            res.push_back(m[sy + h - 1][i]);
        res.pop_back();
        // left column
        for (int i = sy + h - 1; i >= sy; i--)
            res.push_back(m[i][sx]);
        res.pop_back();

        helper(m, sx + 1, sy + 1, h - 2, w - 2, res);
        
    }
    
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int>res;
        if(matrix.empty())
            return res;
        
        int r = matrix.size();
        int c = matrix[0].size();
        
        helper(matrix,0,0,r,c,res);
        return res;
    }
};
