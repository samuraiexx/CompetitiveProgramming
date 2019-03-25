#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " << 
typedef long long ll;
const int N = 16;
const int M = 1 << N;
bool dp[M][N];
vector<int> adj[N];
char v[N];
int pos[256];

int main(){
  int T;
  cin >> T;
  for(int t = 1; t <= T; t++){
    cout << "Case " << t << ": ";

    int n, m;
    cin >> n >> m;
    memset(dp, 0, sizeof dp);
    for(int i = 0; i < n; i++)
      adj[i].clear();

    for(int i = 0; i < n; i++)
      cin >> v[i];

    int bg = v[0], ed = v[n - 1];

    sort(v, v + n);
    for(int i = 0; i < n; i++)
      pos[v[i]] = i;

    for(int i = 0; i < m; i++){
      char a, b;
      cin >> a >> b;
      adj[pos[a]].pb(pos[b]);
      adj[pos[b]].pb(pos[a]);
    }

    dp[1 << pos[ed]][pos[ed]] = true;

    for(int i = 0; i < (1 << n); i++){
      for(int j = 0; j < n; j++){
        if(!dp[i][j]) continue;

        for(auto x : adj[j]){
          int msk = i|(1 << x);
          if(msk != i)
            dp[msk][x] = true;
        }
      }
    }

    int msk = (1 << n) - 1 - (1 << pos[bg]);
    int lst = pos[bg];
    
    string s;
    s.pb(bg);
    bool ok = true;

    while(msk){
      int mn = 'Z' + 1;

      for(auto i : adj[lst])
        if(msk&(1 << i) && dp[msk][i]) mn = min(mn, i);

      if(mn == 'Z' + 1){ ok = false; break; }
      
      s.pb(v[mn]);
      msk ^= (1 << mn);
      lst = mn;
    }

    if(!ok) cout << "impossible\n";
    else cout << s << '\n';
  }
}
