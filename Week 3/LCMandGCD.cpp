//https://practice.geeksforgeeks.org/problems/lcm-and-gcd/0
/*
Given two numbers A and B. The task is to find out their LCM and GCD.

Input:
The first line of input contains an integer T denoting the number of testcases. T testcases follow. In each test cases, there are two numbers A and B separated by space.

Output:
For each testcase in a new line, print LCM and GCD separated by space.

Constraints:
1 <= T <= 104
1 <= A <= 108
1 <= B <= 108

Example:
Input:
2
5 10
14 8

Output:
10 5
56 2

Explanation:
Testcase 1: LCM and GCD of given numbers 5 and 10 are: 10 and 5.
*/

#include<bits/stdc++.h>
using namespace std;
int main()
 {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	    long long a,b;
	    cin>>a>>b;
	    long long gcd=a,lcm,temp=b;
	    while(gcd!=temp)
	    {
	        if(gcd>temp)
	        gcd-=temp;
	        else
	        temp-=gcd;
	    }
	    lcm = (a*b)/gcd;
	    cout<<lcm<<" "<<gcd<<endl;
	}
	return 0;
}
