#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " << 
typedef long long ll;
const int N = 105;
const int M = N*N; 
char g[N][N];
pair<int, int> comp[N][N];

vector<int> adj[M];
int x, vis[M], b[M], ans;
int sz = 1;

bool match(int u) {
  if (vis[u] == x) return 0;
  vis[u] = x;
  for (int v : adj[u]){
    if (!b[v] or match(b[v])) return b[v]=u;
  }
  return 0;
}

int main(){
  ios_base::sync_with_stdio(false), cin.tie(0);

  int n;
  while(cin >> n){
    memset(vis, 0, sizeof vis);
    memset(b, 0, sizeof b);
    x = ans = 0, sz = 1;

    for(int i = 0; i < n; i++)
      for(int j = 0; j < n; j++)
        cin >> g[i][j];

    for(int i = 0; i < n; i++){
      int id = sz++;
      for(int j = 0; j < n; j++){
        if(g[i][j] == 'X') id = sz++;
        else comp[i][j].st = id;
      }
    }

    for(int i = 0; i < sz; i++) adj[i].clear(), vis[i] = 0;

    int fp = sz;
    sz = 1;

    for(int j = 0; j < n; j++){
      int id = sz++; b[id] = 0;
      for(int i = 0; i < n; i++){
        if(g[i][j] == 'X') id = sz++, b[id] = 0;
        else comp[i][j].nd = id, adj[comp[i][j].st].pb(id);
      }
    }

    for(int i = 1; i < fp; i++) x++, ans += match(i);
    cout << ans << '\n';
  }
}
