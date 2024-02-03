// https://programming.in.th/tasks/codecube_128
#include<bits/stdc++.h>
using namespace std;

const int maxN = 1e6 + 10;
int n, mx;
int dp[maxN], h[maxN];

int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> n;
    for(int i = 1; i <= n; ++i){
        cin >> h[i];
    }
    for(int i = n; i > 0; --i){
        dp[i] = max(dp[i+1], h[i]);
    }
    for(int i = 1; i < n; ++i){
        mx = max(mx, h[i]);
        cout << min(dp[i+1], mx) << ' ';
        // cout << dp[i] << ' ';
        // cout << mx << '\n';
    }

    cout << '\n';
}
/*
9
1 2 5 2 3 2 4 3 2
*/