/* Given an array arr[] of N positive integers, the task is to find
the count of indices i such that all the elements from arr[0] to arr[i-1]
are smaller than arr[i].
Examples:
Input: arr[] = {1,2,3,4}
Output: 4
All indices satisfy the given condition.
Input: arr[] = {4,3,2,1}
Output: 1
only i = 0 is the valid index
Approach: The idea is to traverse the array from left to right and keep
track of the current maximum, whenever this maximum changes then the 
current index is a valid index so increment the resulting counter.
Below is the implementation of the above approach.
*/
#include <bits/stdc++.h>
using namespace std;

// Function to return the count
// of indices that satisfy
// the given condition
int countIndices(int arr[], int n)
{
    // To store the result
    int cnt = 0;

    // To store the current maximum 
    // Initialized to 0 since there are only 
    // positive elements in the array
    int max = 0;
    for (int  i = 0; i < n; i++) {

        // i is a valid index
        if (max < arr[i]) {

            // Update the maximum so far
            max = arr[i];

            // Increment the counter
            cnt++;
        }
    }
    return cnt;
}

// Driver Code
int main()
{
    int arr[] =  {1, 2, 3, 4};
    int n = sizeof(arr)/sizeof(int);
    cout << countIndices(arr, n);
    return 0;
}

// Output
// 4
