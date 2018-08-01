#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " << 
typedef long long ll;
const int N = 2e5 + 5;
const int M = 8e5;

vector<int> adj[N];
int city[N];
pair<int, int> lim[N];
int etNode[N];

int lcaPos[N];
int lv[M];
int lcaNode[M];
pair<int, int> lca[M][21];

int cnt = 1, lcaSz;
int rb;
int p;

int bit[N];

int ans[N][13];

int m;

struct Qry{
  int u, v, lca;
  int pos;
  int i;
};

void add(int x, int val){
  for(int i = x; i < N; i+=i&-i)
    bit[i] += val;
}

int query(int a, int b){
  int ans = 0; 
  for(int i = b; i > 0; i-=i&-i)
    ans += bit[i];

  for(int i = a - 1; i > 0; i-=i&-i)
    ans -= bit[i];

  return ans;
}

void preLca(){
  for(int i = 0; i < lcaSz; i++){
    lca[i][0].st = lv[i];
    lca[i][0].nd = lcaNode[i];
  }

  for(int j = 1; j < 21; j++){
    for(int i = 0; i < lcaSz; i++){
      int z = i + (1 << j - 1);
      if(lca[i][j - 1].st < lca[z][j - 1].st)
        lca[i][j] = lca[i][j - 1];
      else lca[i][j] = lca[z][j - 1];
    }
  }
}

int lcaQry(int a, int b){
  a = lcaPos[a], b = lcaPos[b];
  if(a > b) swap(a, b);

  int dx = 32 - __builtin_clz(b - a + 1) - 1;
  int z = b - (1 << dx) + 1;

  if(lca[a][dx].st < lca[z][dx].st)
    return lca[a][dx].nd;
  else 
    return lca[z][dx].nd;
}

void dfs(int n, int nv, int f){
  etNode[cnt] = n;
  lim[n].st = cnt++;

  lcaPos[n] = lcaSz;
  lcaNode[lcaSz] = n;
  lv[lcaSz++] = nv;

  for(auto x : adj[n]) if(x != f){
    dfs(x, nv + 1, n);
    lcaNode[lcaSz] = n;
    lv[lcaSz++] = nv;
  }

  etNode[cnt] = n;
  lim[n].nd = cnt++;
}

void pbs(int l, int r, vector<Qry> v){
  if(l == r){
    for(auto &q : v)
      ans[q.i][q.pos] = (l == m + 1 ? -1 : l);
    return;
  }
  int mid = (l + r)/2;
  while(p < mid){
    p++;
    int c = city[p];
    add(lim[c].st, 1);
    add(lim[c].nd, -1);
  }
  while(p > mid){
    int c = city[p];
    add(lim[c].st, -1);
    add(lim[c].nd, 1);
    p--;
  }

  vector<Qry> lv, rv;
  for(auto &q : v){
    int amt = query(lim[q.lca].st, lim[q.u].st) +
              query(lim[q.lca].st + 1, lim[q.v].st);

    if(amt >= q.pos) lv.pb(q);
    else rv.pb(q);
  }
  pbs(l, mid, lv);
  pbs(mid + 1, r, rv);
}

int main(){
  cin.tie(0), ios_base::sync_with_stdio(false);

  int n, q;
  cin >> n >> m >> q;

  for(int i = 1; i < n; i++){
    int a, b;
    cin >> a >> b;
    adj[a].pb(b), adj[b].pb(a);
  }
  dfs(1, 1, -1);
  preLca();

  for(int i = 1; i <= m; i++)
    cin >> city[i];

  vector<Qry> qv;
  for(int i = 0; i < q; i++){
    int u, v, lim;
    cin >> u >> v >> lim;

    int lca = lcaQry(u, v);
    for(int j = 1; j <= lim; j++)
      qv.push_back({u, v, lca, j, i});

  }

  memset(ans, -1, sizeof ans);

  pbs(1, m + 1, qv);

  for(int i = 0; i < q; i++){
    int sz = 0;
    while(ans[i][++sz] != -1);
    cout << sz - 1 << ' ';
    for(int j = 1; j < sz; j++)
      cout << ans[i][j] << ' ';
    cout << '\n';
  }
}
