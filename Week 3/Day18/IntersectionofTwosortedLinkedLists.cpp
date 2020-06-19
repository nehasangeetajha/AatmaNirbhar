//https://practice.geeksforgeeks.org/problems/intersection-of-two-sorted-linked-lists/1
/*
Given two lists sorted in increasing order, create a new list representing the intersection of the two lists. The new list should be made with its own memory — the original lists should not be changed.

Input:
You have to complete the method which takes 3 argument: the head of the first linked list , the head of second linked list and the head of the third link list which is to be created. You should not read any input from stdin/console. There are multiple test cases. For each test case, this method will be called individually.

Output:
Complete the Function given to produce the desired list with intersectioned values.

User Task:
The task is to complete the function intersection() which should find the intersection of two linked list and add all the elements in intersection to the third linked list.

Expected Time Complexity : O(n+m)
Expected Auxilliary Space : O(n+m)

Constraints:
1 <= T <= 100
1 <= size of linked lists <= 5000
1 <= Data in linked list nodes <= 1000

Example:
Input:
2
5 4
1 2 3 4 6
2 4 6 8
4 2
10 20 40 50
15 40

Output:
2 4 6
40

Explanation:
Testcase 1: For the given first two linked list, 2, 4 and 6 are the elements in the intersection.
*/

// { Driver Code Starts
//

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int val)
    {
        data=val;
        next=NULL;
    }
};

Node* inputList(int size)
{
    Node *head, *tail;
    int val;
    
    cin>>val;
    head = tail = new Node(val);
    
    while(--size)
    {
        cin>>val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
}

Node* findIntersection(Node* head1, Node* head2);

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n,m;
	    cin>> n >> m;
	    
	    Node* head1 = inputList(n);
	    Node* head2 = inputList(m);
	    
	    Node* result = findIntersection(head1, head2);
	    
	    printList(result);
	    cout<< endl;
	}
	return 0;
}
// } Driver Code Ends


/* The structure of the Linked list Node is as follows:

struct Node
{
    int data;
    Node *next;
    Node(int val)
    {
        data=val;
        next=NULL;
    }
};

*/

Node* findIntersection(Node* head1, Node* head2)
{
    // Your Code Here
    unordered_map<int,bool>up;
    Node*newhead = NULL;
    Node*temp = NULL;
    while(head1!=NULL)
    {
        up[head1->data] = true;
        head1=head1->next;
    }
    while(head2!=NULL)
    {
        if(up[head2->data])
        {
            Node*newNode = new Node(head2->data);
            if(newhead==NULL)
            {
                newhead = newNode;
                temp = newhead;
            }
            else
            {
                temp->next=newNode;
                temp = temp->next;
            }
            up[head2->data] = false;
        }
        head2=head2->next;
    }
    return newhead;
}
