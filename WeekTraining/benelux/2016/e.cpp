#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl;
#define _ << ", " << 
#define piii pair<int, pair<int, int>>
const int N = 1e4 + 5;

vector<piii> adj[N];
vector<piii> ar;
int vis[N];
set<int> dfs;
vector<int> df;

int par[N], sz[N];

int find(int a) { return par[a] == a ? a : par[a] = find(par[a]); }

void unite(int a, int b) {
  if ((a = find(a)) == (b = find(b))) return;
  if (sz[a] < sz[b]) swap(a, b);
  par[b] = a; sz[a] += sz[b];
}

int main(){
  int n, m, x;
  cin >> n >> m >> x;
  for(int i = 0, a, b, t; i < m; i++)
    cin >> a >> b >> t, adj[a].pb({t, {a, b}}), adj[b].pb({t, {b, a}}), dfs.insert(t);

  for(auto a : dfs) df.pb(a);

  for(int i = 1; i < n; i++)
    par[i] = i, sz[i] = 1;

  priority_queue<piii, vector<piii>, greater<piii>> q;
  q.push({0, {-1, 1}});

  int mdist = 0;
  bool ok = 1;

  while(q.size() and !mdist){
    auto p = q.top(); q.pop();
    int d = p.nd.nd;
    int w = p.st;

    if(vis[d]) continue;
    vis[d] = 1;

    if(d == n and mdist == 0) {
      mdist = w*(100 + x)/100;
      break;
    }

    for(auto x : adj[d])
      q.push({w + x.st, { x.nd.st, x.nd.nd }});
  }

  int l = 0, r = df.size() - 1;

  while(l != r){
    priority_queue<piii, vector<piii>, greater<piii>> q;
    int mid = (l + r)/2;
    memset(vis, 0, sizeof vis);
    q.push({0, {-1, 1}});

    bool ok = 0;
    while(q.size()){
      auto p = q.top(); q.pop();
      int d = p.nd.nd;
      int w = p.st;


      if(w > mdist) break;
      else if(d == n) {ok = 1; break; }

      if(vis[d]) continue;
      vis[d] = 1;

      for(auto x : adj[d]) if(x.st <= df[mid])
        q.push({w + x.st, { x.nd.st, x.nd.nd }});
    }

    if(ok) r = mid;
    else l = mid + 1;
  }

  cout << df[r] << endl;
}
