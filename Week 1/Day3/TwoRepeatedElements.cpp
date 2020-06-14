//https://practice.geeksforgeeks.org/problems/two-repeated-elements/0


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
	    int *count = new int[sizeof(int)*(n+2)];
	    int arr[n+2];
	    //unordered_map<int,bool>up;
	    for(int i=0;i<n+2;i++)
	    {
	        cin>>arr[i];
	    }
	    for(int i = 0; i < n+2; i++)  
        {  
            if(count[arr[i]] == 1)  
                cout << arr[i] << " ";  
            else
                count[arr[i]]++;  
        } 
	    cout<<endl;
	}
	return 0;
}
