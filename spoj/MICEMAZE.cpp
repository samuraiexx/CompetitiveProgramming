#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " << 
typedef long long ll;
const int N = 105;

int vis[N];
int amt[N];
vector<int> adj[N];

int main(){
  int n, e, t, m;
  cin >> n >> e >> t >> m;

  for(int i = 1, a, b; i <= m; i++)
    cin >> a >> b >> amt[i], adj[a].pb(b);

  int ans = 0;

  for(int i = 1; i <= n; i++){
    queue<int> q;
    q.push(i), vis[i] = 1;
    while(q.size()){
      int x = q.front(); q.pop();
      db(x);

      for(auto a : adj[x])
        if(!vis[a]) vis[a] = vis[x] + 1, q.push(a);
    }
  }

  cout << ans << endl;
}
