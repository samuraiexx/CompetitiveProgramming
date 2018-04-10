#include<bits/stdc++.h>
#define st first
#define nd second
#define pb push_back
#define db(x) cerr << #x << " = " << x << endl
using namespace std;
const int N = 1e3 + 5;

vector<pair<int, int>> adj[N];
int vis[N];

int main(){
  int n, m;
  cin >> n >> m;
  for(int i = 0; i < m; i++){
    int s, t, b;
    cin >> s >> t >> b;
    adj[s].pb({b, t});
    adj[t].pb({b, s});
  }

  int ans = 0;
  priority_queue<pair<int, int>> q;
  q.push({0, 0});
  while(q.size()){
    auto p = q.top(); q.pop();
    if(vis[p.nd]) continue;
    vis[p.nd] = true;
    if(p.nd == n + 1){ cout << -p.st << endl; break;}

    for(auto x : adj[p.nd])
      if(!vis[x.nd]) q.push({-x.st + p.st, x.nd});
  }
}
