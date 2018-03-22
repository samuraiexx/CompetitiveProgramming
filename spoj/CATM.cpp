#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " << 
typedef long long ll;
const int N = 105;
int vis[N][N];
int vis1[N][N];
int vis2[N][N];
pair<int, int> ms, c1, c2;
int n, m, t;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

void bfs(int x, int y, int vis[N][N]){
  queue<pair<int, int>> q;

  for(int i = 1; i <= n; i++)
    for(int j = 1; j <= m; j++)
      vis[i][j] = 0;

  for(int i = 1; i <= n; i++)
    vis[i][0] = vis[i][m + 1] = 1;

  for(int i = 1; i <= m; i++)
    vis[0][i] = vis[n + 1][i] = 1;

  q.push({x, y}), vis[x][y] = 1;

  while(q.size()){
    auto p = q.front(); q.pop();
    for(int i = 0; i < 4; i++){
      int x = p.st + dx[i];
      int y = p.nd + dy[i];
      if(!vis[x][y])
        vis[x][y] = vis[p.st][p.nd] + 1, q.push({x, y});
    }
  }
}

int main(){
  cin.tie(0), ios_base::sync_with_stdio(false);
  cin >> n >> m >> t;
  
  while(t--){
    cin >> ms.st >> ms.nd;
    cin >> c1.st >> c1.nd >> c2.st >> c2.nd;
    bool ok = false;
    bfs(ms.st, ms.nd, vis);
    bfs(c1.st, c1.nd, vis1);
    bfs(c2.st, c2.nd, vis2);

    for(int i = 1; i <= n; i++)
      if(vis[i][1] < vis1[i][1] and vis[i][1] < vis2[i][1] or
         vis[i][m] < vis1[i][m] and vis[i][m] < vis2[i][m]) ok = true;

    for(int i = 1; i <= m; i++)
      if(vis[1][i] < vis1[1][i] and vis[1][i] < vis2[1][i] or
         vis[n][i] < vis1[n][i] and vis[n][i] < vis2[n][i]) ok = true;

    if(ok) cout << "YES" << '\n';
    else cout << "NO" << '\n';
  }
}
