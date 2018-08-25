#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " << 
typedef long long ll;
const int N = 3e5 + 5;
const int M = 21;

int n, m, k;

int cnt[N];
int f[N];
int par[N], sz[N];
int ps[N];

bool even[N];
vector<int> adj[N];
vector<pair<int, int>> ans;

int find(int a) { return par[a] == a ? a : par[a] = find(par[a]); }
void unite(int a, int b){
  if((a = find(a)) == (b = find(b))) return;
  if(sz[a] < sz[b]) swap(a, b);
  par[b] = a; sz[a] += sz[b];
}

int dfs(int n){
  int sum = even[n];
  for(auto x : adj[n])
    if(x != f[n]){
      f[x] = n;
      int amt = dfs(x);
      if(amt&1) ans.push_back({n, x});
      sum += amt;
    }

  return sum;
}

int main(){
  cin.tie(0), ios_base::sync_with_stdio(false);

  cin >> n >> m >> k;

  for(int i = 1; i <= n; i++)
    par[i] = i, sz[i] = 1;

  for(int i = 0; i < m; i++){
    int u, v;
    cin >> u >> v;
    cnt[u]++, cnt[v]++;
  }

  for(int i = 0; i < k; i++){
    int u, v;
    cin >> u >> v;

    if(find(u) != find(v)){
      adj[u].push_back(v);
      adj[v].push_back(u);
      unite(u, v);
    }
  }

  for(int i = 1; i <= n; i++)
    if(cnt[i]&1) even[i] = true;

  for(int i = 1; i <= n; i++){
    if(i != par[i]) continue;
  }

  for(int i = 1; i <= n; i++){
    if(i != par[i]) continue;

    int sum = dfs(i);
    if(sum&1) return cout << "NO\n", 0;
  }

  cout << "YES\n";
  cout << ans.size() << '\n';
  for(auto p : ans)
    cout << p.st << ' ' << p.nd << '\n';
}
