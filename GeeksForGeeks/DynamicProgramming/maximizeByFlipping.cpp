/* Given a binary array, find the maximum number zeros in an array 
with one flip of a subarray allowed. A flip operation switches all 0s 
to 1s and 1s to 0s.
Examples:
Input: arr[] = {0, 1, 0, 0, 1, 1, 0}
Output: 6
We can get 6 zeros by flipping the subarray {1, 1}

Input: arr[] = {0, 0, 0, 1, 0, 1}
Output: 5

Method 1: Simple O(N^2)
A simple solution is to consider all subarrays and find a subarray
with maximum value of (count of 1s ) - (count of 0s). Let this value
be max_diff. Finally return count of zeros in original array plus
max_diff.

C++ program to maximize number of zeroes ina binary array by at most
one flip operation
*/
#include<bits/stdc++.h>
using namespace std;

// A Kadane's algorithm based solution to find maximum 
// number of 0s by flipping a subarray
int findMaxZeroCount(bool arr[], int n)
{
    // Initialize max_diff = maximum of (Count of 0s - count of 1s)
    // for all subarrays.
    int max_diff = 0;
    // Initialize count of 0s in the original array
    int orig_zero_count = 0;
    // Consider all subarrays by using two nested loops
    for (int  i = 0; i < n; i++)
    {
        // Increment count of zeros
        if (arr[i] == 0)
            orig_zero_count++;
        
        // Initialize counts of 0s and 1s.
        int count1 = 0, count0 = 0;
        
        // Consider all subarrays starting from arr[i]
        // and find the difference between 1s and 0s
        // Update max_diff if required
        for (int j = i; j < n; j++)
        {
            (arr[j] == 1)? count1++ : count0++;
            max_diff = max(max_diff, count1 - count0);
        }
    }
    // Final result would be count of 0s in original array 
    // plus max_diff.
    return orig_zero_count + max_diff;
}

// Driver program
int main()
{
    bool arr[] = {0, 1, 0, 0, 1, 1, 0};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << findMaxZeroCount(arr, n);
    return 0;
}

// Output
// 6


// Method 2 (Efficient: O(n))
// This problem can be reduced to largest subarray sum problem. The
// idea is to consider every 0 as -1 and every 1 as 1, find the sum
// of largest subarray sum in this modified array. This sum is our
// required max_diff(count of 0s - count of 1s in any subarray).
// Finally we return the max_diff plus count of zeros in original array.

// Implementation
// C++ program to maximize number of zeroes in  a binary array by
// at most one flip operation
#include <bits/stdc++.h>
using namespace std;

// A Kadane's algorithm based solution to find the maximum number of 
// 0s by flipping a subarray.
int findMaxZeroCount(bool arr[], int n)
{
    // Initialize count of zeros and maximum difference between 
    // count of 1s and 0s in a subarray
    int orig_zero_count = 0;
    // Initialize overall max diff for any subarray
    int max_diff = 0;
    // Initialize current max
    int curr_max = 0;
    for (int i = 0; i < n; i++)
    {
        // Count of zeros in original array
        if (arr[i] == 0)
            orig_zero_count++;
        
        // value to be considered for finding the maximum sum
        int val = (arr[i] == 1)? 1: -1;

        // Update current max and max_diff.
        curr_max = max(val, curr_max + val);
        max_diff = max(max_diff, curr_max);
    }
    max_diff = max(0, max_diff);
    return orig_zero_count + max_diff;
}

// Driver program
int main()
{
    bool arr[] = {0, 1, 0, 0, 1, 1, 0};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << findMaxZeroCount(arr, n);
    return 0;
}