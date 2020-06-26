//https://practice.geeksforgeeks.org/problems/largest-subarray-of-0s-and-1s/1
/*
Given an array of 0s and 1s. Find the length of the largest subarray with equal number of 0s and 1s.

Input:
The first line of the input is T denoting the number of test cases. Then T test cases follow . Each test case contains two lines. The first line of each test case is a number N denoting the size of the array and in the next line are N space separated values of A [].

Output:
For each test case output in a new line the max length of the subarray.

Your Task:
You don't need to read input or print anything. Your task is to complete the function maxLen() which takes the array arr[] and the size of the array as inputs and returns the length of the largest subarray with equal number of 0s and 1s.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(N).

Constraints:
1 <= T <= 100
1 <= N <= 105
0 <= A[] <= 1

Example:
Input
2
4
0 1 0 1
5
0 0 1 0 0

Output
4
2

Explanation:
Testacase 1: The array from index [0...3] contains equal number of 0's and 1's. Thus maximum length of subarray having equal number of 0's and 1's is 4.
*/

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

int maxLen(int arr[], int n);

int main()
{
    // your code goes here
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        cout << maxLen(a, n) << endl;
    }
    return 0;
}// } Driver Code Ends


/*You are required to complete this method*/

// arr[] : the input array containing 0s and 1s
// N : size of the input array

// return the maximum length of the subarray
// with equal 0s and 1s
int maxLen(int arr[], int N)
{
    // Your code here
    for(int i =0;i<N;i++)
    if(arr[i]==0)
        arr[i]=-1;
        
    int sum =0,ans=0;
    unordered_map<int,int> m;
    for(int i = 0;i<N;i++)
    {
        sum += arr[i];
        if(sum == 0)
            ans = max(ans,i+1);
            
        if(m.find(sum) != m.end())
        {
            ans = max(ans,i-m[sum]);
        }
        else
            m[sum] = i;
    }
    
    if(ans == INT_MIN)
        return 0;
    return ans;
}
