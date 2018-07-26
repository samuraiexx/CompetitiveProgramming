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
const int S = 8e6;

vector<int> adj[N];
int city[N];
pair<int, int> lim[N];
int etNode[N];

int lcaPos[N];
int lv[M];
int lcaNode[M];
pair<int, int> lca[M][21];

int root[M];
int lt[S];
int rt[S];
int st[S];
int stSz = 1;

int cnt = 1, lcaSz;
int rb;

int update(int p, int l, int r, int pos, int val){
  int n = stSz++;
  if(l == r) st[n] = val + st[p];
  else {
    int mid = (l + r)/2;
    lt[n] = lt[p], rt[n] = rt[p];
    if(pos <= mid) lt[n] = update(lt[p], l, mid, pos, val);
    else rt[n] = update(rt[p], mid + 1, r, pos, val);

    st[n] = st[lt[n]] + st[rt[n]];
  }
  return n;
}

int query(int n, int l, int r, int i, int j){
  if(n == 0 or i > r or l > j or j < i) return 0;
  if(i <= l and r <= j) return st[n];
  int mid = (l + r)/2;

  return query(lt[n], l, mid, i, j) + 
         query(rt[n], mid + 1, r, i, j);
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

int main(){
  cin.tie(0), ios_base::sync_with_stdio(false);

  int n, m, q;
  cin >> n >> m >> q;

  for(int i = 1; i < n; i++){
    int a, b;
    cin >> a >> b;
    adj[a].pb(b), adj[b].pb(a);
  }
  dfs(1, 1, -1);
  preLca();

  for(int i = 1; i <= m; i++){
    int city;
    cin >> city;
    root[rb + 1] = update(root[rb], 1, 2*n, lim[city].st, 1), rb++;
    root[rb + 1] = update(root[rb], 1, 2*n, lim[city].nd, -1), rb++;
  }

  for(int i = 0; i < q; i++){
    int v, u, a;
    cin >> v >> u >> a;

    int x = lcaQry(u, v);

    int mn = query(root[rb], 1, 2*n, lim[x].st, lim[u].st) + 
             query(root[rb], 1, 2*n, lim[x].st + 1, lim[v].st);
    mn = min(a, mn);


    cout << mn << ' ';

    for(int a = 1; a <= mn; a++){
      int i = 1, j = m;

      while(i != j){
        int mid = (i + j)/2;
        int val = query(root[2*mid], 1, 2*n, lim[x].st, lim[u].st) + 
          query(root[2*mid], 1, 2*n, lim[x].st + 1, lim[v].st); 
        if(val >= a) j = mid;
        else i = mid + 1;
      }
      cout << i << " ";
    }
    cout << '\n';
  }
}
