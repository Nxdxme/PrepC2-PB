// FrogI
// https://atcoder.jp/contests/dp/tasks/dp_a
#include<bits/stdc++.h>
using namespace std;

const int maxN = 1e5 + 1;
int n;
int h[maxN], dp[maxN];

int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> n;
    for(int i = 1; i <= n; ++i)
        cin >> h[i];
    dp[1] = 0;
    dp[2] = dp[1] + abs(h[2]-h[1]);
    for(int i = 3; i <= n; ++i){
        dp[i] = min(dp[i-1] + abs(h[i]-h[i-1]),
                    dp[i-2] + abs(h[i]-h[i-2]));
    }
    cout << dp[n] << '\n';
}