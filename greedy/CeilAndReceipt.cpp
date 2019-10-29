#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long int
#define ll long long int
ll pos_int,bit,remain,test_cases;
int main(){
    ll count;
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>test_cases;
    while(test_cases --)
    {
        count = 0;
        cin>>pos_int;
        remain = pos_int%2048;
        count += pos_int/2048-(pos_int/2048)%1;
        for(bit=10; bit>=0;bit--)
        {
            if(remain & (1<<bit))
            {
                count++;
            }
        }
        cout<<count<<endl;
    }
    return 0;
}
