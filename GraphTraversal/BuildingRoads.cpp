// BuildingRoads
// https://cses.fi/problemset/task/1666
#include<bits/stdc++.h>
using namespace std;

const int maxN = 1e5 + 7;
int n, m;
vector<int> rep;
vector<int> g[maxN];
bool vi[maxN];

void dfs(int u){
    if(vi[u]) return;
    vi[u] = true;
    for(int v : g[u])
        dfs(v);
}

int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> n >> m;
    for(int i = 1; i <= m; ++i){
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    for(int i = 1; i <= n; ++i){
        if(not vi[i]){
            rep.push_back(i);
        }
        dfs(i);
    }
    cout << rep.size()-1 << '\n';
    for(int i = 1; i < rep.size(); ++i){
        cout << rep[0] << ' ' << rep[i] << '\n';
    }
}