//https://practice.geeksforgeeks.org/problems/inorder-successor-in-bst/1
/*
Given a BST,  and a reference to a Node x in the BST. Find the Inorder Successor of the given node in the BST.

Input:
First line of input contains the number of test cases T. For each test case, there will be only two line of input, first line contains a string representing the tree as described below: 

The values in the string are in the order of level order traversal of the tree where, numbers denotes node values, and a character “N” denotes NULL child.

For example:

For the above tree, the string will be: 1 2 3 N N 4 6 N 5 N N 7 N

Second line of each test case will contain the integer value K. K is the data of the reference node.

Output:
For each test case output will be the Inorder successor of the given node. If no such successor is present output will be -1.

Your Task:
You don't need to read input or print anything. Your task is to complete the function inOrderSuccessor(). This function takes the root node and the reference node as argument and returns the node that is inOrder successor of the reference node. If there is no successor, return null value.

Expected Time Complexity: O(Height of the BST).
Expected Auxiliary Space: O(1).

Constraints:
1 <= T <= 1000
1 <= N <= 1000, where N is number of nodes
1 <= A[ ] <= 10000

Example:
Input:
2
20 8 22 4 12 N N N N 10 14
8
20 8 22 4 12 N N N N 10 14
10
Output:
10
12

Explanation:
Testcase 1:
                              20
                            /      \
                          8       22
                        /    \
                      4     12
                            /     \
                         10     14
InOrder traversal gives : 4 8 10 12 14 20 22
Hence successor of 8 is 10
*/

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// Tree Node
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
// Function to Build Tree
Node* buildTree(string str)
{   
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
            return NULL;
    
    // Creating vector of strings from input 
    // string after spliting by space
    vector<string> ip;
    
    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);
        
    // Create the root of the tree
    Node* root = new Node(stoi(ip[0]));
        
    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);
        
    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {
            
        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();
            
        // Get the current node's value from the string
        string currVal = ip[i];
            
        // If the left child is not null
        if(currVal != "N") {
                
            // Create the left child for the current node
            currNode->left = new Node(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->left);
        }
            
        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];
            
        // If the right child is not null
        if(currVal != "N") {
                
            // Create the right child for the current node
            currNode->right = new Node(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    
    return root;
}

Node* search(Node* root, int key)
{
    // Base Cases: root is null or key is present at root
    if (root == NULL || root->data == key)
       return root;
    
    // Key is greater than root's key
    if (root->data < key)
       return search(root->right, key);
 
    // Key is smaller than root's key
    return search(root->left, key);
}

Node * inOrderSuccessor(Node *, Node* );

int main()
{
    int t;
    cin>>t;
    getchar();
    
    while(t--)
    {
        string s;
        getline(cin,s);
        Node* head = buildTree(s);
        
        int k;
        cin>>k;
        getchar();
        
        Node* kNode = search( head, k );
        Node* suc = inOrderSuccessor(head, kNode);
        
        if( suc == NULL ) cout<< "-1";
        else cout<< suc->data;
        cout << endl;
    }
    
    return 1;
}// } Driver Code Ends


/*The structure of Node

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

Node*find(Node*root,Node*x)
{
    while(root && root->data!=x->data)
    {
        if(root->data>x->data)
            root= root->left;
        else if(root->data<x->data)
            root= root->right;
    }
    if(root && root->data==x->data)
    return root;
    else return NULL;
}

// returns the inorder successor of the Node x in BST (rooted at 'root')
Node * inOrderSuccessor(Node *root, Node *x)
{
    //Your code here
    Node*curr = find(root,x);
    Node*temp;
    if(curr==NULL)
        return curr;
    if(curr->right)
    {
        temp = curr->right;
        while(temp->left)
            temp = temp->left;
        return temp;
    }
    
    
    Node*successor=NULL;
    Node*ancestor=root;
    while(ancestor && ancestor!=curr)
    {
        if(curr->data<ancestor->data)
        {
            successor=ancestor;
            ancestor = ancestor->left;
        }
        else
            ancestor = ancestor->right;
    }
    return successor;
}
