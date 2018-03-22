#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " << 
typedef long long ll;
const int N = 1e4 + 5;
bool vis[N];
vector<int> adj[N];

void dfs(int n){
  for(auto a : adj[n])
    if(!vis[a]) vis[a] = true, dfs(a);
}

int main(){
  int n, m;
  cin >> n >> m;
  for(int i = 0, a, b; i < m; i++)
    cin >> a >> b, adj[a].pb(b), adj[b].pb(a);

  dfs(1);
  bool ok = (m == n - 1);
  for(int i = 1; i <= n; i++) if(!vis[i]) ok = false;

  if(ok)
    cout << "YES" << endl;
  else cout << "NO" << endl;
}
