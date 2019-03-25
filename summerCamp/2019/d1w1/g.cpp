#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " << 
#define pii tuple<int, int, int>
typedef long long ll;
const int N = 1e5 + 5;
vector<tuple<int, int>> adj[N];
vector<int> adj[N];
int dist[N];
int id[N];

int main(){
  cin.tie(0), ios_base::sync_with_stdio(false);
  memset(dist, -1, sizeof dist);

  int n, m, k, p;
  cin >> n >> m >> k >> p;

  vector<int> super;
  for(int i = 0, x; i < k; i++)
    cin >> x, super.pb(x);

  for(int i = 0; i < m; i++){
    int a, b, c;
    cin >> a >> b >> c;
    adj[a].pb({c, b});
    adj[b].pb({a, b});
  }

  priority_queue<pii, vector<pii>, greater<pii>> q;
  q.push({0, 1, 1});
  q.push({0, n, 1});
  for(auto x : super) q.push({0, x, x});

  while(q.size()){
    auto [c, n, sp] = q.top(); q.pop();
    if(dist[n] >= 0){
      if(dist[n] + c <= p)
        adj[sp].pb(id[n]), adj[id[n]].pb(sp);
      continue; 
    }
    dist[n] = c, id[n] = sp;

    for(auto x : adj[n])
      q.push({c + x.st, x.nd, sp});
  }
}
