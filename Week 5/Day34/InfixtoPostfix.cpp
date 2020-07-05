//https://practice.geeksforgeeks.org/problems/infix-to-postfix/0
/*
Given an infix expression in the form of a string str. Conver this infix expression to postfix expression.

Infix expression: The expression of the form a op b. When an operator is in-between every pair of operands.
Postfix expression: The expression of the form a b op. When an operator is followed for every pair of operands.
Input:
The first line of input contains an integer T denoting the number of test cases. The next T lines contains an infix expression.The expression contains all characters and ^,*,/,+,-.

Output:
For each testcase, in a new line, output the infix expression to postfix expression.

Constraints:
1 <= T <= 100
1 <= length of str <= 103

Example:
Input:
2
a+b*(c^d-e)^(f+g*h)-i
A*(B+C)/D

Output:
abcd^e-fgh*+^*+i-
ABC+*D/
*/

#include<bits/stdc++.h>
using namespace std;
int prec(char c) 
{ 
    if(c == '^') 
    return 3; 
    else if(c == '*' || c == '/') 
    return 2; 
    else if(c == '+' || c == '-') 
    return 1; 
    else
    return -1; 
} 
int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
      string s;
      cin>>s;
      stack<char>st;
      char c;
      int i;
      for(i=0;i<s.size();i++)
      {
          if((s[i]>='a'&& s[i]<='z')||(s[i]>='A' && s[i]<='Z'))
          {
              cout<<s[i];
          }
          else if(s[i]=='(')
          st.push(s[i]);
          else if(s[i]==')')
          {
              while(st.empty()!=1 && st.top()!='(')
              {
                   c=st.top();
                    cout<<c;
                
                  st.pop();
              }
              if(st.empty()!=1)
              st.pop();
          }
          else
          {
              while(st.empty()!=1 && prec(st.top())>=prec(s[i]))
              {
                   c=st.top();
                    cout<<c;
                
                  st.pop();
              }
              st.push(s[i]);
          }
      }
      while(st.empty()!=1)
      {
          c=st.top();
           cout<<c;
         
          st.pop();
      }
      cout<<endl;
    }
	return 0;
 }
