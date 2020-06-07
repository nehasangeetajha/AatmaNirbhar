/*
given an array example ar= { 1,2,3,4,5} of size n
and q set of queries and x for each q. Queries can be of two types
1 - left rotate array by x times
2 - right rotate array by x times
return the array after perfroming q set of queries

Sample case 1:
n = 5
ar = { 4,7,9,0,4}
q=5
1 3
2 8
1 9
2 2
1 2
Ans : {4,4,7,9,0}
*/

#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) 
{ 
    if (b == 0) 
        return a; 
  
    else
        return gcd(b, a % b); 
}

void leftrotate(vector<int>&arr,int d,int n)
{
	d = d % n; 
    int g_c_d = gcd(d, n); 
    for (int i = 0; i < g_c_d; i++) { 
        int temp = arr[i]; 
        int j = i; 
  
        while (1) { 
            int k = j + d; 
            if (k >= n) 
                k = k - n; 
  
            if (k == i) 
                break; 
  
            arr[j] = arr[k]; 
            j = k; 
        } 
        arr[j] = temp; 
    } 
}

void reverseArray(vector<int>&arr, int start, 
                            int end) 
{ 
    while (start < end) 
    { 
        std::swap(arr[start], arr[end]); 
        start++; 
        end--; 
    } 
}

void rightrotate(vector<int>&arr,int d,int n)
{
	reverseArray(arr, 0, n-1); 
    reverseArray(arr, 0, d-1); 
    reverseArray(arr, d, n-1); 
}

int main() {
	// your code goes here
	int n;
	cin>>n;
	vector<int>arr;
	for(int i = 0;i<n;i++)
	cin>>arr[i];
	
	int q;
	cin>>q;
	pair<int,int>queries[q];
	for(int i = 0;i<q;i++)
	{
		cin>>queries[i].first>>queries[i].second;
	}
	for(int i = 0;i<q;i++)
	{
		if(queries[i].first==1)
		leftrotate(arr,queries[i].second,n);
		else if(queries[i].first==2)
		rightrotate(arr,queries[i].second,n);
	}
	for(int i =0;i<n;i++)
	cout<<arr[i]<<" ";
	return 0;
}
