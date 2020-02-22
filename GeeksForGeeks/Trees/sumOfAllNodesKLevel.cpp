/* Given a binary tree with N nodes and an integer K, the task is to
find the sum of all the nodes present at the Kth level.
Examples:
Input: 
            10
           /  \
          20  50
         /  \ / \
        50 23 10 15
K = 1
Output: 70
Input: 
            50
           /  \ 
          30   70
         /  \  /
        20  40 60
K = 2
Output: 120
Approach:
1. Traverse the Binary Tree using Level Order Traversal and queue
2. During traversal, pop each element out of the queue and push it's
child (if available) in the queue.
3. Keep the track of the current level of the Binary tree.
4. To track the current level, declare a variable level and increase
whenever a child is traversed from the parent.
5. When the current level of the tree i.e the variable level meets the
required Kth level, pop the elements from the queue and calculate
their sum.
C++ implementation of the approach.
*/
#include <bits/stdc++.h>
using namespace std;

// Binary tree node consists of data,
// a pointer to the left child and a
// pointer to the right child
struct node {
    int data;
    struct node* left;
    struct node* right;
};

// Function to create a new Binary Tree node
struct node* newNode (int data)
{
    struct node* temp = new struct node;
    temp->data = data;
    temp->left = nullptr;
    temp->right = nullptr;
    return temp;
};

// Function  to return the sum of all
// the nodes at Kth level using
// level order traversal
int sumOfNodesAtNthLevel( struct node* root, int k)
{
    // If the current node is NULL
    if(root == nullptr)
        return 0;
    
    // Create Queue
    queue<struct node*> que;
    
    // Enqueue the root node
    que.push(root);

    // Level is used to track the 
    // current level
    int level = 0;

    // To store the sum of nodes
    // at the Kth level
    int sum = 0;

    // flag is used to break out of the loop
    // after the sum of all the nodes at Nth 
    // level is found
    int flag = 0;

    // Iterate the queue till its not empty;
    while (!que.empty()) {
        // Calculate the number of nodes in
        // the current level
        int size  = que.size();

        while(size--) {
            struct node* ptr = que.front();
            que.pop();

            if (level == k) {

                flag = 1;
                sum += ptr->data;
            }
            else {
                if (ptr->left)
                    que.push(ptr->left);
                
                if (ptr->right)
                    que.push(ptr->right);
            }
        }    
        level++;

        // Break out of loop after 
        // sum at current level is found
        if (flag == 1)
            break;
    }
    return sum;
}

// Driver Code
int main()
{
    struct node* root = new struct node;

    root = newNode(50);
    root->left = newNode(30);
    root->right = newNode(70);
    root->left->left = newNode(20);
    root->left->right = newNode(40);
    root->right->left = newNode(60);
    int level = 2;
    int result = sumOfNodesAtNthLevel(root, level);

    // Printing the result
    cout << result;
    return 0;
}

// Output:
// 120
// Time Complexity: O(N)