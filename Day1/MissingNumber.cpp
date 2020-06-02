//https://practice.geeksforgeeks.org/problems/missing-number/0

#include<bits/stdc++.h>
using namespace std;
int main()
 {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int arr[n];
	    int sumorg = 0,sum=0;
	    for(int i = 0;i<n-1;i++)
	    {
	        cin>>arr[i];
	        sumorg+=i;
	        sum+=arr[i];
	        //cout<<sumorg<<"-";
	        //cout<<sum<<endl;
	    }
	    sumorg+=n-1;
	    sumorg+=n;
	    cout<<sumorg-sum<<endl;
	}
	return 0;
}
