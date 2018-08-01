#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " << 
typedef long long ll;
const int N = 5e5 + 5;
vector<int> adj[N];
int vis[N];

bool dfs(int n){
  if(vis[n]) return false;
  vis[n] = true;
  for(auto x : adj[n])
    dfs(x);

  return true;
}

int main(){
  int n, m, q;
  cin >> n >> m >> q;
  for(int i = 0; i < q; i++){
    int a, b;
    cin >> a >> b;
    adj[a].pb(n + b);
    adj[n + b].pb(a);
  }

  int ans = 0;
  for(int i = 1; i <= n + m; i++)
    ans += dfs(i);

  cout << ans - 1 << endl;
}
