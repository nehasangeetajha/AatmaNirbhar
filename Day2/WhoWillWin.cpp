//https://practice.geeksforgeeks.org/problems/who-will-win/0


#include<iostream>
using namespace std;

int binarySearch(int*arr,int low,int high,int k)
{
    if(high<low)
    return -1;
    int mid = low+(high-low)/2;
    if(arr[mid]==k)
    return 1;
    if(arr[mid]<k)
    return binarySearch(arr,mid+1,high,k);
    else
    return binarySearch(arr,0,mid-1,k);
}

int main()
 {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	    int n,k;
	    cin>>n>>k;
	    int arr[n];
	    for(int i = 0;i<n;i++)
	    {
	        cin>>arr[i];
	    }
	    cout<<binarySearch(arr,0,n-1,k)<<endl;
	    
	}
	return 0;
}
