#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl;
#define _ << ", " << 
const int N = 2e5 + 5;
vector<int> adj[N];
int f[2][N];
int col[N];

bool dfs(int n){
  if(col[n] == 2) return false;
  if(col[n] == 1) return true;
  bool ret = 0;
  col[n] = 1;
  for(auto a : adj[n]) {
    ret = ret|dfs(a);
  }
  col[n] = 2;
  return ret;
}

int main(){
  int n, m, s;
  cin >> n >> m;
  for(int i = 1; i <= n; i++){
    int c;
    cin >> c;
    for(int j = 0, a; j < c; j++)
      cin >> a, adj[i].pb(a);
  }
  cin >> s;

  queue<pair<bool, int>> q;
  int ed = -1;
  q.push({0, s});
  
  while(q.size()){
    auto x = q.front(); q.pop();
    if(x.st and adj[x.nd].size() == 0) { ed = x.nd; break; }

    for(auto a : adj[x.nd])
      if(!f[!x.st][a])
        q.push({!x.st, a}), f[!x.st][a] = x.nd;
  }

  if(ed != -1){
    vector<int> path;
    bool p = 1;
    while(ed != s or path.size()%2 == 0) path.pb(ed), ed = f[p][ed], p = !p;
    path.pb(s);
    cout << "Win" << endl;
    for(int i = path.size() - 1; i >= 0; i--)
      cout << path[i] << " \n"[i == 0];
  }
  else if(dfs(s)) cout << "Draw" << endl, 0;
  else cout << "Lose" << endl, 0;
}
