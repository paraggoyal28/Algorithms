/* Given an array arr[] of N integers and another integer K.
The task is to find the maximum sum of a subsequence such that the
difference of the indices of all consecutive elements in the 
subsequence in the original array is exactly K. For example, if arr[i]
is the first element of the subsequence then the next element has 
to be arr[i+k] then arr[i+2k] and so on.
Examples:
Input: arr[] = {2, -3, -1, -1, 2}, K = 2
Output: 3
Input: arr[] = {2, 3, -1, -1, 2}, K = 3
Output: 5
Approach: There are K sequences possible where the elements are K
distance apart and these can be of the forms:
0, 0 + k, 0 + 2k, ...., 0 + n*k
1, 1 + k, 1 + 2k, ...., 1 + n*k
2, 2 + k, 2 + 2k, ...., 2 + n*k
....
k-1, k-1 + k, k-1 + 2k, ...., k-1 + n*k
Now any subarray of the sequences is a subsequence of the original 
array where elements are K distance apart from each other.
So, the task now reduces to find the maximum subarray sum of these
sequences which can be found by Kadane's algorithm.
Below is the implementation of the above approach:
// C++ implementation of the approach:
*/
#include<bits/stdc++.h>
using namespace std;

// Function to return the maximum subarray sum 
// for the array {a[i], a[i + k], a[i + 2k], a[i + 3k], ....}
int maxSubArraySum(int a[], int n, int k, int i)
{
    int max_so_far = INT_MIN, max_ending_here = 0;
    while(i < n){
        max_ending_here = max_ending_here + a[i];
        if(max_so_far < max_ending_here)
            max_so_far = max_ending_here;
        if(max_ending_here < 0)
            max_ending_here = 0;
        i += k;
    }
    return max_so_far;
}
// Function to return the sum of the maximum required subsequence
int find(int arr[], int n, int k)
{
    // To store the result
    int maxSum = 0;

    // Run a loop from 0 to k
    for (int i = 0;i <= min(n, k); i++) {
        int sum = 0;
        // Find the maximum subarray sum for the
        // array {a[i], a[i + k], a[i + 2k], ....}
        maxSum = max(maxSum, maxSubArraySum(arr, n, k, i));
    }
    return maxSum;
}
// Driver code
int main()
{
    int arr[] = {2, -3, -1, -1, 2};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 2;

    cout << find(arr, n, k);
    return 0;
}
// Output
// 3