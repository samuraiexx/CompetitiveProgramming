#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl;
#define _ << ", " << 
typedef long long ll;
const int N = 2e5 + 5;
const int M = 19;
int n, m;

struct Edge{
  int u, v, c;
  bool operator<(Edge e)const{
    if(c != e.c) return c > e.c;
    return e.u == u ? v < e.v : u < e.u;
  };
};

struct pHash{
  size_t operator()(const pair<int, int> &p) const {
    size_t h1 = p.st;
    size_t h2 = p.nd;

    return (h1 << 32) + h2;
  }
};

vector<Edge> adj[N];
int anc[M][N], h[N], mx[M][N];

map<pair<int, int>, int> edgs;
set<pair<int, int>> mst;
ll cost;

void prim(){
  priority_queue<Edge> q;
  q.push({1, 1, 0});

  while(q.size()){
    Edge edge = q.top();
    q.pop();

    if(h[edge.v]) continue;
    anc[0][edge.v] = edge.u;
    mx[0][edge.v] = edge.c;
    h[edge.v] = 1 + h[edge.u];
    cost += edge.c;

    mst.insert({min(edge.u, edge.v), max(edge.u, edge.v)});

    for(auto edge : adj[edge.v])
      if(!h[edge.v]) q.push(edge);
  }
}

void lcapre(){
  for(int i = 1; i < M; i++)
    for(int j = 1; j <= n; j++)
      anc[i][j] = anc[i - 1][anc[i - 1][j]],
      mx[i][j] = max(mx[i - 1][anc[i - 1][j]], mx[i - 1][j]);
}

int getMax(int u, int v){
  int ans = 0;

  if(h[u] < h[v]) swap(u, v);

  for(int i = M - 1; i >= 0; i--)
    if(h[anc[i][u]] >= h[v])
      ans = max(ans, mx[i][u]), u = anc[i][u];
  if(u == v) return ans;

  for(int i = M - 1; i >= 0; i--)
    if(anc[i][u] != anc[i][v]){
      ans = max({ans, mx[i][u], mx[i][v]});
      u = anc[i][u], v = anc[i][v];
    }

  return max({ans, mx[0][u], mx[0][v]});
}

int main(){
  ios_base::sync_with_stdio(false), cin.tie(0);

  cin >> n >> m;

  for(int i = 0; i < m; i++){
    int a, b, c;
    cin >> a >> b >> c;
    adj[a].pb({a, b, c});
    adj[b].pb({b, a, c});

    if(a > b) swap(a, b);
    edgs[{a, b}] = c;
  }

  prim();
  lcapre();

  int q;
  cin >> q;
  while(q--){
    int u, v;
    cin >> u >> v;
    if(u > v) swap(u, v);

    int c = edgs[{u, v}];
    Edge edge({u, v, c});

    if(mst.count({u, v})) cout << cost << '\n';
    else cout << cost + c - getMax(u, v) << '\n';
  }
}
