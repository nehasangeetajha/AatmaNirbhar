//https://leetcode.com/problems/spiral-matrix-ii/

/*
Given a positive integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.

Example:

Input: 3
Output:
[
 [ 1, 2, 3 ],
 [ 8, 9, 4 ],
 [ 7, 6, 5 ]
]
*/

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n,vector<int>(n));
        int r1 = 0;
        int r2 = matrix.size()-1;
        int c1 = 0;
        int c2 = matrix[0].size()-1;
        int num =1;
        
        while(r1<=r2 && c1<=c2)
        {
            for(int c=c1;c<=c2;c++)
            {
                matrix[r1][c]=num;
                num++;
            }
            for(int r=r1+1;r<=r2;r++)
            {
                matrix[r][c2]=num;
                num++;
            }
            if(r1<r2 && c1<c2)
            {
                for(int c=c2-1;c>=c1+1;c--)
                {
                    matrix[r2][c]=num;
                    num++;
                }
                for(int r=r2;r>=r1+1;r--)
                {
                    matrix[r][c1]=num;
                    num++;
                }
            
            }
            r1++;
            r2--;
            c1++;
            c2--;
        }
        return matrix;
    }
};
