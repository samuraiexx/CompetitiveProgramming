#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " << 
typedef long long ll;
const int N = 1e4 + 5;

vector<int> adj[N];
int low[N], id[N], ch[N];
bool art[N];
int t;

void dfs(int n, int f){
  if(id[n]) return;
  low[n] = id[n] = ++t;

  for(int x : adj[n])
    if(!id[x]){
      if(!id[x]) ch[n]++;
      dfs(x, n);
      low[n] = min(low[n], low[x]);
      if(low[x] >= id[n]) 
        art[n] = true;
    }else if(x != f)
      low[n] = min(low[n], id[x]);
}

int main(){
  int n, m;
  while(cin >> n >> m, n or m){
    for(int i = 1; i <= n; i++) adj[i].clear();
    memset(id, 0, sizeof id);
    memset(art, 0, sizeof art);
    memset(ch, 0, sizeof ch);
    t = 0;

    for(int i = 0; i < m; i++){
      int a, b;
      cin >> a >> b;
      adj[a].push_back(b);
      adj[b].push_back(a);
    }

    dfs(1, 0), art[1] = ch[1] > 1;

    int ans = 0;
    for(int i = 1; i <= n; i++)
      if(art[i]) ans++;

    cout << ans << endl;
  }
}
