#include<bits/stdc++.h>
using namespace std;

const int maxN = 1e5 + 7;
int n, m, compo;
long long cost;
vector<tuple<int, int, int>> edges;
int par[maxN];

int fi(int u){
    if(par[u] == u) return u;
    return par[u] = fi(par[u]);
}

bool merge(int u, int v){
    int hu = fi(u), hv = fi(v);
    if(hu == hv) return false;
    par[hv] = hu;
    return true;
}

int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> n >> m;
    compo = n;
    for(int i = 1; i <= n; ++i)
        par[i] = i;
    for(int i = 1; i <= m; ++i){
        int a, b, c;
        cin >> a >> b >> c;
        edges.push_back({c, a, b});
    }
    sort(edges.begin(), edges.end());
    for(auto [c, a, b] : edges){
        if(merge(a, b)){
            --compo;
            cost += c;
        }
    }
    if(compo > 1){
        cout << "IMPOSSIBLE\n";
    }else cout << cost << '\n';
}