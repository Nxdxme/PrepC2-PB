// Dice Combination
// https://cses.fi/problemset/task/1633
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll MOD = 1e9 + 7;
const int maxN = 1e6 + 1;
ll dp[maxN];
int n;

int main(){
    cin >> n;
    dp[0] = 1;
    for(int i = 1; i <= n; ++i){
        ll sm = 0;
        for(int j = 1; j <= 6; ++j){
            if(i-j < 0) continue;
            sm += dp[i-j];
            sm %= MOD;
        }
        dp[i] += sm;
        dp[i] %= MOD;
    }
    cout << dp[n] << '\n';
}