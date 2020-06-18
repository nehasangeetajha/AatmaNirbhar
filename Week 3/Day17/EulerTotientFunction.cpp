//https://www.hackerearth.com/practice/math/number-theory/totient-function/tutorial/
/*
Euler Totient Function
In number theory, the totient  of a positive integer N is defined as the number of positive integers less than or equal to N that are co-prime to N.

Given an integer N. Compute the value of the totient .

Input:
First and the only line of input contains single integer N.

Output:
Print the phi(n) in a single line.


*/

#include<bits/stdc++.h>
using namespace std;

int phi(int n)
{
    float result = n;
    for(int p =2;p*p<=n;p++)
    {
        if(n%p==0)
        {
            while(n%p==0)
            n/=p;
            result = result * (1.0 - (1.0 / (float)p));
        }
    }
    if(n>1)
    {
        result = result * (1.0 - (1.0 / (float)n));
    }
    return result;
}

int main()
{
    int n;
    cin>>n;
    cout<<phi(n);

}
