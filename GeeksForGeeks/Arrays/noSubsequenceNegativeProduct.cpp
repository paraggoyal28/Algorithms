/* Given an array arr[] of N integers, the task is to find the 
count of all the subsequences of the array that have a negative 
products.
Examples:
Input: arr[] = {1, -5, -6}
Output: 4
Explanation: 
{-5}, {-6}, {1, -5}, {1, -6}.
Input: arr[] = {2, 3, 1}
Output: 0
Explanation: There is no such possible subsequence with negative product
Naive:
Generate all the subsequences of the array and compute the product
of all the subsequences. If the product is negative then increment the
count by 1
Efficient Approach:
1. Count the number of positive and negative elements in the array.
2. An odd number of negative elements can be chosen for the subsequence
to maintain the negative product. The number of different combinations 
of subsequences with an odd number of negative elements will be 
pow(2, count of negative elements - 1)
3. Any number of positive elements can be chosen for the subsequence 
to maintain the negative product. The number of different combinations
of subsequences with all the posititve elements will be
pow(2, count of positive elements)
*/
// C++ implementation of the approach
#include <bits/stdc++.h>
using namespace std;

// Function to return the count of all the subsequences with 
// negative product
int cntSubSeq(int arr[], int n)
{
    // To store the count of positive 
    // elements in the array
    int pos_count = 0;

    // To store the count of negative elements
    // in the array
    int neg_count = 0;

    int result;

    for (int i = 0; i < n; i++ ) {
        
        // If the current element
        // is positive
        if(arr[i] > 0)
            pos_count++;
        
        // If the current element
        // is negative
        if (arr[i] < 0)
            neg_count++;
    }

    // For all the positive elements of the array
    result = pow(2, pos_count);

    // For all the negative elements of the array
    if(neg_count > 0) 
        result *= pow(2, neg_count - 1);
    else
        result = 0;
    return result;
}

// Driver Code
int main()
{
    int arr[] = {3, -4, -1, 6};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << cntSubSeq(arr, n);
    return 0;
}

// Time Complexity: O(n)
// Another Approach:
/* We can also count the number of subsequences with a negative
product by subtracting total number of subsequences with the
positive subsequences from the total number of subsequences.