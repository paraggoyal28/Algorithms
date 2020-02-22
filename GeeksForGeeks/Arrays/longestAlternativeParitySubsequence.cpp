/* Given an array a of size N. The task is to print the length of the
longest alternative odd/even or even/odd subsequence.
Examples:
Input: a[] = {13, 16, 8, 9, 32, 10}
Output: 4
{13, 16, 9, 10} or any other subsequence of length 4 can be the answer.
Input: a[] = {1, 2, 3, 3, 9}
Output: 3
{1, 2, 3}
Approach: The answer to the longest alternative parity subsequence
will be either [odd, even, odd, even, ... ] or [even, odd, even, odd, ..]
sequence. Hence iterate in the array and first find the longest odd/
even subsequence, and then the longest even/odd sequence.
The steps to find the longest subsequence is:
1. Iterate and find the next odd number and increase the length.
2. Iterate and find the next even number and increase the length.
3. Repeat step1 and step2 alternatively starting from step1 till the
end to find the longest odd/even subsequence.
4. Repeat step1 and step2 alternatively starting from step2 till the
end to find the longest even/odd subsequence.
Below is the implementation of the above approach:
C++ program to find the length of the longest alternative 
parity subsequence
*/
#include <iostream>
using namespace std;

// Function to find the longest 
int longestAlternativeSequence(int a[], int n)
{
    int maxi1 = 0;
    
    // Marks the starting of odd number
    // as sequence and alternatively changes
    int f1 = 0;

    // Finding the longest odd/even sequence
    for (int i = 0; i < n; i++) {

        // Find the odd number first
        if(!f1) {
            if(a[i] % 2) {
                f1 = 1;
                maxi1++;
            }
        }
        else {
            if(a[i] % 2 == 0) {
                maxi1++;
                f1 = 0;
            }
        }
    }
    
    int maxi2 = 0;
    int f2 = 0;

    // Length of the longest even/odd sequence
    for (int i = 0; i < n; i++) {
        // Find the odd number
        if (f2) {
            if(a[i] % 2) {
                f2 = 1;
                maxi2++;
            }
        }

        // Find even number
        else {
            if (a[i]%2 == 0) {
                maxi2++;
                f2 = 0;
            }
        }
    }

    // Answer is maximum of both odd/even or even/odd subsequence
    return max(maxi1, maxi2);
}

// Driver Code
int main()
{
    int a[] = {13, 16, 8, 9, 32, 10};
    int n = sizeof(a)/sizeof(int);
    cout << longestAlternativeSequence(a, n);
}

// Output:
// 4