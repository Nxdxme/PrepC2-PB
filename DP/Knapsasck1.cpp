// KnapsackI
// https://atcoder.jp/contests/dp/tasks/dp_d
#include<bits/stdc++.h>
using namespace std;

int n, maxW, w, v, ans;
long long dp[107][100007];

int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> n >> maxW;
    for(int i = 1; i <= n; ++i){
        cin >> w >> v;
        for(int j = 0; j <= maxW; ++j){
            if(j-w <= maxW and j-w >= 0)
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-w] + v);
            else dp[i][j] = dp[i-1][j];
        }
    }
    cout << dp[n][maxW] << '\n';
}