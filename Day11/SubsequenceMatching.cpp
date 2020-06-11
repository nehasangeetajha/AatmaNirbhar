//https://practice.geeksforgeeks.org/problems/subsequence-matching/0
/*
Given an all upper case string, check if it is a combination of one or more of the following:
1) R
2) RY
3) RYY

Input:

First line contains an integer T denoting the number of test cases. Each of the following T lines will contain an upper case string.

Output:

Print YES if the sequence is correct, NO if not correct.

Constraints:  

1<=T<=100
1<=10^5<= Size of String

Example: 

Input:

3
RY
RWR
RRYY

Output:

YES
NO
YES
*/

#include<bits/stdc++.h>
using namespace std;

bool search(string s)
{
    int i,n=s.length(),count=0;
    if(s[0]=='Y')
    return false;
    for(i=0;i<n;i++)
    {
        if(s[i]=='R'||s[i]=='Y')
        {
            if(s[i]=='Y')
            {
                count++;
                if(count>2)
                return false;
            }
            else
            count=0;
        }
        else
        return false;
    }
    return true;
}

int main()
 {
	//code
	int t;
	cin>>t;
	vector<string>v = {"R","RY","RYY"};
	while(t--)
	{
	    string s;
	    cin>>s;
	    bool flag = search(s);
	    if(flag)
	    cout<<"YES"<<endl;
	    else
	    cout<<"NO"<<endl;
	}
	return 0;
}
