#include<bits/stdc++.h>
using namespace std;

const int maxN = 1050;
int n, m;
vector<int> g[maxN];
bool vi[maxN] = {false};
 
void dfs(int u){
    if(vi[u]) return;
    vi[u] = true;
    // do sth.
    for(int v : g[u]){
        dfs(v);
        // do sth.
    }
}

int main(){
    cin >> n >> m;
    for(int i = 1; i <= n; ++i){
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
    }
    dfs(1);
}