#include<bits/stdc++.h>
using namespace std;

const int maxN = 1007;
int n, m;
int grid[maxN][maxN];
bool vi[maxN][maxN] = {false};

void floodfill(int x, int y){
    queue<pair<int, int>> q;
    q.push({x, y});
    while(not q.empty()){
        auto u = q.front();
        q.pop();
        if(u.first < 0 or u.first >= n or u.second < 0 or u.second >= m) continue;
        vi[u.first][u.second] = true;
        floodfill(u.first+1, u.second);
        floodfill(u.first-1, u.second);
        floodfill(u.first, u.second+1);
        floodfill(u.first, u.second-1);
    }
}

int main(){

}