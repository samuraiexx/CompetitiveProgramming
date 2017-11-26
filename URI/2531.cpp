#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int n;
int st[2][4*N];
int v[N];

void build(int n, int l, int r){
    if(l == r) st[0][n] = st[1][n] = v[l];
    int mid = (l + r)/2;
    build(2*n, l, mid);
    build(2*n + 1, mid + 1, r);
    st[0][n] = min(st[0][2*n], st[0][2*n + 1]);
    st[1][n] = max(st[1][2*n], st[1][2*n + 1]);
}

pair<int, int> query(int n, int l, int r, int i, int j){
    if(l > i and r < j) return { st[0][n], st[1][n] }
    if(r < i or l > j) return { 1e9, 0 }

}


int main(){
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> v[i];
    for(int i = 1; i < 4*N; i++) st[i][0] = 1e9;

    build(1, 1, n);
}
