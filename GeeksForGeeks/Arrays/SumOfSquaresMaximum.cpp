/* Given an integer array arr[], the task is to divide this array into two non-empty subsets such that 
the sum of the square of the sum of both the subsets is maximum and sizes of both the subsets must not 
differ by more than 1.

Examples:
Input: arr[] = {1,2,3}
Output: 26
Maximum among these is 26, Therefore the required sum is 26.
Input: arr[] = {7,2,13,4,25,8}
Output: 2845
Approach: The task is to maximize the sum of a^2 + b^2 where a and b are the sum of two subsets
and a+b = C(constant) i.e the sum of the entire array. The maximum sum can be achieved by sorting the 
array and dividing the first N/2 - 1 smaller elements in one subset and the rest N/2 + 1 elements in 
other subset. In this way, the sum can be maximized while keeping the difference in size at most 1.
Below is the implementation of the above approach:
*/
#include <bits/stdc++.h>
using namespace std;

// Function to return the maximum sum of the 
// square of the sum of two subsets of an array
int maxSquareSubsetSum(int* A, int N)
{
    // Initialize variables to store
    // the sum of subsets
    int sub1 = 0, sub2 = 0;
    // sorting the array
    sort(A, A + N);

    // Loop through the array
    for (int i = 0; i < N; i++){
        // Sum of the first subset
        if (i < (N/2) - 1)
            sub1 += A[i];
        
        // Sum of the second subset
        else
            sub2 += A[i];
    }
    
    // Return the maximum sum of the square of the sum 
    // of subsets
    return sub1 * sub1 + sub2 * sub2;
}
// Driver Code
int main()
{
    int arr[] = {7, 2, 13, 4, 25, 8};
    int N = sizeof(arr)/sizeof(arr[0]);
    cout << maxSquareSubsetSum(arr, N);
    return 0;
}