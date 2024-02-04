// toi11_candle
// https://programming.in.th/tasks/toi11_candle
#include<bits/stdc++.h>
using namespace std;

int m, n, ans;
string grid[2000];
bitset<2000> vi[2000];

void dfs(int x, int y){
    if(x < 0 or x >= n or y < 0 or y >= m) return;
    if(grid[x][y] == '0') return;
    if(vi[x][y]) return;
    vi[x][y] = true;
    dfs(x-1, y-1);  dfs(x-1, y);    dfs(x-1, y+1);
    dfs(x, y-1);                    dfs(x, y+1);
    dfs(x+1, y-1);  dfs(x+1, y);    dfs(x+1, y+1);
}

int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> n >> m;
    for(int i = 0; i < n; ++i)
        cin >> grid[i];
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            if(vi[i][j]) continue;
            if(grid[i][j] == '0') continue;
            ++ans;
            dfs(i, j);
        }
    }
    cout << ans << '\n';
}
/*
4 5 10011 00001 01100 10011*/