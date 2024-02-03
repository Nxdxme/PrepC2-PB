#include<bits/stdc++.h>
using namespace std;

int a[1000005];

void merge(int l, int r) {
    int mid = (l + r) / 2;
    int i = l, j = mid + 1, k = 0;
    int tmp[r - l + 1];
    while(i <= mid and j <= r) {
        if(a[i] <= a[j]) tmp[k++] = a[i++];
        else tmp[k++] = a[j++];
    }
    while(i <= mid) tmp[k++] = a[i++];
    while(j <= r) tmp[k++] = a[j++];
    for(int i = l; i <= r; ++i) a[i] = tmp[i - l];
    
}

void mergeSort(int l, int r) {
    if(l == r) return;
    int mid = (l + r) / 2;
    mergeSort(l, mid);
    mergeSort(mid + 1, r);
    merge(l, r);
}

int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int n;
    cin >> n;
    for(int i = 0; i < n; ++i) cin >> a[i];
    mergeSort(0, n - 1);
    for(int i = 0; i < n; ++i) cout << a[i] << " ";
}