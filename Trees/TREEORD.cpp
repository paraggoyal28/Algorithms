#include <bits/stdc++.h>
using namespace std;
vector<int> post;
int search(int arr[], int x, int n)
{
    for (int i = 0; i < n; i++)  if (arr[i] == x)  return i;  return -1; }
 
void calcPostOrder(int in[], int pre[],  int n)
{
   int root = search(in, pre[0], n);

    if (root != 0)
        calcPostOrder(in, pre+1, root);

    if (root != n-1)
        calcPostOrder(in+root+1, pre+root+1,  n-root-1);
    
   	post.push_back(pre[0]);     
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int N;
    cin>>N;
    int preorder[N],postorder[N],inorder[N];
	for(int j=0;j<N;j++)
    {
        cin>>preorder[j];
    }
    for(int j=0;j<N; j++)
    {
        cin>>postorder[j];
    }
    for(int j=0;j<N;j++)
    {
        cin>>inorder[j];
    }
    calcPostOrder(inorder,preorder,N);
    for(int j=0;j<N;j++)
    {
        if(post[j] != postorder[j])
        {
            
            cout<< "no" <<endl;
            return 0;
        }
    }
    cout<<"yes"<<endl;
    return 0;
}