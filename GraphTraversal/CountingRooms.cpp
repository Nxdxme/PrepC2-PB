// https://cses.fi/problemset/task/1192
#include<bits/stdc++.h>
using namespace std;

const int maxN = 1005;
int n, m, ans;
int mp[maxN][maxN];
bool vi[maxN][maxN];

int main(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        string s;
        cin >> s;
        for(int j = 1; j <= m; j++){
            mp[i][j] = s[j-1];
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(!vi[i][j] && mp[i][j] == '.'){
                ans++;
                queue<pair<int, int>> q;
                q.push({i, j});
                vi[i][j] = true;
                while(!q.empty()){
                    int x = q.front().first, y = q.front().second;
                    q.pop();
                    if(!vi[x-1][y] && mp[x-1][y] == '.'){
                        q.push({x-1, y});
                        vi[x-1][y] = true;
                    }
                    if(!vi[x+1][y] && mp[x+1][y] == '.'){
                        q.push({x+1, y});
                        vi[x+1][y] = true;
                    }
                    if(!vi[x][y-1] && mp[x][y-1] == '.'){
                        q.push({x, y-1});
                        vi[x][y-1] = true;
                    }
                    if(!vi[x][y+1] && mp[x][y+1] == '.'){
                        q.push({x, y+1});
                        vi[x][y+1] = true;
                    }
                }
            }
        }
    }
    cout << ans;
}