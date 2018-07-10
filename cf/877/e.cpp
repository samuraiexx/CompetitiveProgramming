#include<bits/stdc++.h>
#define st first
#define nd second
using namespace std;
const int N = 2e5 + 5;

int v[N];
int st[4*N];
bool lz[4*N];
vector<int> adj[N];
pair<int, int> sub[N];
int cnt = 1;

void build(int n, int l, int r){
  if(l == r) { st[n] = v[l]; return; }
  int mid = (l + r)/2;
  build(2*n, l, mid);
  build(2*n + 1, mid + 1, r);
  st[n] = st[2*n] + st[2*n + 1];
}

void push(int n, int l, int r){
  if(!lz[n]) return;
  st[n] = r - l + 1 - st[n];
  if(l != r){
    lz[2*n] ^= lz[n];
    lz[2*n + 1] ^= lz[n];
  }
  lz[n] = false;
}

void update(int n, int l, int r, int i, int j){
  push(n, l, r);
  if(j < l or i > r) return;
  if(i <= l and r <= j) { lz[n] = 1; push(n, l, r); return; }
  int mid = (l + r)/2;
  update(2*n, l, mid, i, j);
  update(2*n + 1, mid + 1, r, i, j);
  st[n] = st[2*n] + st[2*n + 1];
}

int query(int n, int l, int r, int i, int j){
  push(n, l, r);
  if(j < l or i > r) return 0;
  if(i <= l and r <= j) return st[n];
  int mid = (l + r)/2;
  return query(2*n, l, mid, i, j) + query(2*n + 1, mid + 1, r, i, j);
}

void dfs(int n){
  sub[n].st = cnt++;
  for(auto x : adj[n])
    dfs(x);
  sub[n].nd = cnt - 1;
}

int main(){
  cin.tie(0); ios_base::sync_with_stdio(false);

  int n;
  cin >> n;

  for(int i = 2; i <= n; i++){
    int f;
    cin >> f;
    adj[f].push_back(i);
  }

  dfs(1);

  for(int i = 1; i <= n; i++)
    cin >> v[sub[i].st];

  build(1, 1, n);

  int q;
  cin >> q;
  for(int i = 0; i < q; i++){
    string t;
    int x;
    cin >> t >> x;
    if(t == "get"){
      cout << query(1, 1, n, sub[x].st, sub[x].nd) << '\n';
    }else{
      update(1, 1, n, sub[x].st, sub[x].nd);
    }
  }
}
