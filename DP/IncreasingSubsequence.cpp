// Increasing Subsequence
// https://cses.fi/problemset/task/1145
#include<bits/stdc++.h>
using namespace std;

const int maxN = 1e5 + 1;
int n, x;
vector<int> dp;

int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> n;
    for(int i = 1; i <= n; ++i){
        cin >> x;
        auto itr = lower_bound(dp.begin(), dp.end(), x);
        if(itr == dp.end()) dp.push_back(x);
        else *itr = x;
    }
    cout << dp.size() << '\n';
}