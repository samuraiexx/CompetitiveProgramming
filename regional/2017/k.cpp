#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl;
#define _ << ", " << 
typedef long long ll;
const int N = 25;
int x, vis[N][N], ans;
pair<int, int> b[N][N];
vector<pair<int, int>> adj[N][N];

char g[N][N];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, -1, 1};

bool match(pair<int, int> u){
  if(vis[u.st][u.nd] == x) return 0;
  vis[u.st][u.nd] = x;
  for(auto v : adj[u.st][u.nd])
    if(!b[v.st][v.nd].st or match(b[v.st][v.nd]))
      return b[v.st][v.nd] = u, true;
  return 0;
}

int main(){
  cin.tie(0), ios_base::sync_with_stdio(false);

  int r, c;
  cin >> r >> c;

  memset(g, '#', sizeof g);

  map<pair<int, int>, int> s;
  int cnt = 0;

  for(int i = 1; i <= r; i++)
    for(int j = 1; j <= c; j++){
      cin >> g[i][j];
      if(g[i][j] == 'o') s[{i, j}] = cnt++;
    }

  if(s.size()&1) return cout << "N\n", 0;

  vector<bool> v(s.size());
  for(int i = s.size()/2; i < s.size(); i++) v[i] = 1;

  do{
    ans = x = 0;
    memset(vis, 0, sizeof vis);
    memset(b, 0, sizeof b);
    for(int i = 1; i <= r; i++)
      for(int j = 1; j <= c; j++)
        b[i][j] = {0, 0}, adj[i][j].clear();

    for(int i = 1; i <= r; i++)
      for(int j = 1; j <= c; j++){
        if(s.count({i, j}) and !v[s[{i, j}]])
          continue;

        for(int k = 0; k < 4; k++){
          int x = i + dx[k];
          int y = j + dy[k];
          if(g[x][y] == '#' or s.count({x, y}) and v[s[{x, y}]])
            continue;

          adj[i][j].pb({x, y});
        }
      }

    for(int i = 1; i <= r; i++)
      for(int j = 1; j <= c; j++)
        ++x, ans += match({i, j});

    if(ans == c*r - s.size()/2)
      return cout << "Y\n", 0;
  } while (next_permutation(v.begin(), v.end()));
  cout << "N\n";
}
