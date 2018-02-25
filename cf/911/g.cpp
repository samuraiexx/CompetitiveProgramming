#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
char st[4*N][100];
bool lz[4*N];
int v[N];

void build(int n, int l, int r){
    for(int i = 1; i <= 100; i++) st[n][i] = i;
    int mid = (l + r)/2;
    if(l != r) build(2*n, l, mid), build(2*n + 1, mid + 1, r);
}

void push(int n, int l, int r){
    if(!lz[n] or l == r) return;
    for(int i = 1; i <= 100; i++)
        st[2*n][i] = st[n][st[2*n][i]],
        st[2*n + 1][i] = st[n][st[2*n + 1][i]];
    lz[2*n] = lz[2*n + 1] = 1;

    for(int i = 1; i <= 100; i++)
        st[n][i] = i;
    lz[n] = 0;
}

void update(int n, int l, int r, int i, int j, int x, int y){
    if(i > r or j < l) return;
    if(l >= i and r <= j) {
        for(int i = 1; i <= 100; i++)
            if(st[n][i] == x) st[n][i] = y;
        lz[n] = true;
        return; 
    }
    push(n, l, r);
    int mid = (l + r)/2;
    update(2*n, l, mid, i, j, x, y);
    update(2*n + 1, mid + 1, r, i, j, x, y);
}

void print(int n, int l, int r){
    push(n, l, r);
    int mid = (l + r)/2;
    if(l == r) cout << (int)st[n][v[l]] << ' ';
    else print(2*n, l, mid), print(2*n + 1, mid + 1, r);
}

int main(){
    int n, q;
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> v[i];
    build(1, 1, n);
    cin >> q;
    for(int i = 0; i < q; i++){
        int l, r, x, y;
        cin >> l >> r >> x >> y;
        update(1, 1, n, l, r, x, y);
    }

    print(1, 1, n);
    cout << endl;
    return 0;
}
