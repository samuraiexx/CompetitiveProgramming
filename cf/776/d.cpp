#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " << 
typedef long long ll;

const int N = 2e5 + 5;

// 2-SAT - O(V+E)
// For each variable x, we create two nodes in the graph: u and !u
// If the variable has index i, the index of u and !u are: 2*i and 2*i+1
int ans[N], cn, vis[N], sccn, scc[N], scch[N];
vector<int> stk, adj[N], radj[N];

void koj(int u) {
  vis[u] = 1;
  for (int v : adj[u]) if (!vis[v]) koj(v);
  stk.pb(u);
}

void rkoj(int u) {
  vis[u] = 0;
  for (int v : radj[u]) if (vis[v]) rkoj(v);
  scc[u] = sccn;
}

void rsat(int);

void sat(int u) {
  if (ans[u] != -1) return;
  ans[u] = 1, rsat(u^1);
  for (int v : adj[u]) sat(v);
}

void rsat(int u) {
  if (ans[u] != -1) return;
  ans[u] = 0, sat(u^1);
  for (int v : radj[u]) rsat(v);
}

bool sat() {
  sccn = 1; // Kosaraju's
  for (int i = 2; i <= cn; i++) if (!vis[i]) koj(i);
  while (stk.size()) {
    int u = stk.back(); stk.pop_back();
    if (vis[u]) rkoj(u), scch[sccn++] = u;
  }

  // Checks if exists a valid assingment.
  for (int i = 2; i <= cn; i+=2) if (scc[i] == scc[i^1]) return 0;

  memset(ans, -1, sizeof ans);
  // To set value of x to true (or false) call sat(x) (or sat(x^1)) below.

  // Finds a valid assignment. Erase if not needed.
  for(int i = sccn - 1; i > 0; --i) sat(scch[i]);

  // Check for inconsistencies in implication graph.
  for (int u = 2; u <= cn; u++) if (ans[u] == 1)
    for (int v : adj[u]) if (!ans[v]) return 0;

  return 1;
}

void add_clause(int x, int y) {
  cn = max(cn, max(x|1, y|1));
  adj[x].pb(y),  adj[y^1].pb(x^1);
  radj[y].pb(x), radj[x^1].pb(y^1);
}

void reset() {
  memset(ans, -1, sizeof ans);
  for(int i=0; i<=cn; ++i) adj[i].clear(), radj[i].clear();
  cn = 0;
}


vector<int> sw[N];
bool state[N];

int main(){
  int n, m;
  cin >> n >> m;

  for(int i = 1; i <= n; i++)
    cin >> state[i];

  for(int i = 0; i < m; i++){
    int x;
    cin >> x;
    for(int j = 0, y; j < x; j++)
      cin >> y, sw[y].pb(i);
  }

  for(int i = 1; i <= n; i++){
    if(state[i]) //unclocked
      add_clause(2*sw[i][0], 2*sw[i][1]),
      add_clause(2*sw[i][0] + 1, 2*sw[i][1] + 1);
    else
      add_clause(2*sw[i][0], 2*sw[i][1] + 1),
      add_clause(2*sw[i][0] + 1, 2*sw[i][1]);
  }

  if(sat()) cout << "YES" << endl;
  else cout << "NO" << endl;
}
