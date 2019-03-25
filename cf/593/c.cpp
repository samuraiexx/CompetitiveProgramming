#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " << 
typedef long long ll;

const ll N = 2e5 + 5;
const ll INF = 2e18;
ll par[N];
vector<pair<ll, ll>> adj[N];
ll val[N];
ll n, m;

ll sz[N], nxt[N];
ll h[N];
ll in[N], rin[N], out[N];
ll etov[N];
ll t;

// Segment Tree
ll st[4*N], v[N];

ll mult(ll a, ll b){
  return INF/b < a ? INF : a*b;
}

void build(ll p, ll l, ll r) {
  if (l == r) { st[p] = v[l]; return; }
  build(2*p, l, (l+r)/2);
  build(2*p+1, (l+r)/2+1, r);
  st[p] = mult(st[2*p], st[2*p+1]);
}

ll query(ll p, ll l, ll r, ll i, ll j) {
  if (r < i or l > j) return 1;
  if (l >= i and r <= j) return st[p];

  return mult(query(2*p, l, (l+r)/2, i, j),
              query(2*p+1, (l+r)/2+1, r, i, j));
}

void update(ll p, ll l, ll r, ll i, ll v) {
  if(l == r){ st[p] = v; return; }
  ll mid = (l + r)/2;

  if(i <= mid) update(2*p, l, mid, i, v);
  else update(2*p + 1, mid + 1, r, i, v);

  st[p] = mult(st[2*p], st[2*p + 1]);
}

void dfs_sz(ll u = 1){
  sz[u] = 1;
  for(auto &p : adj[u]) if(p.st != par[u]) {
    etov[p.nd] = p.st;

    par[p.st] = u;
    h[p.st] = h[u] + 1;

    dfs_sz(p.st);
    sz[u] += sz[p.st];
    if(sz[p.st] > sz[adj[u][0].st])
      swap(p, adj[u][0]);
  }
}

void dfs_hld(ll u = 1){
  in[u] = t++;
  for(auto p : adj[u]) if(p.st != par[u]) {
    nxt[p.st] = (p.st == adj[u][0].st ? nxt[u] : p.st);
    v[t] = val[p.nd];
    dfs_hld(p.st);
  }

  out[u] = t - 1;
}

ll lca(ll u, ll v){
  while(nxt[u] != nxt[v]){
    if(h[nxt[u]] < h[nxt[v]]) swap(u, v);
    u = par[nxt[u]];
  }

  if(h[u] > h[v]) swap(u, v);
  return u;
}

ll query_up(ll u, ll v) {
  if(u == v) return 1;
  ll ans = 1;
  while(1){
    if(nxt[u] == nxt[v]){
      if(u == v) break;
      ans = mult(ans, query(1, 0, n - 1, in[v] + 1, in[u]));
      break;
    }

    ans = mult(ans, query(1, 0, n - 1, in[nxt[u]], in[u]));
    u = par[nxt[u]];
  }

  return ans;
}

ll hld_query(ll u, ll v) {
  ll l = lca(u, v);
  return mult(query_up(u, l), query_up(v, l));
}

int main(){
  cin.tie(0), ios_base::sync_with_stdio(false);

  cin >> n >> m;

  for(ll i = 1; i < n; i++){
    ll a, b, c;
    cin >> a >> b >> c;
    val[i] = c;
    adj[a].pb({b, i});
    adj[b].pb({a, i});
  }

  v[0] = 1;
  dfs_sz();
  dfs_hld();
  build(1, 0, n - 1);

  while(m--){
    ll t;
    cin >> t;
    if(t == 1){
      ll a, b, y;
      cin >> a >> b >> y;

      cout << y/hld_query(a, b) << '\n';
    } else {
      ll p, c;
      cin >> p >> c;
      update(1, 0, n - 1, in[etov[p]], c);
    }
  }
}
