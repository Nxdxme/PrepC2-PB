// MaximumSubarraySum
// https://cses.fi/problemset/task/1643
#include<bits/stdc++.h>
using namespace std;

const int maxN = 2e5 + 1;
long long x[maxN], dp[maxN], ans, lessmin = -1e9;
int n;

int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> n;
    for(int i = 1; i <= n; ++ i)
        cin >> x[i];
    for(int i = 1; i <= n; ++i){
        dp[i] = max(dp[i-1] + x[i], 0ll);
        ans = max(ans, dp[i]);
        lessmin = max(lessmin, x[i]);
    }
    if(ans == 0){
        cout << lessmin << '\n';
    }else cout << ans << '\n';
}