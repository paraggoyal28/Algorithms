#include <cstdio>
#include <cassert>
#include <cmath>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <functional>
#include <stack>
#include <queue>
#include <tuple>
// #define getchar getchar_unlocked
// #define putchar putchar_unlocked
#define _rep(_1, _2, _3, _4, name, ...) name
#define rep2(i, n) rep3(i, 0, n)
#define rep3(i, a, b) rep4(i, a, b, 1)
#define rep4(i, a, b, c) for(int i = int(a);i < int(b); i += int(c))
#define rep(...) _rep(__VA_ARGS__, rep4, rep3, rep2, _) (__VA_ARGS__)
using namespace std;
using i64 = long long;
using u8 = unsigned char;
using u32 = unsigned;
using u64 = unsigned long long;
using f80 = long double;

int get_int(){
    int c, n;
    while ((c = getchar()) < '0');
    n = c - '0';
    while ((c = getchar()) >= '0') n = n * 10 + (c - '0');
    return n;
}

void solve(){
    int T;
    scanf("%d", &T);
    rep(_,T)
    {
        int N = get_int(), D = get_int();
        vector< pair<int, int> > dat(N);
        vector< pair<int, int> > arrival(N);
        rep(i,N){
            int d = get_int(), t = get_int(), s = get_int();
            dat[i] = {t, s};
            arrival[i] = {d, i};
        }
        sort(arrival.begin(),arrival.end());
        using P = pair<int, int>;
        priority_queue<P, vector<P>> que;
        int ai = 0;
        rep(day, 1, D + 1){
            for(; ai < N && arrival[ai].first == day; ++ai)
            {
                int i = arrival[ai].second;
                que.push({dat[i].second,i});
            }
            if(!que.empty()){
                int s, i; tie(s, i) = que.top();
                dat[i].first -= 1;
                if(dat[i].first == 0) que.pop();
            }
        }
        i64 ans = 0;
        rep(i, N) ans += i64(dat[i].first)*dat[i].second;
        printf("%lld\n", ans);
    }
}

int main(){
    clock_t beg = clock();
    solve();
    clock_t end = clock();
    fprintf(stderr, "%.3f sec\n",double(end - beg)/ CLOCKS_PER_SEC);
    return 0;
}