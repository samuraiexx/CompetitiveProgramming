#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " << 
typedef long long ll;
const int N = 3e5 + 5;
vector<int> adj[N];
int c[N];
pair<int, int> amt[N];
int cnt[2];

int ans = 0;
void dfs(int u, int f){
  if(c[u] == 1) amt[u].st++;
  if(c[u] == 2) amt[u].nd++;

  for(auto v : adj[u]) if(v != f){
    dfs(v, u);
    amt[u].st += amt[v].st;
    amt[u].nd += amt[v].nd;
  }

  ans += amt[u].st == cnt[0] and amt[u].nd == 0;
  ans += amt[u].st == 0 and amt[u].nd == cnt[1];
}

int main(){
  cin.tie(0), ios_base::sync_with_stdio(false);
  int n;
  cin >> n;

  for(int i = 1; i <= n; i++){
    cin >> c[i];
    if(c[i]) cnt[c[i] - 1]++;
  }

  for(int i = 1; i < n; i++){
    int u, v;
    cin >> u >> v;
    adj[u].pb(v);
    adj[v].pb(u);
  }
  
  dfs(1, -1);
  cout << ans << endl;
}
