#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " << 
typedef long long ll;
const int N = 2e3 + 5;
const int M = 505;
char g[N][N];
short int id[N][N];

int vis[2*M];
int x, b[2*M];
vector<int> adj[2*M];

bool match(int u){
  if(vis[u] == x) return 0;
  vis[u] = x;
  for(int v : adj[u])
    if(!b[v] or match(b[v])) return b[v] = u;
  return 0;
}

int main(){
  cin.tie(0), ios_base::sync_with_stdio(false);
  int t;
  cin >> t;

  while(t--){
    memset(vis, 0, sizeof vis);
    memset(g, 0, sizeof g);
    memset(b, 0, sizeof b);
    for(int i = 0; i < 2*M; i++)
      adj[i].clear();
    x = 0;

    int h, v;
    cin >> h >> v;

    for(int i = 1; i <= h; i++){
      int x, y;
      string s;

      cin >> x >> y >> s;
      for(int j = 0; j < s.size(); j++)
        g[x + j][y] = s[j], id[x + j][y] = i;
    }

    for(int i = 1; i <= v; i++){
      int x, y;
      string s;
      cin >> x >> y >> s;

      for(int j = 0; j < s.size(); j++){
        if(g[x][y + j] != 0 and g[x][y + j] != s[j])
          adj[id[x][y + j]].pb(i + M);
      }
    }

    int ans = 0;
    for(int i = 1; i <= v; i++)
      ++x, ans += match(i);

    cout << h + v - ans << '\n';
  }
}
