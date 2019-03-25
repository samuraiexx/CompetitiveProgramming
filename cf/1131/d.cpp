#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " << 
typedef long long ll;
const int N = 2e3 + 5;;
vector<int> adj[N];
char g[N][N];
int ans[N];
bool ok = true;
int vis[N];

int par[N], sz[N];

int find(int a) { return par[a] == a ? a : par[a] = find(par[a]); }

void unite(int a, int b) {
  if ((a = find(a)) == (b = find(b))) return;
  if (sz[a] < sz[b]) swap(a, b);
  par[b] = a; sz[a] += sz[b];
}

void dfs(int u){
  u = find(u);
  if(vis[u] == 1){ ok = false; return; }
  if(vis[u] == 2) return;
  vis[u] = 1;

  for(auto v : adj[u])
    dfs(v);

  vis[u] = 2;
}

int dpf(int u){
  u = find(u);
  if(ans[u]) return ans[u];
  ans[u] = 1;
  for(auto v : adj[u])
    ans[u] = max(ans[u], dpf(v) + 1);
  return ans[u];
}

int main(){
  for(int i = 0; i < N; i++)
    par[i] = i, sz[i] = 1;

  cin.tie(0), ios_base::sync_with_stdio(false);
  int n, m;
  cin >> n >> m;

  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= m; j++){
      char c;
      cin >> c;
      g[i][j] = c;

      if(c == '=') unite(i, j + n);
    }
  }

  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= m; j++){
      char c = g[i][j];
      if(c == '<') adj[find(j + n)].pb(find(i));
      else if(c == '>') adj[find(i)].pb(find(j + n));
    }
  }

  for(int i = 1; i <= n + m; i++)
    dfs(i);
  if(!ok) return cout << "No\n", 0;
  cout << "Yes\n";

  for(int i = 1; i <= n; i++)
    cout << dpf(i) << ' ';
  cout << endl;

  for(int i = 1; i <= m; i++)
    cout << dpf(i + n) << ' ';
  cout << endl;
}
