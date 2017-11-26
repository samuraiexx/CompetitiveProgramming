#include <bits/stdc++.h> 
using namespace std; const int N = 3e4 + 5;

int nxt = 1;
vector<int> root;
vector<int> version;
int lastseen[1000005];
int lf[32*N], rt[32*N];
int v[32*N];

int query(int n, int l, int r, int i, int j){
    if(r < i or l > j) return 0;
    if(l >= i and r <= j) return v[n];
    int mid = (l + r)/2;
    return query(lf[n], l, mid, i, j) + query(rt[n], mid + 1, r, i, j);
}

int update(int n, int l, int r, int x, int val){
    int node = nxt++;
    if(l == r){ v[node] = val; return node; }
    int mid = (l + r)/2;
    if(x <= mid) rt[node] = rt[n], lf[node] = update(lf[n], l, mid, x, val);
    else lf[node] = lf[n], rt[node] = update(rt[n], mid + 1, r, x, val);
    v[node] = v[lf[node]] + v[rt[node]];
    return node;
}

int main(){
    int n;
    cin >> n;
    root.push_back(0);
    for(int i = 1; i <= n; i++){
        int a;
        scanf("%d", &a);
        if(lastseen[a]) root.push_back(update(root.back(), 1, n, lastseen[a], 0));
        root.push_back(update(root.back(), 1, n, i, 1));
        lastseen[a] = i;
        version.push_back(root.back());
    }

    int q;
    cin >> q;
    for(int x = 0; x < q; x++){
        int i, j;
        cin >> i >> j;
        cout << query(version[j - 1], 1, n, i, n) << '\n';
    }
}
