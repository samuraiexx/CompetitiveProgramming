#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define vii vector<pair<int, int>>
const int N = 1e5 + 1;
const int INF = 0x3f3f3f3f;

vector<int> adj[N];
int val[N];
vector<int> tree;
pair<int, int> treePos[N];
vector<pair<int, int>> st[4*N];
int dep[N];

void merge(vii &u1, vii &u2, vii &v){
    int i = 0, j = 0, mn = INF;
    while(i < u1.size() or j < u2.size()){
        int lv;
        if(i == u1.size())
            lv = u2[j].first, mn = min(mn, u2[j++].second);
        else if(j == u2.size())
            lv = u1[i].first, mn = min(mn, u1[i++].second);
        else if(u1[i].first < u2[j].first)
            lv = u1[i].first,
            mn = min(mn, u1[i++].second);
        else if(u1[i].first > u2[j].first)
            lv = u2[j].first,
            mn = min(mn, u2[j++].second);
        else
            lv = u1[i].first,
            mn = min({mn, u1[i++].second, u2[j++].second});

        v.push_back({lv, mn});
    }
}

void build(int n, int l, int r){
    if(l == r) { st[n].pb({dep[tree[l]], val[tree[l]]});  return; } 
    int mid = (l + r)/2;
    build(2*n, l, mid), build(2*n + 1, mid + 1, r);

    merge(st[2*n], st[2*n + 1], st[n]);
}

int query(int n, int l, int r, int i, int j, int d){
    if(l > j or r < i) return INF;
    if(i <= l and j >= r){
        auto it = upper_bound(st[n].begin(), st[n].end(), make_pair(d, INF));
        if(it == st[n].begin()) return INF;
        else return --it, it->second;
    }
    int mid = (l+r)/2;

    return min(query(2*n, l, mid, i, j, d), query(2*n + 1, mid + 1, r, i, j, d));
}

void dfs(int n, int f){
    dep[n] = dep[f] + 1;
    tree.pb(n);
    treePos[n].first = tree.size() - 1;
    for(auto u : adj[n]) if(u != f) dfs(u, n);
    treePos[n].second = tree.size() - 1;
}

int main(){
    int n, r;
    scanf("%d%d", &n, &r);
    for(int i = 1; i <= n; i++) scanf("%d",&val[i]);
    for(int i = 1, a, b; i < n; i++)
        scanf("%d%d", &a, &b), adj[a].pb(b), adj[b].pb(a);
    dep[0] = -1;
    tree.pb(0);
    dfs(r, 0);
    build(1, 1, n);
    
    int q, ans = 0;
    scanf("%d",&q);
    for(int i = 0; i < q; i++){
        int x, k;
        int p, q;
        scanf("%d%d", &p, &q);
        x = (p + ans)%n + 1;
        k = (q + ans)%n;

        ans = query(1, 1, n, treePos[x].first, treePos[x].second, k + dep[x]);
        printf("%d\n", ans);
    }

    return 0;
}
