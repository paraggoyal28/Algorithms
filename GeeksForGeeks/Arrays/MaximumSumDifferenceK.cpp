/* Given an array arr[] consisting of integers of length N and an integer K ( 1<= K <= N), the task is to find
the maximum subsequence sum in the array such that adjacent elements in that subsequence have at least a 
difference of K in their indices in the original array.
Examples:
Input: arr[] = {1,2,-2,4,3,1}, K = 4
Output: 4
Explanation: Such subsequnces that can be selected: {1,3}, {1,1}, {2,1}
Subsequence with maximum sum = (1+3) = 4.
Selected elements are a[0] and a[4](difference between indices = 4).
Input: arr[] = {1,2,72,4,3}, K = 2
Output: 76
Explanation: Such subsequences that can be selected - {{1,72,3},{2,4},
{2,3},{1,4},{1,3}}
Subsequence with maximum sum = (1+72+3) = 76
Selected elements are a[0], a[2] and a[4](difference between each indices = 2)
Naive approach: Generate all possible subsets of the array and check for each 
of the subsets that it satisfies the condition such that two adjacent elements
have at least difference of K in their indices. If yes, then compare its sum with 
the largest sum obtained till now and update the sum if it is greater than the
obtained sum till now.
Efficient Approach: This problem can be solved using Dynamic Programming, in which 
for each element in array consider such that if we take this element then is it 
contributes into the final sum obtained. If yes then add it into the DP array for
that element.
Let's decide the states of 'dp'.Let dp[i] be the largest possible sum for the sub-
array starting from index '0' and ending at index 'i'. Now, we have to find a 
recurrence relation between this state and a lower order state.
Now the Recurrence Relation for the array will have two choices for every index i.
1. Choose the current index:
In this case, the element that can be chosen is at index i - k. So,
dp[i] = arr[i] + dp[i - k]

2. Skip the current index.
In this case, the element that can be chosen is at index i - 1.
So,
dp[i] = dp[i-1]
For every index choose that condition which gives the maximum sum at that index,
So final recurrence relation will be:
dp[i] = max(dp[i-1], arr[i] + dp[i-k])
Below is the implementation of the above approach.

C++ implementation to find the maximum sum subsequence such that two adjacent element
have atleast difference of K in their indices.
*/
#include <bits/stdc++.h>
using namespace std;

// Function to find the maximum between two elements a and b
int maxi(int a, int b)
{
    if (a > b) {
        return a;
    }
    else{
        return b;
    }
}

// Function to find the maximum sum subsequence such that two adjacent 
// element have atleast difference of K in their indices.
int max_sum(int arr[], int n, int k)
{
    // DP array to store the maximum sum obtained till now
    int dp[n];

    // Either select the first element or Nothing
    dp[0] = maxi(0, arr[0]);
    int i = 1;
    
    // Either select the (i-1) element or let the previous best answer be the
    // current best answer
    while(i < k){
        dp[i] = maxi(dp[i-1], arr[i]);
        i++;
    }
    i = k;

    // Either select the best sum 
    // till previous_index or select the 
    // current element + best_sum till index k
    while(i < n) {
        dp[i] = maxi(dp[i-1], arr[i] + dp[i-k]);
        i++;
    }
    return dp[n-1];
}

// Driver Code
int main()
{
    int arr[] = {1,2,-2,4,3,1};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 4;
    cout << max_sum(arr, n, k);
    return 0;
}

// Output: 4
// Time Complexity: O(N).
// Space Complexity: O(N).