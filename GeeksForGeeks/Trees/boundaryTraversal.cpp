/* Given a binary tree, print boundary nodes of the binary tree 
Anti-Clockwise starting from the root. For example, boundary
traversal of the following tree is "20 8 4 10 14 25 22"
            20
           /  \ 
          8    22
         / \    \
        4  12    25
          /  \   
         10  14
We break the problem in 3 parts:
1. Print the left boundary in top down manner.
2. Print all leaf nodes from left to right, which can again be 
subdivided into two sub parts:
    2.1 Print all leaf nodes of left subtree from left to right.
    2.2 Print all leaf nodes of right subtree from left to right.
3. Print the right boundary in bottom up manner.

*/
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left, *right;
};

// A simple function to print leaf nodes of a binary tree
void printLeaves(struct node* root){
    if(root == NULL){
        return;
    }
    printLeaves(root->left);

    // Print it if it is a leaf node
    if(!(root->left) && !(root->right)){
        printf("%d ", root->data);
    }

    printLeaves(root->right);
}

// A function to print all left boundary nodes except leaf node
void printBoundaryLeft(strcut node* root){
    if(root == NULL)
        return;
    
    if(root->left) {
        printf("%d ", root->data);
        printBoundaryLeft(root->left);
    }

    else if(root->right){
        printf("%d ", root->data);
        printBoundaryLeft(root->right);
    }
}

// A function to print all right boundary node s
void printBoundaryRight(struct node* root)
{
    if (root==NULL)
        return;
    
    if(root->right){
        printBoundaryRight(root->right);
        printf("%d ", root->data);
    }
    else if(root->left){
        printBoundaryRight(root->left);
        printf("%d ", root->data);
    }
}

// A function to do boundary traversal
void printBoundary(struct node* root)
{
    if(root==NULL)
        return;

    printf("%d ", root->data);

    printBoundaryLeft(root->left);

    printLeaves(root->left);
    printLeaves(root->right);

    printBoundaryRight(root->right);
}

// A utility function to create a new node
struct node* newNode(int data)
{
    struct node* temp = (struct node*)malloc(sizeof(struct node));

    temp->data = data;
    temp->left = temp->right = NULL;

    return temp;
}

int main()
{

    struct node* root = newNode(20);
    root->left = newNode(8);
    root->left->left = newNode(4);
    root->left->right = newNode(12);
    root->left->right->left = newNode(10);
    root->left->right->right = newNode(14);
    root->right = newNode(22);
    root->right->right = newNode(25);

    printBoundary(root);

    return 0;
}