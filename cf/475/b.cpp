#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " << 
typedef long long ll;
const int N = 25;
bool vis[N][N];

vector<pair<int, int>> adj[N][N];

void dfs(pair<int, int> p){
  for(auto x : adj[p.st][p.nd]) if(!vis[x.st][x.nd])
    vis[x.st][x.nd] = true, dfs(x);
}

int main(){
  int n, m;
  cin >> n >> m;
  for(int i = 0; i < n; i++){
    char c;
    cin >> c;
    if(c == '>') for(int j = 0; j < m - 1; j++)
      adj[i][j].pb({i, j + 1});
    if(c == '<') for(int j = 1; j < m; j++)
      adj[i][j].pb({i, j - 1});
  }

  for(int j = 0; j < m; j++){
    char c;
    cin >> c;
    if(c == 'v') for(int i = 0; i < n - 1; i++)
      adj[i][j].pb({i + 1, j});
    if(c == '^') for(int i = 1; i < n; i++)
      adj[i][j].pb({i - 1, j});
  }

  bool ok = 1;
  for(int i = 0; i < n; i++)
    for(int j = 0; j < m; j++){
      memset(vis, 0, sizeof vis);
      dfs({i, j});
      for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
          if(!vis[i][j]) ok = 0;
    }

  if(ok) cout << "YES" << endl;
  else cout << "NO" << endl;
}
