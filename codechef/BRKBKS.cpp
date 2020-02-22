#include<bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int test, s, w1, w2, w3;
    cin >> test;
    while(test--)
    {
        cin >> s;
        int dummy = s;
        cin >> w1 >> w2 >> w3;    
        if(w1 + w2 + w3  <= s)
        {
            cout << 1 << endl;
        }
        else if(w1 + w2 <= s) 
        {
            cout << 2  << endl;
        }
        else if(w2 + w3 <= s) 
        {
            cout << 2 << endl;
        }
        else
        {
            cout << 3 << endl;
        }
        
            
    }
	return 0;
}
