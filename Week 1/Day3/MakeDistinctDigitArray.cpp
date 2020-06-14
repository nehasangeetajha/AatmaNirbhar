//https://practice.geeksforgeeks.org/problems/make-a-distinct-digit-array/0


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
	    for(int i =0;i<n;i++)
	    {
	        cin>>arr[i];
	    }
	    
	    int digits[10] = {0};
	    for(int i = 0;i<n;i++)
	    {
	        while(arr[i]>0)
	        {
	            int temp = arr[i]%10;
	            arr[i] = arr[i]/10;
	            digits[temp]++;
	        }
	    }
	    vector<int>res;
	    for(int i=0;i<10;i++)
	    {
	        if(digits[i]!=0)
	        res.push_back(i);
	    }
	    sort(res.begin(),res.end());
	    for(int i = 0;i<res.size();i++)
	    cout<<res[i]<<" ";
	    
	    cout<<endl;
	    
	}
	return 0;
}
