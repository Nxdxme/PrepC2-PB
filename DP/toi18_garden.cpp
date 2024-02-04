#include<bits/stdc++.h>
using namespace std;

const int maxN = 200001;
int n, q, x;
int h[maxN], l[maxN], r[maxN], k[maxN];
vector<int> dp;

int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> n >> q;
    for(int i = 0; i < n; ++i){
        cin >> h[i];
    }
    for(int i = 0; i < n; ++i){
        auto itr = lower_bound(dp.begin(), dp.end(), h[i]);
        l[i] = itr - dp.begin();
        if(itr == dp.end()) dp.push_back(h[i]);
        else *itr = h[i];
    }
    dp.clear();
    for(int i = n-1; i >= 0; --i){
        auto itr = lower_bound(dp.begin(), dp.end(), h[i]);
        r[i] = itr - dp.begin();
        if(itr == dp.end()) dp.push_back(h[i]);
        else *itr = h[i];
    }
    for(int i = 0; i < n; ++i){
        k[i] = min(l[i], r[i]);
    }
    for(int i = 0; i < q; ++i){
        cin >> x;
        cout << k[x] << '\n';
    }
}
/*
10 4
2 4 6 8 10 9 7 5 3 1
9 4 0 3
*/