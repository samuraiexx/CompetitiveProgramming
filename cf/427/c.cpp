#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int N = 1e5 + 5;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;

int c[N];
int vis[N];
vector<vector<int>> scc;

vector<int> adj[N], iadj[N];
stack<int> kosa;

void dfs(int n){
  if(vis[n]) return;
  vis[n] = 1;
  for(auto x : adj[n])
    dfs(x);

  kosa.push(n);
}

void idfs(int n){
  if(vis[n] == 2) return;
  vis[n] = 2;
  scc.back().push_back(n);

  for(auto x : iadj[n])
    idfs(x);
}

int main(){
  int n, m;
  cin >> n;
  for(int i = 1; i <= n; i++)
    cin >> c[i];

  cin >> m;
  for(int i = 0; i < m; i++){
    int a, b;
    cin >> a >> b;
    adj[a].push_back(b);
    iadj[b].push_back(a);
  }

  for(int i = 1; i <= n; i++)
    dfs(i);

  while(kosa.size()){
    int x = kosa.top(); kosa.pop();

    if(vis[x] != 2){
      scc.push_back(vector<int>());
      idfs(x);
    }
  }

  ll ans = 0;
  ll dw = 1;

  for(auto v : scc){
    int mn = INF;
    int cnt = 0;
    for(auto x : v)
      mn = min(mn, c[x]);

    for(auto x : v)
      if(c[x] == mn) cnt++;

    ans += mn;
    dw = (dw*cnt)%mod;
  }

  cout << ans << ' ' << dw << endl;
}
