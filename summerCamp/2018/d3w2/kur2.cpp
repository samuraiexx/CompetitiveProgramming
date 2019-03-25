#include<bits/stdc++.h>
using namespace std;

const int N = 5e5 + 5;

int v[N];
int st[4*N];
pair<int, int> vp[N];
int n, m;

int amt(int x, int l, int r){
    return upper_bound(vp, vp + n, make_pair(x, r)) - 
           lower_bound(vp, vp + n, make_pair(x, l));
}

void build(int n, int l, int r){
    if(l == r) { st[n] = v[l]; return; }
    int mid = (l + r)/2;
    build(2*n, l, mid), build(2*n + 1, mid + 1, r);

    int x = st[2*n] ? amt(st[2*n], l, r) : 0;
    int y = st[2*n + 1] ? amt(st[2*n + 1], l, r) : 0;
    if(max(x, y)*2 > (r - l + 1))
        st[n] = x > y ? st[2*n] : st[2*n + 1];
}

int query(int n, int l, int r, int i, int j){
    if(r < i or l > j) return 0;
    if(i <= l and r <= j) return st[n];

    int mid = (l + r)/2;

    int e1 = query(2*n, l, mid, i, j),
        e2 = query(2*n + 1, mid + 1, r, i, j);

    int x = e1 ? amt(e1, i, j) : 0;
    int y = e2 ? amt(e2, i, j) : 0;

    if(max(x, y)*2 > (j - i + 1))
        return x > y ? e1 : e2;
    return 0;
}

int main(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> v[i], vp[i - 1] = {v[i], i};
    sort(vp, vp+n);
    build(1, 1, n);

    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        cout << query(1, 1, n, a, b) << endl;
    }
    return 0;
}
