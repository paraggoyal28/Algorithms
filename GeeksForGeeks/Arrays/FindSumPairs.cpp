/* Given an array arr[] of N integers, the task is to find the sum of all the 
pairs possible from the given array. Note that,
1. (arr[i], arr[i]) is also considered as a valid pair.
2. (arr[i], arr[j]) and (arr[j], arr[i]) are considered as two different valid pairs.
Examples:
Input: arr[] = {1, 2}
Output: 12
All valid pairs are (1,1), (1,2), (2,1) and (2,2).
1 + 1 + 1 + 2 + 2 + 1 + 2 + 2 = 12
Input: arr[] = {1,2,3,1,4}
Output: 110
Naive approach: Find all the possible pairs and calculate the sum of the elements of 
each pair.
Below is the implementation of the above approach.
*/
#include <bits/stdc++.h>
using namespace std;

// Function to return the sum of the elements 
// of all the possible pairs of the array
int sumPairs(int arr[], int n)
{
    // To store the required sum
    int sum = 0;

    // Nested loops for all the possible pairs
    for (int i=0; i < n; i++){
        for (int j=0; j < n; j++){
            // Add the sum of the elements 
            // of the current pair
            sum += (arr[i] + arr[j]);
        }
    }
    return sum;
}

// Driver Code
int main()
{
    int arr[] = {1,2,3};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << sumPairs(arr, n);
    return 0;
}