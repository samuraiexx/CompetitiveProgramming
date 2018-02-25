#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl;
#define _ << ", " << 

const int N = 1e5 + 5;
vector<pair<int, int>> adj[N];
int sd[N];
int vis[N];
int vis2[N];

int dfs(int n){
  if(n == 1) return 1;
  int dist = 0;
  for(auto a : adj[n]){
    if(!vis2[a.nd] and sd[n] != a.nd){
      vis2[a.nd] = true;
      dist = max(dist, dfs(a.nd));
      if(dist){
        vis[n] = a.nd;
        break;
      }
    }
  }

  return dist ? dist + 1 : 0;
}

int main(){
  int n, m;

  scanf("%d %d", &n, &m);
  for(int i = 0; i < n; i++) sd[i] = -1;

  for(int i = 0, a, b, d; i < m; i++)
    scanf("%d %d %d", &a,  &b,  &d), adj[b].pb({-d, a}), adj[a].pb({-d, b});

  priority_queue<pair<int, pair<int, int>>> q;

  q.push({0, {1, -1}});

  while(q.size()){
    auto p = q.top(); q.pop();

    if(sd[p.nd.st] != -1) continue;
    sd[p.nd.st] = p.nd.nd;

    for(auto a : adj[p.nd.st]){
      if(sd[a.nd] == -1)
        q.push({p.st + a.st, {a.nd, p.nd.st}});
    }
  }

  int x = dfs(0);
  if(!x) return printf("impossible\n"), 0;

  printf("%d ", x);
  int i = 0;
  while(i != 1){
    printf("%d ", i);
    i = vis[i];
  }
  printf("1\n");
}
