/* Given a binary tree (not a binary search tree) and any number of Key nodes, the task is to find
the least common ancestor of all key nodes
Let T be a rooted tree. The lowest common ancestor between two nodes n1 and n2 is defined as the 
lowest node in T that has both n1 and n2 as descendants(where we allow a node to be a descendant
of itself).
The LCA of any number of nodes in T is the shared common ancestor of the nodes that is located 
farthest from the root.
                    1
                  /    \
                 2       3
                /\       / \
               4  5     6    7
              /\  /\    /\   /\
             8 9 10 11 12 13 14 15
Example: In the figure above:
LCA of nodes 12, 14, 15 is node 3.
LCA of nodes 3, 14, 15 is node 3.
LCA of nodes 6, 7, 15  is node 3.
LCA of nodes 5, 13, 14, 15 is node 1.
LCA of nodes 6, 12 is node 6.

Approach: 
Following is the somple approach for Least Common Ancestor for any
number of nodes.
1. For every node calculate the matching number of nodes at that node and its sub tree.
    a. If root is also a matching node.
        matchingNodes = matchingNodes in left sub-tree + 
            matchingNodes in right sub-tree + 1
    b. If root is not a matching node
        matchingNodes = matchingNodes in left sub-tree + 
            matchingNodes in right sub-tree
2. If matching Nodes count at any node is equal to number of keys then add that node
into the ancestors list.

3. The first node in the ancestors list is the Least Common Ancestor of all the given 
keys.

Below is the implementation of above approach.
*/

// Java implementation to find 
// Ancestors of any number of nodes
import java.util.ArrayList;

// Tree Class
class TreeNode {
    int data;
    TreeNode left;
    TreeNode right;
    public TreeNode(int value)
    {
        this.data = value;
        left = right = null;
    }
}

public class LCAofAnyNumberOfNodes {
    // Function to find Least Common 
    // Ancestors of N number of nodes
    public static TreeNode lcaOfNodes(
        TreeNode root,
        ArrayList<Integer> keyNodes)
    {
        // Create a new list of 
        // capturing all the ancestors 
        // of the given nodes
        ArrayList<TreeNode> ancestors = new ArrayList<TreeNode>();

        // Initially there is No matching Nodes
        int matchingNodes = 0;
        getKeysCount(root, keyNodes, matchingNodes, ancestors);

        // First node in the ancestors list is the least common ancestor
        // of given keynodes
        return ancestors.get(0);
    }

    private static int getKeysCount(
        TreeNode root, ArrayList<Integer> keyNodes,
        int matchingNodes,
        ArrayList<TreeNode> ancestors
    )
    {
        // Base Case: When root is Null
        if (root == null)
            return 0;
        
        // Search for left and right subtree 
        // for matching child key node
        matchingNodes += getKeysCount(root.left, keyNodes, matchingNodes, ancestors)
                        + getKeysCount(root.right, keyNodes, matchingNodes, ancestors);

        // Condition to check if the Root Node is 
        // also in Key Node
        if (keyNodes.contains(root.data)){
            matchingNodes++;
        }

        // Condition when matching Nodes is equal to the 
        // Key Nodes found
        if (matchingNodes == keyNodes.size())
            ancestors.add(root);

        return matchingNodes;
    }
    
    // Driver Code
    public static void main(String[] args)
    {
        // Creation of Tree
        TreeNode root = new TreeNode(1);

        root.left = new TreeNode(2);
        root.right = new TreeNode(3);
        root.left.left = new TreeNode(4);
        root.left.right = new TreeNode(5);
        root.right.left = new TreeNode(6);
        root.right.right = new TreeNode(7);
        root.left.left.left = new TreeNode(8);
        root.left.left.right = new TreeNode(9);
        root.left.right.left = new TreeNode(10);
        root.left.right.right = new TreeNode(11);
        root.right.left.left = new TreeNode(12);
        root.right.left.right = new TreeNode(13);
        root.right.right.left = new TreeNode(14);
        root.right.right.right = new TreeNode(15);
        
        // Key Nodes for LCA
        ArrayList<Integer> keyNodes = new ArrayList<Integer>();
        keyNodes.add(12);
        keyNodes.add(14);
        keyNodes.add(15);
        System.out.println(lcaOfNodes(root, keyNodes).data);
    }
}