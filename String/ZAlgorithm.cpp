/*
This algorithm finds all occurences of a pattern in a text in linear time. Let length of text be n and of the pattern be m, then total
time taken is O(m+n) with linear space complexity.
Z Array
For a string str[0...n-1], Z array is of the same length as of string.An element Z[i] of Z array stores length of the longest substring 
starting from str[i] which is also a prefix of str[0...n-1].The first entry is meaningless.
How is Z Array helpful in searching pattern in linear time?
The idea is to concatenate pattern and text, and create a string "P$T" where P is the pattern and T is the text. Build the Z array for the
concatenated string. In Z array, if Z value at any point is equal to pattern length, then pattern is present at that point.
How to construct a z array in linear time
The idea is to maintain an interval [L,R] which is the interval with max R such that [L,R] is the prefix substring.
Steps for maintaining this interval are as follows:
1) If i > R, then there is no prefix substring that starts before i and ends after i, so we reset L and R and compute new L and R 
by comparing str[0...] to str[i..] and get Z[i] (=R-L+1).
2) If i<=R, then let K = i-L, now Z[i] >= min(Z[k],R-i+1) because str[i...] matches with str[K....] for at least R-i+1 characters.
Now two subcases will arise:
a) If Z[k] < R-i+1 then there is no prefix substring starting at str[i](otherwise Z[k] would be larger), so Z[i] = Z[k] and interval 
[L,R] remains same.
b) If Z[k] >= R-i+1 then it is possible to extend the [L,R] interval thus we will set L as i and start matching from str[R] onwards and 
get new R then we will update interval [L,R] and calculate Z[i] (= R-L+1).
*/

// A C++ Program that implements the Z Algorithm for pattern searching
#include<iostream>
using namespace std;

void getZarr(string str, int Z[]);

// prints all occurences of pattern in text using Z algo
void search(string text, string pattern)
{
  // Create concatenated string "P$T"
  string concat = pattern + "$" + text;
  int l = concat.length();
  
  // construct Z array
  int Z[l];
  getZarr(concat,Z);
  
  // looping through Z array for matching condition
  for(int i = 0; i < l ; i++)
  {
    // If Z[i] (matched region) is equal to the pattern length we got the pattern
    if(Z[i] == pattern.length())
    {
      cout<< "Pattern found at index " << i - pattern.length() - 1 <<endl;
    }
}

// Fills Z array for given string str[]
void getZarr(string str, int Z[])
{
    int n = str.length();
    int L, R, k;
  
    //[L,R] make a window which matches the prefix of s
    L = R = 0;
    for(int i = 1; i < n; i++)
    {
      // if i > R nothing matches we calculate Z[i] using naive way
      if(i > R)
      {
          L = R = i;
        
          // R-L = 0 in starting, so it will start checking from the beginning, 
          // For example for ababab and i = 1, the value of R remains 0 and Z[i] becomes 0
          // For string "aaaaaa" and i = 1, Z[i] = R = 5
          while(R < n && str[R-L] == str[R])
            R++;
          Z[i] = R-L;
          R--;
      }
      else
      {
          // k = i - L, so k corresponds to the number which matches in [L,R] interval.
          k = i - L;
          if(Z[k] < R-i+1)
            Z[i] = Z[k];
          
          else
          {
            L = i;
            while(R<n && str[R-L] == str[R])
              R++;
            Z[i] = R-L;
            R--;
          }
      }
   }
}

int main() 
{ 
    string text = "GEEKS FOR GEEKS"; 
    string pattern = "GEEK"; 
    search(text, pattern); 
    return 0; 
} 
 
    
