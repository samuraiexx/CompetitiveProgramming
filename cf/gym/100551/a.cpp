#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " << 
typedef long long ll;
const int INF = 0x3f3f3f3f;
const int N = 3e5 + 5;
vector<int> st[4*N];
int pa[N], sz[N];
stack<pair<int, int>> rb;

struct Query{
  int u, v;
  int i, j;
};

vector<int> q;
vector<Query> qv;
map<pair<int, int>, int> m;

int amt;

int find(int u){
  return pa[u] == u ? u : find(pa[u]);
}

void unite(int u, int v) {
  u = find(u), v = find(v);
  if(sz[u] < sz[v]) swap(u, v);
  if(u == v) rb.push({0, 0});
  else rb.push({v, sz[u]}), sz[u] += sz[v], pa[v] = u, amt--;
}

void rollback() {
  auto p = rb.top(); rb.pop();
  if(p.st == 0) return;
  sz[pa[p.st]] = p.nd;
  pa[p.st] = p.st;
  amt++;
}

void update(int n, int l, int r, int i, int j, int id){
  if(r < i or l > j) return;
  if(i <= l and r <= j){ st[n].pb(id); return; }
  int mid = (l + r)/2;
  update(2*n, l, mid, i, j, id);
  update(2*n + 1, mid + 1, r, i, j, id);
}

void dfs(int n, int l, int r){
  for(auto i : st[n]) unite(qv[i].u, qv[i].v);
  if(l == r) cout << amt << '\n';
  else{
    int mid = (l + r)/2;
    dfs(2*n, l, mid);
    dfs(2*n + 1, mid + 1, r);
  }
  for(auto i : st[n]) rollback();
}


int main(){
  cin.tie(0), ios_base::sync_with_stdio(false);
  freopen("connect.in", "r", stdin);
  freopen("connect.out", "w", stdout);
  int n, k;
  cin >> n >> k;

  for(int i = 1; i <= n; i++)
    pa[i] = i, sz[i] = 1;

  for(int i = 0; i < k; i++){
    char t;
    cin >> t;

    if(t == '?') {
      q.pb(i);
    } else if(t == '+') {
      int u, v;
      cin >> u >> v;
      if(u > v) swap(u, v);

      m[{u, v}] = qv.size();
      qv.pb({u, v, (int)q.size(), INF});
    } else if(t == '-') {
      int u, v;
      cin >> u >> v;
      if(u > v) swap(u, v);

      qv[m[{u, v}]].j = (int)q.size() - 1;
    }
  }

  if(q.size() == 0) return 0;

  for(int i = 0; i < qv.size(); i++){
    auto &qry = qv[i];
    if(qry.j >= qry.i) update(1, 0, q.size() - 1, qry.i, qry.j, i);
  }

  amt = n;
  dfs(1, 0, q.size() - 1);
}
