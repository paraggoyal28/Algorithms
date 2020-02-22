/* Maximum non attacking Knights that can be placed on an N*M Chessboard
Given an N*M chessboard. The task is to find the maximum number of knights that can be 
placed on the given chessboard such that no knight attack some other knight.
Example:
Input: N = 1, M = 4
Output: 4
Place a knight on every cell of the chessboard
Input: N = 4, M = 5
Output: 10
Approach: As we knwo that a knight can attack in two ways. Here are the places in which he can attack.
Here, in the picture, the knight is on the white color and attacks only the black color.
Thus, we concluded that a knight can attack only on a different color.
We can take help of this fact and use it for our purpose. Now as we know knights attacks on different
color so we can keep all knights on the same color i.e all on white or all on black. Thus making the 
highest number of knights which can be placed.
Total Blocks = n * m
Blocks of the same color = (n * m)/2.
Corner Cases:
If there is only a single row or column, then all the blocks can be filled by knights as a knight 
cannot attack in the same row or column.
If there are only two rows or columns, then every two columns(or rows) will be filled with
knights and every consecutive two columns(or rows) will remain empty.
*/
#include <bits/stdc++.h>
using namespace std;

// Function to return the maximum number of knights that can be placed on the given 
// chessboard such that no two knights attack each other
int max_knight(int n, int m)
{
    // Check for corner case #1
    // If row or column is 1
    if (m == 1 || n == 1) {
        // If yes, then simply print total blocks which will be the max of row and column
        return max(n, m);
    }

    // Check for corner case #2
    // If row or column is 2
    else if (m == 2 || n == 2) {
        
        // If yes, then simply calculate 
        // consecutive 2 rows or columns
        int c = 0;
        c = (max(m, n) / 4) * 4;

        if (max(m, n) % 4 == 1) {
            c += 2;
        }
        else if (max(m,n) % 4 > 1) {
            c += 4;
        }
        return c;
    }
    
    // For general case, just print the half of the total blocks
    else {
        return ((( m * n ) + 1) / 2);
    }
}

// Driver Code 
int main()
{
    int n = 4, m = 5;
    cout << max_knight(n, m);
    return 0;
}