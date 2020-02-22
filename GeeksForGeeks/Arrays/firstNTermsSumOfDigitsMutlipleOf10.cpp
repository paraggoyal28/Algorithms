/* Given an integer N, the task is to print the first N terms whose
sum of digits is a multiple of 10. First few terms of the series are
19, 28, 37, 46, 55,...
Input: N = 5
Output: 19 28 37 46 55 
Input: N = 10
Output: 19 28 37 46 55 64 73 82 91 109
Approach: It can be observed that to get the Nth term of the required
series, find the sum of the digits of N. If the sum is already a multiple
of 10 then append digit 0 in the end of N else append the minimum  
possible digit in the end so that the new sum of digits is a multiple
of 10.
For example, to get the 19th term, since the sum of digits is already 
a multiple of 10 then append 0 and 190 is the 19th term of the series.
For N = 5, the minimum digit that can be appended to make the sum of
the digits as a multiple of 10 is 5 and 55 is the 5th term of the series.
Below is the implementation of the above approach:
*/
#include <bits/stdc++.h>
using namespace std;

const int TEN = 10;

// Function to return the 
// sum of digits of n
int digitSum(int n)
{
    int sum = 0;
    while (n > 0) {

        // Add last digit to the sum
        sum  += n % TEN;

        // Remove the last digit 
        n /= TEN;
    }
    return sum;
}

// Function to return the nth term of 
// the required series
int getNthTerm(int n)
{
    int sum = digitSum(n);
    
    // If the sum of digit is already 
    // a multiple of 10 then append 0
    if ( sum % TEN  == 0){
        return (n * TEN);
    }

    // To store the minimum digit that
    // must be appended
    int extra = TEN - (sum % TEN);

    // Return n after appending 
    // the required digit
    return ((n* TEN) + extra);
}

// Function to print the first n terms
// of the required series
void firstNTerms(int n)
{
    for (int i = 1; i <= n; i++){
        cout << getNthTerm(i) << " ";
    }
}

// Driver Code
int main()
{
    int n = 10;
    firstNTerms(n);
    return 0;
}

// Output:
// 19 28 37 46 55 64 73 82 91 109
