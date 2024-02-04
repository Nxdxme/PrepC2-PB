// LIS O(nlogn)
#include<bits/stdc++.h>
using namespace std;

const int maxN = 1e5;
int n, a;
vector<int> dp;

int main(){
    cin.tie(nullptr)->sync_with_stdio(false);  
    cin >> n;
    for(int i = 1; i <= n; ++i){
        cin >> a;
        vector<int>::iterator itr = lower_bound(dp.begin(), dp.end(), a);
        if(itr == dp.end()) dp.push_back(a);
        else *itr = a;
    }
    cout << dp.size() << '\n';
}