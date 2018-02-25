#include <bits/stdc++.h>
using namespace std;

const int N = 5e5+5, INF = 0x3f3f3f3f, MOD = 1e9+7;

int v[N];
int st[4*N];
pair<int, int> amt[N];
int n, m;

bool search(int x, int y, int i, int j){
    int xa = upper_bound(amt, amt+n, make_pair(x, j)) - 
        lower_bound(amt, amt+n, make_pair(x, i));
    int ya = upper_bound(amt, amt+n, make_pair(y, j)) - 
        lower_bound(amt, amt+n, make_pair(y, i));

    return xa > ya;
}

void build(int n, int l, int r){
    if(l == r) { st[n] = v[l]; return; }
    int mid = (l + r)/2;
    build(2*n, l, mid), build(2*n + 1, mid + 1, r);

    st[n] = search(st[2*n], st[2*n + 1], l, r) ? st[2*n] : st[2*n + 1];
}

int query(int n, int l, int r, int i, int j){
    if(r < i or l > j) return -1;
    if(l >= i and r <= j) return st[n];

    int mid = (l+r)/2;
    int x = query(2*n, l, mid, i, j);
    int y = query(2*n + 1, mid + 1, r, i, j);

    return search(x, y, l, r) ? x : y;
}

int main() {
    cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> v[i], amt[i] = {v[i], i};
    sort(amt, amt + n);

    build(1, 0, n - 1);

    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        a--, b--;
        int x = query(1, 0, n - 1, a, b);
        int sz = upper_bound(amt, amt+n, make_pair(x, b)) - 
            lower_bound(amt, amt+n, make_pair(x, a));
        if(x == -1) cout << 0 << endl;
        else cout << (2*sz > (b - a + 1) ? x : 0) << endl;
    }
    return 0;
}
