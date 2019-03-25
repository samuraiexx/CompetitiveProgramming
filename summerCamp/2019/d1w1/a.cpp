#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " << 
typedef long long ll;
const int N = 2e4 + 5;
vector<pair<int, int>> adj[N];
bool vis[N];

int main(){
  int n, m;
  while(cin >> n >> m, n){
    for(int i = 1; i <= n; i++)
      adj[i].clear(), vis[i] = false;

    for(int i = 0; i < m; i++){
      int t, s, d;
      cin >> t >> s >> d;

      adj[s].pb({t, d});
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    q.push({-1, 1});

    while(q.size()) {
      auto p = q.top(); q.pop();
      if(vis[p.nd]) continue;

      vis[p.nd] = true;
      for(auto x : adj[p.nd])
        if(x.st > p.st) q.push(x);
    }

    int ans = 0;
    for(int i = 1; i <= n; i++)
      ans += vis[i];

    cout << ans << '\n';
  }
}
