// CountingRoom
// https://cses.fi/problemset/task/1192
#include<bits/stdc++.h>
using namespace std;

int n, m, noRoom;
string grid[1007];
bool vi[1007][1007] = {false};

void bfs(int initi, int initj){
    queue<pair<int, int>> q;
    q.push({initi, initj});
    while(not q.empty()){
        auto [i, j] = q.front();
        q.pop();
        if(i < 0 or i >= n or j < 0 or j >= m) continue;
        if(grid[i][j] == '#') continue;
        if(vi[i][j]) continue;
        vi[i][j] = true;
        q.push({i+1, j});
        q.push({i-1, j});
        q.push({i, j+1});
        q.push({i, j-1});
    }
}

int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> n >> m;
    for(int i = 0; i < n; ++i)
        cin >> grid[i];
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            if(grid[i][j] == '#') continue;
            if(vi[i][j]) continue;
            ++noRoom;
            bfs(i, j);
        }
    }
    cout << noRoom << '\n';
}