// ShortestRouteI
// https://cses.fi/problemset/task/1671
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxN = 1e5 + 7;
int n, m;
ll dist[maxN];
vector<pair<int, int>> g[maxN];
bool vi[maxN];
priority_queue<pair<ll, int>> pq;

int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> n >> m;
    for(int i = 1; i <= m; ++i){
        int a, b, c;
        cin >> a >> b >> c;
        g[a].push_back({b, c});
    }
    for(int i = 1; i <= n; ++i)
        dist[i] = 1e18;
    pq.push({0, 1});
    dist[1] = 0;
    while(not pq.empty()){
        auto [_, u] = pq.top();
        pq.pop();
        if(vi[u]) continue;
        vi[u] = true;
        for(auto [v, w] : g[u]){
            if(dist[v] > dist[u]+w){
                dist[v] = dist[u]+w;
                pq.push({-dist[v], v});
            }
        }
    }
    for(int i = 1; i <= n; ++i)
        cout << dist[i] << ' ';
    cout << '\n';
}