#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " << 
typedef long long ll;
const int N = 2e5 + 5;
int par[N];
int val[N];
int tsz[N];
int ans[N];

vector<int> adj[N];
int sz[N], nxt[N];
int h[N];
int in[N], rin[N], out[N];
int ed[N];
int t;

void dfs_sz(int u = 1){
  sz[u] = 1;
  for(auto &v : adj[u]){
    h[v] = h[u] + 1;

    dfs_sz(v);
    sz[u] += sz[v];
    if(sz[v] > sz[adj[u][0]])
      swap(v, adj[u][0]);
  }
}

void dfs_hld(int u = 1){
  in[u] = t++;
  ed[nxt[u]] = in[u];
  rin[in[u]] = u;
  for(auto v : adj[u]){
    nxt[v] = (v == adj[u][0] ? nxt[u] : v);
    dfs_hld(v);
  }

  out[u] = t - 1;
}

int lca(int u, int v){
  while(nxt[u] != nxt[v]){
    if(h[nxt[u]] < h[nxt[v]]) swap(u, v);
    u = par[nxt[u]];
  }

  if(h[u] > h[v]) swap(u, v);
  return u;
}

void add(int x, int val, int *bit){
  for(int i = x + 2; i < N; i+=i&-i)
    bit[i] += val;
}

int query(int a, int b, int *bit){
  int ans = 0;
  for(int i = b + 2; i > 0; i-=i&-i)
    ans += bit[i];
  for(int i = a + 1; i > 0; i-=i&-i)
    ans -= bit[i];

  return ans;
}

int hld_query(int u){
  int tans = query(in[u], out[u], tsz)*val[u];
  while(u > 1){
    int v = par[nxt[u]];

    tans += query(in[nxt[u]], in[u] - 1, ans);

    tans += (query(in[v], out[v], tsz) -
            query(in[nxt[u]], out[nxt[u]], tsz))*val[v];
    
    u = v;
  }

  return tans;
}

void hld_update(int u){
  add(in[u], 1, tsz);
  while(u > 0){
    add(in[u], val[u], ans);
    u = par[nxt[u]];
  }
}

int main(){
  cin.tie(0), ios_base::sync_with_stdio(false);
  int T;
  nxt[1] = 1;
  cin >> T;
  while(T--){
    int n;
    cin >> n;

    for(int i = 1; i <= n; i++)
      adj[i].clear();
    memset(tsz, 0, sizeof tsz);
    memset(ans, 0, sizeof ans);
    t = 0;

    for(int i = 1; i <= n; i++)
      cin >> val[i];

    for(int i = 1; i <= n; i++){
      cin >> par[i];

      adj[par[i]].pb(i);
    }

    dfs_sz();
    dfs_hld();
    hld_update(1);

    for(int i = 2; i <= n; i++){
      cout << hld_query(i) << ' ';
      hld_update(i);
    }
    cout << '\n';
  }
}
