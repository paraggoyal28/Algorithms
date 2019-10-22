/*
KMP ALGORITHM FOR PATTERN SEARCHING
Given a txt[0, ... n-1] and a pattern[0,...m-1], write a function search(char pat[],char txt[]) that prints all occurences of the pat[] in
txt[]. You may assume n>m.
Input:  txt[] = "AABAACAADAABAABA"
	pat[] = "AABA"
Output: Pattern found at index 0
	Pattern found at index 9
	Pattern found at index 12
LONGEST PREFIX SUFFIX
lps[i] = the longest proper prefix of pat[0..i] which is also a suffix of pat[0..i].

Example of lps construction:
For the pattern "AAAA":
lps[] = [0,1,2,3]
For the pattern "ABCDE":
lps[] = [0,0,0,0,0]
For the pattern "AABAACAABAA":
lps[] = [0,1,0,1,2,0,1,2,3,4,5]

Searching Algorithm:
Unlike Naive algorithm, where we slide the pattern by one and compare all the characters at each shift, we use a value from lps[] to 
decide the next characters to be matched. The idea is not to match a character that we know will anyways match.
How to use lps[] to calculate next positions:
1. We start comparisons of pat[j] with j=0 with characters of current window of text.
2. We keep matching characters txt[i] and pat[j] and keep incrementing i and j while pat[j] and txt[i] keep on matching.
3. When we see a mismatch
	a. We know that characters pat[0..j-1] match with txt[i-j ... i-1]( Note that j starts with 0 and increment it only when there is 
	a match)
	b. We also know (from above definition) that lps[j-1] is a count of characters of pat[0...j-1] that are both prefix and suffix.
	c. From above two points, we can conclude that we do not need to match these lps[j-1] with characters with txt[i-j ... i-1]
	because we know already that they will match.

Example to show how the KMP Algorithm works
txt[] = "AAAAABAAABA"
pat[] = "AAAA"
lps[] = {0,1,2,3}

i=0, j=0
txt[] = "'A'AAAABAAABA"
pat[] = "'A'AAA"
txt[i] and pat[j] match so i++, j++

i=1, j=1
txt[] = "A'A'AAABAAABA"
pat[] = "A'A'AA"
txt[i] and pat[j] match so i++, j++;

i=2, j=2
txt[] = "AA'A'AABAAABA"
pat[] = "AA'A'A"
txt[i] and pat[j] match so i++, j++;

i=3, j=3
txt[] = "AAA'A'ABAAABA"
pat[] = "AAA'A'"
txt[i] and pat[j] match so i++, j++;

i=4, j=4
Since j==M, print pattern found and reset j,
j = lps[j-1] = lps[3] = 3

Here unlike Naive algorithm, we donot match first three characters of the window. Value of lps[j-1] (in above step) gave us index
of next character to match

i=4, j=3
txt[] = "AAAA'A'BAAABA"
pat[] = "AAA'A'"
txt[i] and pat[j] match, so i++, j++;

i=5, j=4
Since j == M, print pattern found and reset j
j = lps[j-1] = lps[3] = 3

i=5, j=3
txt[] = "AAAAA'B'AAABA"
pat[] = "AAA'A'"
txt[i] and pat[j] mismatch. so change only j as j>0
therefore j = lps[j-1] = lps[2] = 2

i=5, j=2
txt[] = "AAAAA'B'AAABA"
pat[] = "AA'A'A"
txt[i] and pat[j] mismatch, so change only j 
j = lps[j-1] = lps[1] = 1

i=5, j=1
txt[] = "AAAAA'B'AAABA"
pat[] = "A'A'AA"
txt[i] and pat[j] mismatch, so change only j
j = lps[j-1] = lps[0] = 0

i=5, j=0
txt[] = "AAAAA'B'AAABA"
pat[] = "'A'AAA"
txt[i] and pat[j] mismatch, as j == 0  thus i++

i=6, j=0
txt[] = "AAAAAB'A'AABA"
pat[] = "'A'AAA"
txt[i] and pat[j] match , so i++, j++

i=7, j=1
txt[] = "AAAAABA'A'ABA"
pat[] = "A'A'AA"
txt[i] and pat[j] match, so i++, j++

i=8, j=2
txt[] = "AAAAABAA'A'BA"
pat[] = "AA'A'A"
txt[i] and pat[j] match so i++, j++;

AND SO ON.....

PREPROCESSING ALGORITHM

pat[] = "AAACAAAA"

len = 0, i = 0;
lps[0] = 0 , i = 1

len = 0, i = 1;
Since pat[len] and pat[i] match do len++;
lps[i] = len => lps[1] = 1; and do i++
len  = 1, lps[1] = 1, i = 2;

len = 1, i = 2;
Since pat[len] and pat[i] match do len++;
len = 2, lps[2] = 2, i = 3;

len = 2, i = 3;
pat[len] != pat[i]
len!=0 => len = lps[len-1] = lps[1] = 1, i=3 

len = 1 , i = 3;
pat[len] != pat[i]
len!=0 => len = lps[len-1] = lps[0] = 0, i=3

len = 0 , i = 3
pat[len] != pat[i]
len = 0 ,lps[3] = 0, i=4

len = 0, i = 4
pat[len] = pat[i]
len = 1, lps[4] = 1, i=5

len = 1, i = 5
pat[len] = pat[i]
len = 2, lps[5] = 2, i = 6

len = 2, i = 6
pat[len] = pat[i]
len = 3, lps[6] = 3, i = 7,

len = 3, i = 7
pat[len] != pat[i]
len = lps[len-1] = lps[2] = 2

len = 2, i = 7
pat[len] = pat[i],
len = 3, lps[7] = 3, i = 8
*/

#include<bits/stdc++.h>
using namespace std;

void computeLPSArray(char* pat,int M,int* lps);

void KMPSearch(char* pat, char* txt)
{
	int M = strlen(pat);
	int N = strlen(txt);
	int lps[M];
	computeLPSArray(pat,M,lps);
	
	int i = 0;
	int j = 0;
	while(i < N)
	{
		if(pat[j] == txt[i]){
			i++;
			j++;
		}
		if(j == M){
			printf("Found at the index %d", i - j);
			j = lps[j-1];
		}
		else if(i<N && pat[j]!=txt[i]){
			if(j!=0){
				j = lps[j-1];
			}
			else{
				i = i + 1;
			}
		}
	}
}
void computeLPSArray(char* pat, int M, int* lps)
{
	int len = 0;
	lps[0] = 0;
	int i = 1;
	while(i < M){
		if(pat[i] == pat[len]){
			len++;
			lps[i] = len;
			i++;
		}
		else{
			if(len!=0){
				len = lps[len-1];
			}
			else{
				lps[i] = 0;
				i++;
			}
		}
	}
}

int main() 
{ 
    char txt[] = "ABABDABACDABABCABAB"; 
    char pat[] = "ABABCABAB"; 
    KMPSearch(pat, txt); 
    return 0; 
} 
			
		
			




