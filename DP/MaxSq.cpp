#include<bits/stdc++.h>
using namespace std;

int a[2505], dp[2505], st[2505];
int n, maxans, maxidx, endidx;

int main(){
    cin >> n;
    for(int i = 1; i <= n; ++i){
        cin >> a[i];
    }
    for(int i = 1; i <= n; ++i){
        dp[i] = max(dp[i-1]+a[i], 0);
        if(dp[i-1]+a[i]>0){
            st[i] = st[i-1];
            dp[i] = dp[i-1]+a[i];
        }else{
            st[i] = i+1;
            dp[i] = 0;
        }
        if(dp[i] > maxans){
            maxans = dp[i];
            maxidx = st[i];
            endidx = i;
        }
    }
    if(maxans == 0){
        cout << "Empty Sequence\n";
    }else{
        cout << a[maxidx];
        for(int i = maxidx+1; i <= endidx; ++i)
            cout << ' ' << a[i];
        cout << '\n' << maxans << '\n';
    }
}