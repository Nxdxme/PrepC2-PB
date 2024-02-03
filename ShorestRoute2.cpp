// ShortestRouteII
// https://cses.fi/problemset/task/1672
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

// O(n^3)
const int maxN = 507;
int n, m, q;
ll dist[maxN][maxN];

int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> n >> m >> q;
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= n; ++j){
            dist[i][j] = 1e18;
        }
    }
    for(int i = 1; i <= n; ++i)
        dist[i][i] = 0;
    for(int i = 1; i <= m; ++i){
        int a, b, c;
        cin >> a >> b >> c;
        dist[a][b] = min(dist[a][b], 1ll*c);
        dist[b][a] = min(dist[b][a], 1ll*c);
    }
    // O(n^3)
    for(int k = 1; k <= n; ++k){
        for(int i = 1; i <= n; ++i){
            for(int j = 1; j <= n; ++j){
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    for(int i = 1; i <= q; ++i){
        int a, b;
        cin >> a >> b;
        if(dist[a][b] == 1e18){
            cout << "-1\n";
        }else cout << dist[a][b] << '\n';
    }
}