#include<bits/stdc++.h>
using namespace std;

const int maxN = 1007;
int n, m;
int grid[maxN][maxN];
bool vi[maxN][maxN] = {false};

void flood_fill(int i, int j){
    if(i < 0 or i >= n or j < 0 or j >= m) return;
    if(vi[i][j]) return;
    vi[i][j] = true;
    // do sth.
    flood_fill(i+1, j);
    flood_fill(i-1, j);
    flood_fill(i, j+1);
    flood_fill(i, j-1);
}

int main(){

}