//https://practice.geeksforgeeks.org/problems/segregate-even-and-odd-nodes-in-a-linked-list/0

/*
Given a Linked List of integers, write a function to modify the linked list such that all even numbers appear before all the odd numbers in the modified linked list. Also, keep the order of even and odd numbers same.

Input:

The first line of input contains an integer T denoting the number of test cases.
The first line of each test case is N,N is the number of elements in Linked List.
The second line of each test case contains N input,elements in Linked List.

Output:

Print the all even numbers then odd numbers in the modified Linked List.

Constraints:

1 ≤ T ≤ 100
1 ≤ N ≤ 100
1 ≤ size of elements ≤ 1000

Example:

Input
3
7
17 15 8 9 2 4 6
4
1 3 5 7
7
8 12 10 5 4 1 6

Output
8 2 4 6 17 15 9
1 3 5 7
8 12 10 4 6 5 1
*/


#include<iostream>
using namespace std;
struct Node {
    int data;
    struct Node *next;
};
Node* push(Node *head, int data) {

    Node*temp = new Node();
    temp->data = data;
    temp->next=NULL;
    Node*last = head;
    if(head==NULL)
    {
        head = temp;
        return head;
    }
    while(last->next!=NULL)
    last=last->next;
    last->next=temp;
    return head;
}

int main()
 {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	    int n,x;
	    cin>>n;
	    Node*odd = NULL,*even=NULL;
	    for(int i=0;i<n;i++)
	    {
	        cin>>x;
	        if(x%2==0)
	        even = push(even,x);
	        else
	        odd = push(odd,x);
	    }
	    while(even!=NULL)
	    {
	        cout<<even->data<< " ";
	        even=even->next;
	    }
	    while(odd!=NULL)
	    {
	        cout<<odd->data<< " ";
	        odd=odd->next;
	    }
	    cout<<endl;
	}
	return 0;
}
