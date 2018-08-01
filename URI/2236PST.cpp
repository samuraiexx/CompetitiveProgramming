#include<bits/stdc++.h>
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " <<
using namespace std;
const int N = 5e4 + 5;
const int M = 1e6;
int mn[N];
int nxt[N];

int lt[M], rt[M], st[M];
int sz = 1;
vector<int> root;
int ver[N];

vector<int> g[N];
vector<int> pos[N];

void dfs(int u, int r) {
  if (mn[u]) return;
  mn[u] = r;
  for(int v : g[u]) dfs(v, r);
}

int update(int n, int l, int r, int i){
  int node = sz++;
  if(l == r) { st[node] = 1; return node; }
  int mid = (l + r)/2;

  lt[node] = lt[n];
  rt[node] = rt[n];

  if(i <= mid) lt[node] = update(lt[n], l, mid, i);
  else rt[node] = update(rt[n], mid + 1, r, i);

  st[node] = st[lt[node]] + st[rt[node]];

  return node;
}

int query(int n, int l, int r, int i, int j){
  if(n == 0) return 0;
  if(i > r or l > j) return 0;
  if(i <= l and r <= j) return st[n];
  int mid = (l + r)/2;
  return query(lt[n], l, mid, i, j) + query(rt[n], mid + 1, r, i, j);
}

int main(){
  cin.tie(0), ios_base::sync_with_stdio(false);

  int n, q;
  cin >> n >> q;
  for(int i = 1, x; i <= n; i++)
    cin >> nxt[i], g[nxt[i]].push_back(i);

  for(int i = 1; i <= n; i++)
    dfs(i, i);

  for(int i = 1; i <= n; i++)
    pos[mn[i]].push_back(i);

  root.push_back(0);
  for(int i = 1; i <= n; i++){
    for(auto x : pos[i]){
      root.push_back(update(root.back(), 1, n, x));
    }
    ver[i] = root.back();
  }

  while(q--){
    int l, r;
    cin >> l >> r;

    int i = 1, j = n;
    while(i != j){
      int mid = (i + j + 1)/2;
      int x = query(ver[mid], 1, n, l, r);

      if(2*x <= r - l + 1) i = mid;
      else j = mid - 1;
    }
    int x = i;
    int amt1 = query(ver[x], 1, n, l, r);

    i = 1, j = n;
    while(i != j){
      int mid = (i + j)/2;
      int x = query(ver[mid], 1, n, l, r);

      if(2*x < r - l + 1) i = mid + 1;
      else j = mid;
    }
    int y = i;
    int amt2 = query(ver[y], 1, n, l, r);

    int ans;
    if(amt1 >= (r - l + 1) - amt2)
      ans = amt1;
    else ans = amt2;

    i = 1, j = n;
    while(i != j){
      int mid = (i + j)/2;
      int x = query(ver[mid], 1, n, l, r);

      if(x < ans) i = mid + 1;
      else j = mid;
    }

    cout << i << '\n';
  }
}
