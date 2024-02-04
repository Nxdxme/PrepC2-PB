// KnapsackI
// https://atcoder.jp/contests/dp/tasks/dp_d
#include<bits/stdc++.h>
using namespace std;

const int maxW = 1e5 + 1;
int N, W;
int w[101], v[101];
long long dp[101][maxW];

int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> N >> W;
    for(int i = 1; i <= N; ++i)
        cin >> w[i] >> v[i];
    for(int i = 1; i <= N; ++i){
        for(int j = 0; j <= W; ++j){
            if(j-w[i] >= 0)
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-w[i]] + v[i]);
            else dp[i][j] = dp[i-1][j];
        }
    }
    cout << dp[N][W] << '\n';
}