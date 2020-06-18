//https://practice.geeksforgeeks.org/problems/find-length-of-loop/1
/*
Given a linked list of size N. The task is to complete the function countNodesinLoop() that checks whether a given Linked List contains a loop or not and if the loop is present then return the count of nodes in a loop or else return 0.

Input:
The first line of input contains the number of testcases T. For each test case, the first line of input contains the length of a linked list and next line contains data of the linked list, and the third line contains the position of the node from the beginning (0 based indexing) to which the last node will be connected to form a loop.
Note: If the input of the third line is zero then there is no loop.

Output:
For each test case, there will be a single line of output containing the length of the loop in a linked list, else print 0, if the loop is not present in the linked list.

User Task:
The task is to complete the function countNodesinLoop() which contains the only argument as reference to head of linked list.

Challenge : Try to solve the problem with constant Auxilliary space and Linear Time Complexity.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(1)

Constraints:
1 <= T <= 100
1 <= N <= 500
0 <= C <= N-1

Example:
Input:
2
10
25 14 19 33 10 21 39 90 58 45
4
2
1 0
1
Output:
6
1

Explanation:
Testcase 1: The loop is 45->10. So length of loop is 10->21->39->90->58->45 = 6. The number 10 is connected to the last node to form the loop because according to the input the 4th node from the beginning(0 based index) will be connected to the last node for the loop.
Testcase2:  The length of the loop is 1.

*/

// { Driver Code Starts
#include<stdio.h>
#include<stdlib.h>
#include<bits/stdc++.h>
using namespace std;

struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};

void append(struct Node **tail, int data)
{
	struct Node* new_node = new Node (data);
	(*tail)->next = new_node;
	(*tail) = new_node;
	return;
}

void printList(struct Node *tmp){
    while(tmp){
        cout<<tmp->data<<' ';
        tmp=tmp->next;
    }
    cout<<endl;
}

int countNodesinLoop(struct Node *head);

/* Drier program to test above function*/
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n, tmp;
        cin>>n;
        struct Node *head = NULL;
        struct Node *tail = NULL;
        struct Node* temp;
        struct Node *s;
        struct Node *t;
        cin>>tmp;
        struct Node* new_node = new Node (tmp);
        head = new_node;
        tail = new_node;
        s=head;
        for(int i=1; i<n; i++){
            cin>>tmp;
            append(&tail, tmp);
        }
        /* Create a loop for testing */
        // srand(time(NULL));
        int c;
        cin>>c;
        if(c>0){
            //c=c-1;
            temp=head;
            t = head;
            while(t->next)t=t->next;
            while(c--)temp=temp->next;
            t->next=temp;
            // s->next=temp;
        }
        //printList(head);
        cout<<countNodesinLoop(head)<<endl;
	}
    return 0;
}// } Driver Code Ends


/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/
// Your task is to complete the function this function
// function should return the size of the loop
int countNodesinLoop(struct Node *head)
{
     // Code here
     Node*fast = head;
     Node*slow = head;
     bool flag = false;
     while(fast && slow && fast->next!=NULL)
     {
         fast = fast->next->next;
         slow = slow->next;
         if(slow==fast)
         {
             flag =true;
             break;
         }
     }
     if(flag)
     {
         int count=0;
         Node*temp = slow;
         while(slow!=NULL)
         {
             slow=slow->next;
             count++;
             if(slow==temp)
             break;
         }
         return count;
     }
     return 0;
}
