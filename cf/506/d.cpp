#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define st first
#define nd second
#define db(x) cout << #x << " = " << x << endl
#define _ << ", " << 
typedef long long ll;
const int N = 1e5 + 5;

map<int, vector<int>> adj[N];
map<int, int> id[N];
map<int, int> ans[N];
bool vis[N];

void dfs(int n, int c, int x){
  if(id[n].count(c)) return;
  id[n][c] = x;

  for(auto v : adj[n][c])
    dfs(v, c, x);
}

int main(){
  cin.tie(0); ios_base::sync_with_stdio(false);
  int n, m;
  cin >> n >> m;

  for(int i = 0; i < m; i++){
    int a, b, c;
    cin >> a >> b >> c;
    adj[a][c].pb(b), adj[b][c].pb(a);
  }

  for(int i = 1; i <= n; i++)
    for(auto p : adj[i])
      dfs(i, p.st, i);

  int q;
  cin >> q;
  for(int i = 0; i < q; i++){
    int u, v;
    cin >> u >> v;
    if(id[u].size() > id[v].size()) swap(u, v);
    if(ans[u].count(v)) cout << ans[u][v] << '\n'; continue; }

    vis[u] = true;

    int cnt = 0;
    for(auto p : id[u])
      if(id[v].count(p.st) and id[v][p.st] == p.nd) cnt++;

    ans[u][v] = cnt;
    ans[v][u] = cnt;

    cout << cnt << '\n';
  }
}
