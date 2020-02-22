#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long int

ull power(int exponent)
{
    ull res = 1;
    ull base = 10;
    while(exponent>0)
    {
        if(exponent%2!=0)
        {
            res = res * base;
        }
        base *= base;
        exponent/=2;
    }
    return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
    int n;
    ull a,b,d;
    ull s;
    int res;
    cin >> t;
    while(t--)
    {
        cin >> n;
        s = power(n);
        cin >> a;
        cout << 2*s + a << endl;
        cin >> b;
        cout << s - b << endl;
        cin >> d;
        cout << s - d << endl;
        cin >> res;
        if(res == -1)
            return 1;
    }
    return 0;
}
