// https://cses.fi/problemset/task/1646
#include<bits/stdc++.h>
using namespace std;

const int maxN = 2e5 + 100;
int n, q;
int x[maxN];
long long qs[maxN];

// O(n+q)
int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> n >> q;

    // O(n)
    for(int i = 1; i <= n; ++i){
        cin >> x[i];
    }

    // O(n)
    for(int i = 1; i <= n; ++i){
        qs[i] = qs[i-1] + x[i];
    }

    // O(q)
    for(int i = 1; i <= q; ++i){
        int l, r;
        cin >> l >> r;
        cout << qs[r] - qs[l-1] << '\n';
    }
}