#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " << 
typedef long long ll;
const int N = 105;
vector<int> adj[N], nadj[N];

bool vis[N]; //1 not change, 2 change
bool ch[N];

bool dfs(int n, bool t){
  if(vis[n]) return t == ch[n];
  vis[n] = true;
  ch[n] = t;
  bool ans = true;

  for(auto x : adj[n]) ans &= dfs(x, t);
  for(auto x : nadj[n]) ans &= dfs(x, !t);

  return ans;
}

int main(){
  int n, m;
  cin >> n >> m;
  for(int i = 0; i < m; i++){
    int a, b, c;
    cin >> a >> b >> c;
    if(c) adj[a].push_back(b), adj[b].push_back(a);
    else nadj[a].push_back(b), nadj[b].push_back(a);
  }

  for(int i = 1; i <= n; i++)
    if(!vis[i])
      if(!dfs(i, 0)) return cout << "Impossible\n", 0;

  vector<int> ans;
  for(int i = 1; i <= n; i++)
    if(ch[i]) ans.push_back(i);

  cout << ans.size() << endl;
  for(auto x : ans) cout << x << ' ';
  cout << endl;
}
