// RoadConstruction
// https://cses.fi/problemset/task/1676
#include<bits/stdc++.h>
using namespace std;

const int maxN = 1e5 + 7;
int par[maxN], sz[maxN], n, m, compo, maxcompo;

int fi(int u){
    return par[u] = (par[u] == u) ? u : fi(par[u]);
}

bool merge(int u, int v){
    int hu = fi(u), hv = fi(v);
    if(hu == hv) return false;
    par[hv] = hu;
    sz[hu] += sz[hv];
    return true;
}

int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> n >> m;
    compo = n;
    for(int i = 1; i <= n; ++i){
        par[i] = i;
        sz[i] = 1;
    }
    for(int i = 1; i <= m; ++i){
        int u, v;
        cin >> u >> v;
        if(merge(u, v)){
            --compo;
        }
        maxcompo = max(maxcompo, sz[fi(u)]);
        cout << compo << ' ' << maxcompo << '\n';
    }
}