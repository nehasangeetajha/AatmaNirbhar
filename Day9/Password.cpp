//https://www.hackerearth.com/practice/algorithms/string-algorithm/basics-of-string-manipulation/practice-problems/algorithm/password-1/
/*
Danny has a possible list of passwords of Manny's facebook account. All passwords length is odd. But Danny knows that Manny is a big fan of palindromes. So, his password and reverse of his password both should be in the list.

You have to print the length of Manny's password and it's middle character.

Note : The solution will be unique.

INPUT
The first line of input contains the integer N, the number of possible passwords.
Each of the following N lines contains a single word, its length being an odd number greater than 2 and lesser than . All characters are lowercase letters of the English alphabet.

OUTPUT
The first and only line of output must contain the length of the correct password and its central letter.

CONSTRAINTS

SAMPLE INPUT 
4
abc
def
feg
cba
SAMPLE OUTPUT 
3 b
*/

/*
// Sample code to perform I/O:

cin >> name;                            // Reading input from STDIN
cout << "Hi, " << name << ".\n";        // Writing output to STDOUT

// Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail
*/

// Write your code here
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    string s[n];
    string res;
    unordered_map<string,bool>up;
    for(int i =0;i<n;i++)
    {
        cin>>s[i];
        up[s[i]] = true;
    }
    for(int i = 0;i<n;i++)
    {
        string str = s[i];
        reverse(str.begin(), str.end()); 
        if(up[str])
        {
            res = s[i];
            cout<<s[i].length()<<" ";
            cout<<str[s[i].length()/2];
            break;
        }
    }

    
}
