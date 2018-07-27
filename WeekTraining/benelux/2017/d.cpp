#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " << 
const int N = 1e5 + 5;

vector<pair<int, int>> adj[N];
int vis[N];
bool vis2[N];
int to[N];

bool dfs(int n, int f){
  if(vis2[n]) return false;
  vis2[n] = true;
  if(n == 1) return to[n] = n, true;

  for(auto p : adj[n])
    if(p.nd != f and p.nd != vis[n])
      if(dfs(p.nd, n)) to[n] = p.nd;

  return to[n] != -1;
}

int main(){
  memset(vis, -1, sizeof vis);
  memset(to, -1, sizeof to);

  cin.tie(0), ios_base::sync_with_stdio(0);

  int n, m;
  cin >> n >> m;
  for(int i = 0, a, b, c; i < m; i++)
    cin >> a >> b >> c, adj[a].pb({-c, b}), adj[b].pb({-c, a});

  priority_queue<pair<int, pair<int, int>>> q;
  q.push({0, {1, -1}});

  while(q.size()){
    auto p = q.top(); q.pop();
    if(vis[p.nd.st] != -1) continue;
    vis[p.nd.st] = p.nd.nd;

    for(auto a : adj[p.nd.st])
        q.push({p.st + a.st, {a.nd, p.nd.st}});
  }

  if(!dfs(0, -1)) return cout << "impossible\n", 0;

  vector<int> path;
  int x = 0;
  while(to[x] != x)
    path.pb(x), x = to[x];
  path.pb(1);
  cout << path.size() << ' ';
  for(auto x : path) cout << x << ' ';
  cout << '\n';

}
