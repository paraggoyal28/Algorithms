/* Given an array arr[] of size N and an integer K. The task is to find the sum of f(s) 
over all possible sets.For a finite set X, f(X) is max(X) - min(X). Set X contains any K
numbers from the given array. Output can be very large, so, output answer modulo 10^9+7.
Examples:
Input: arr[] = {1,1,3,4}, K = 2
Output: 11
Sets are {1,1}, {1,3}, {1,4}, {1,3}, {1,4}, {3,4} and f(X) are 0,2,3,2,3,1
Input: arr[] = {10,-10,10,-10,10,-10}, K=3
Output: 360
18 sets with f(x) equal to 20 and 2 sets with f(x) equal to 0.
Approach:
On assuming that arr is sorted beforehand, the idea is to perform precomputations 
to calculate the binomial coefficients fast by precalculating the factorials till N 
and their inverses. The sum is calculated separately for min and max. In other words, 
(sum(max(S))) - (sum(min(S))), instead of sum(f(S)).
For simplicity, assume that arri is distinct from each other.The possible value of max(S)
is any element of arr. Therefore, by counting the number of S such that max(S) = arri for 
each i, you can find sum(max(S)). The necessary condition of max(S) = arri is S contains
arri, and also contains K-1 elements less than arri, so such number can be calculated directly
by binomial coefficients.We can calculate the sum(min(S)) similarly.
If Ai contains duplicates, we can prove that the explanation above also holds if we assume 
arbitrary order between arr is with the same value.
Below is the implementation of the approach.
*/
#include <bits/stdc++.h>
using namespace std;
#define N 100005
#define mod (int)(1e9 + 7)

// To store the factorial and the factorial mod inverse of a number
int factorial[N], modinverse[N];

// Function to find (a ^ m1) % mod
int power(int a, int m1)
{
    if (m1 == 0)
        return 1;
    else if (m1 == 1)
        return a;
    else if (m1 == 2)
        return (1LL * a * a) % mod;
    else if (m1 & 1) 
        return (1LL * a 
            * power(power(a, m1/2),2)) % mod;
    else
        return power(power(a, m1/2),2) % mod;
}

// Function to find the factorial of all numbers
void factorialfun()
{
    factorial[0] = 1;
    for (int i = 1; i < N; i++){
        factorial[i] = (1LL * i * factorial[i-1]) % mod;
    }
}

// Function to find the factorial mod inverse of all the numbers
void modinversefun()
{
    modinverse[N - 1] = power(factorial[N - 1], mod - 2) % mod;
    for (int i = N-2; i >= 0; i--){
        modinverse[i] = (1LL * modinverse[i + 1] * (i + 1)) % mod;
    } 
} 

// Function to return nCr
int binomial(int n, int r)
{
    if (r > n)
        return 0;
    int a = (1LL * factorial[n] * modInverse[n-r]) % mod;
    a = (1LL * a * modInverse[r]) % mod;
    return a;
}

// Function to find sum of f(s) for all the chosen sets from the given array
int max_min(int a[], int n, int k)
{
    // Sort the given array
    sort(a, a + n);

    // Calculate the factorial and
    // modinverse of all elements
    factorialfun();
    modinversefun();

    long long ans = 0;
    k--;

    // For all the possible sets
    // Calculate the max(S) and min(S)
    for (int i = 0; i < n; i++){
        int x = n - i - 1;
        if ( x >= k )
            ans -= (binomial(n, k) * a[i]) % mod;
        int y = i;
        if ( y >= k )
            ans += (binomial(n, k) * a[i]) % mod;
        ans = (ans + mod) % mod; 
    }
    return (int)(ans);
}

// Driver Code
int main()
{
    int a[] = {1, 1, 3, 4};
    int k = 2;
    int n = sizeof(a)/sizeof(a[0]);
    cout << max_min(a, n, k);
    return 0;
}