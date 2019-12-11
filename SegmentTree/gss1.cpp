#include<vector>
#include<algorithm>
#include<cstdio>
using namespace std;
int a[50000];
int sum[200000];
int maxlsum[200000];
int maxrsum[200000];
int maxisum[200000];
int N, M;
void update(int node)
{
    sum[node] = sum[2*node] + sum[2*node+1];
    maxlsum[node] = max(maxlsum[2*node],sum[2*node] + maxlsum[2*node+1]);
    maxrsum[node] = max(maxrsum[2*node+1], sum[2*node+1] + maxrsum[2*node]);
    maxisum[node] = 
}