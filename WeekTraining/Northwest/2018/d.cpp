#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " << 
typedef long long ll;
const int N = 5e4 + 5;

vector<pair<int, int>> adj[N];
map<int, int> cnt[N];
bool eqe[N], ok[N];
int amt[N];
int ans;

void dfs(int u, int f, int c){
  for(auto p : adj[u]) if(p.st != f){
    dfs(p.st, u, p.nd);
    if(p.nd == c) eqe[u] = true;
    else amt[u] += (amt[p.st] > 0);
  }

  amt[f] += eqe[u];
}

void dfs2(int u, int f, int c){
  bool fnok = false;
  if(f > 0)  fnok = (amt[f] - eqe[u] > 0 or cnt[f][c] > 1);
  amt[u] += fnok;
  if(amt[u] == 0) ok[u] = true, ans++;

  for(auto p : adj[u]) if(p.st != f)
    dfs2(p.st, u, p.nd);
}

int main(){
  ios_base::sync_with_stdio(false), cin.tie(0);

  int n;
  cin >> n;
  for(int i = 1; i < n; i++){
    int a, b, c;
    cin >> a >> b >> c;
    adj[a].pb({b, c});
    adj[b].pb({a, c});
    cnt[a][c]++, cnt[b][c]++;
  }

  dfs(1, -1, -1);
  dfs2(1, -1, -1);

  cout << ans << '\n';
  for(int i = 1; i <= n; i++)
    if(ok[i]) cout << i << '\n';
}
