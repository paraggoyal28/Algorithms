// Given an array arr[], the task is to remove at most one element and
// calculate the maximum length of strictly increasing subarray.
// Examples:
// Input: arr[] = { 1, 2, 5, 3, 4}
// Output: 4
// After deleting 5, the resulting array will be {1, 2, 3, 4}
// and the maximum length of its strictly increasing subarray is 4
// Input: arr[] = {1, 2}
// Output: 2
// The complete array is already strictly increasing.
// Approach:
// 1. Create two arrays pre[] and pos[] of size N.
// 2. Iterate over the input array arr[] from (0, N) to find out the 
// contribution of the current element arr[i] in the array till now
// [0, i) and update the pre[] array if it contributes in the strictly
// increasing subarray.
// 3. Iterate over the input array arr[] from [N-2, 0] to find out the
// contribution of the current element arr[j] in the array till now
// (N, j) and update the pos[] array if arr[j] contributes in the 
// longest increasing subarray.
// 4. Calculate the maximum length of the strictly increasing subarray 
// without removing any element.
// 5. Iterate over the array pre[] and pos[] to find out the 
// contribution of the current element by excluding that element.
// 6. Maintain a variable ans to find the maximum found till now.
// Below is the implementation of the above approach:


// C++ implementation of the approach
#include <bits/stdc++.h>
using namespace std;

// Function to return the maximum length of strictly increasing
// subarray after removing atmost one element
int maxIncSubarr(int a[], int n)
{
    // Create two arrays pre and pos
    int pre[n] = {0};
    int pos[n] = {0};
    pre[0] = 1;
    pos[n-1] = 1;
    int l = 0;
    
    // Find out the contribution of the current element in 
    // array[0, i]  and update pre[i]
    for (int i = 1; i < n; i++) {
        if (a[i] > a[i - 1])
            pre[i] = pre[i-1] + 1;
        else
            pre[i] = 1;
    }

    // Find out the contribution of the current element in 
    // array[N - 1, i] and update pos[i]
    l = 1;
    for (int i = n-2; i >= 0; i--){
        if (a[i] < a[i + 1])
            pos[i] = pos[i+1] + 1;
        else
            pos[i] = 1;
    }

    // Calculate the maximum length of the strictly increasing 
    // subarray without removing any element
    int ans = 0;
    l = 1;
    for (int i = 1;i < n; i++)
    {
        if (a[i] > a[i - 1])
            l++;
        else    
            l = 1;
        ans = max(ans, l);
    }
    
    // Calculate the maximum length of the strictly increasing 
    // subarray after removing the current element
    for (int i = 1; i <= n - 2; i++) {
        if (a[i - 1] < a[i + 1])
            ans = max(pre[i - 1] + pos[i + 1], ans);
    }
    return ans;
}

// Driver code
int main()
{
    int arr[] = { 1, 2};
    int n = sizeof(arr)/sizeof(int);
    cout << maxIncSubarr(arr, n);
    return 0;
}