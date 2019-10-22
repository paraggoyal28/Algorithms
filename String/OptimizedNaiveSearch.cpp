// Consider a situation when all the characters of the pattern are different. How can we modify the naive string search algorithm so that
// it works for this type of cases well. When all the characters of the pattern are different, we can slide the pattern by more than 1.
// When a mismatch occurs after j matches, we know that the first character of pattern will not match with the jth character because all
// characters are different. So we can slide the pattern by j without missing any valid shifts.Following is the modified code that is 
// modified for special patterns.

#include<bits/stdc++.h>
using namespace std;

void search(string pat,string txt)
{
  int M  = pat.size();
  int N  = txt.size();
  int i  = 0;
  
  while(i <= N - M)
  {
    int j;
    for(j = 0;j< M; j++)
      if(txt[j+i]!=pat[j])
        break;
    if(j==M)
    {
      cout << "Pattern found at index "<<i<<endl;
      i = i+ M;
    }
    else if(j == 0)
      i = i + 1;
    else
      i = i + j;
}
int main()  
{  
    string txt = "ABCEABCDABCEABCD";  
    string pat = "ABCD";  
    search(pat, txt);  
    return 0;  
}  

