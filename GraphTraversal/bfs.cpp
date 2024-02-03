#include<bits/stdc++.h>
using namespace std;

const int maxN = 1e5 + 7;
vector<int> g[maxN];
bool vi[maxN] = {false};
    
void bfs(int st){
    queue<int> q;
    q.push(st);
    while(not q.empty()){
        int u = q.front();
        q.pop();
        if(vi[u]) continue;
        vi[u] = true;
        // do sth.
        for(int v : g[u]){
            q.push(v);
        }
    }
}

int main(){

}