/* Given a binary tree and a leaf node from this tree. It is known that
in 1s all nodes connected to a given node get's burned.That is left 
child, right child and parent. The task is to find the minimum time
required to burn the complete binary tree.
Examples:
Input:
        1
       / \
      2   3
     / \   \
    4   5   6
       / \   \
      7   8   9
               \
                10
Leaf = 8
Output: 7
Initially 8 is set to fire at 0th sec.
        1
       / \
      2   3
     / \   \
    4   5   6
       / \   \
      7   F   9
               \
                10
After 1 sec: 5 is set to fire.
        1
       / \
      2   3
     / \   \
    4   F   6
       / \   \
      7   F   9
               \
               10
After 2 sec: 7 and 2 are set to fire.
        1
       / \
      F   3
     / \   \
    4   F   6
       / \   \
      F   F   9
               \
                10
After 3 sec: 4 and 1 are set to fire
        F
       / \
      F   3
     / \   \
    F   F   6
       / \   \
      F   F   9
               \
                10
After 4 sec: 3 is set to fire
        F
       / \
      F   F
     / \   \
    F   F   6
       / \   \
      F   F   9
               \
                10
After 5 sec: 6 is set to fire
        F
       / \
      F   F
     / \   \
    F   F   F
       / \   \
      F   F   9
               \
                10
After 6 sec: 9 is set to fire
        F
       / \
      F   F
     / \   \
    F   F   F
       / \   \
      F   F   F
               \
                10
After 7 sec: 10 is set to fire.
        F
       / \
      F   F
     / \   \
    F   F   F
       / \   \
      F   F   F
               \
                F
After 7 sec. whole tree will burn.
The idea is to store extra additional information for every node:
1) Depth of left subtree.
2) Depth of right subtree.
3) The time required for the fire to reach the current node starting from
the first leaf node burnt.
4) A boolean variable to check if the initial burnt node is in the tree
rooted under the current node.

Before moving ahead lets look at the tree below:
                1
               / \
              2   3
             / \  /
            4   5 6 
           /   / \
          8   9   10
             /
            11

In the above tree, if we set node 11 at fire.
1. In 1 sec, the fire will reach node 9
2. In 2 sec, the fire will reach node 5
3. In 3 sec, the fire will reach node 2 and node 10. Here comes an observation:
    a)In 2s the fire reached node 5. For node 5, the initial burned leaf is in 
     it's left subtree, so the time taken to burn right subtree will be the height
     of right subtree which is 1. Therefore, fire will reach node 10 in (2+1) = 3s.
    b) Again for node 2 Fire reached to node 2 in 3 sec, from right subtree.Therefore,
    time taken to burn left subtree will be it's height.
So the solution is to apply recursion and for every node calculate the below required values:
1. Left Depth
2. Right Depth
3. The time required for fire to reach current node
4. Is the current subtree contains the initial burned leaf node.

So, for the minimum time required to burn any subtree will be:
The time required for fire to reach the root node from initial burnt leaf + 
depth of the opposite side

Therefore, to find time required to burn the complete tree, we need to calculate the 
above value for all nodes and take maximum of that value.

ans = max(ans, (time required for fire to reach current node + depth of other subtree)).

Below is the implementation of the above approach:
*/
// C++ program to find the minimum time required to burn the binary tree completely.
#include<bits/stdc++.h>
using namespace std;

// Tree Node
struct Node{
        int data;
        Node* left;
        Node* right;
        Node(){
                left = NULL;
                right = NULL;
        }
};

//Utility function to create a new node
Node* newNode(int val)
{
        Node* temp = new Node;
        temp->data = val;
        return temp;
}
/*
************* ADDITIONAL INFO ***************
lDepth - maximum height of left subtree
rDepth - maximum height of right subtree
contains - stores true if tree rooted at the current node contains the first burnt node
time - time for the fire to reach from the first burnt node to this node
*/
struct Info{
        int lDepth;
        int rDepth;
        bool contains;
        int time;
        Info(){
                lDepth = rDepth = 0;
                contains = false;
                time = -1;
        }
};

/* Function to calculate time required to burn tree completely. 
node - address of the current node
info - extra information about the current node
target - node that is fired
res - stored the result
*/
Info calcTime(Node* node, Info& info, int target, int& res)
{
        // Base Case: If root is null
        if(node == NULL)
                return info;
        
        // If current node is leaf
        if(node->left == NULL && node->right == NULL){
                // If current node is the first burnt node
                if(node->data == target){
                        info.contains = true;
                        info.time = 0;
                }
                return info;
        }

        // Information about the left child of root
        Info leftInfo;
        calcTime(node->left, leftInfo, target, res);

        // Information about the right child of root
        Info rightInfo;
        calcTime(node->right, rightInfo, target, res);

        // If left subtree contains the fired node 
        // then time required to reach fire to current node
        // will be (1 + time required for left child )
        info.time = (node->left && leftInfo.contains)?(leftInfo.time + 1):-1;

        // If right subtree contains the fired node
        // then time required to reach fire to current node
        // will be (1 + time required for right child)
        if (info.time == -1)
                info.time = (node->right && rightInfo.contains)?(rightInfo.time + 1): -1;

        // Storing (true or false) if the tree rooted at current node
        // contains the fired node
        info.contains = ((node->left && leftInfo.contains)||(node->right && rightInfo.contains));

        // Calculate the maximum depth of the left subtree
        info.lDepth = !(node->left)? 0: (1 + max(leftInfo.lDepth, leftInfo.rDepth));
        
        // Calculate the maximum depth of the right subtree
        info.rDepth = !(node->right)? 0: (1 + max(rightInfo.lDepth, rightInfo.rDepth));

        // Calculate the answer
        if(info.contains){
                // If left subtree exists and 
                // contains the fired node
                if(node->left && leftInfo.contains){
                        // calculate the result
                        res = max(res, info.time + info.rDepth);
                }
                
                // Else if right subtree exists and
                // contains the fired node
                if(node->right && rightInfo.contains){
                        // calculate the result
                        res = max(res, info.time + info.lDepth);
                }
        }
}

// Driver function to calculate the minimum time required
int minTime(Node* root, int target)
{
        int res = 0;
        Info info;
        calcTime(root, info, target, res);
        return res;
}

// Driver Code
int main()
{
        Node* root = newNode(1);
        root->left = newNode(2);
        root->right = newNode(3);
        root->left->left = newNode(4);
        root->left->right = newNode(5);
        root->right->left = newNode(6);
        root->left->left->left = newNode(8);
        root->left->right->left = newNode(9);
        root->left->right->right = newNode(10);
        root->left->right->left->left = newNode(11);
        

        // target node is 11
        int target = 11;

        cout << minTime(root, target);

        return 0;
}