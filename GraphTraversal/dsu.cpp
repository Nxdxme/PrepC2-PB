#include<bits/stdc++.h>
using namespace std;

const int maxN = 2e5 + 7;
int n, compo;
int par[maxN];

int fi(int u){
    if(par[u] == u) return u;
    return fi(par[u]);
}

bool merge(int u, int v){
    int hu = fi(u);
    int hv = fi(v);
    if(hu == hv) return false;
    par[hv] = hu;
    return true;
}

int main(){
    for(int i = 1; i <= n; ++i)
        par[i] = i;
    compo = n;
}