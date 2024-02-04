// FrogII
// https://atcoder.jp/contests/dp/tasks/dp_b
#include<bits/stdc++.h>
using namespace std;

const int maxN = 1e5 + 1;
int n, k;
int dp[maxN], h[maxN];

int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> n >> k;
    for(int i = 1; i <= n; ++i)
        dp[i] = 1e9;
    for(int i = 1; i <= n; ++i)
        cin >> h[i];
    dp[1] = 0;
    for(int i = 2; i <= n; ++i){
        for(int j = 1; j <= k; ++j){
            if(i-j <= 0) continue; 
            dp[i] = min(dp[i], dp[i-j] + abs(h[i] - h[i-j]));
        }
    }
    cout << dp[n] << '\n';
}