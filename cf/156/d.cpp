#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " << 
typedef long long ll;
const ll N = 1e5 + 5;
vector<ll> adj[N];
bool vis[N];
ll n, m, k;

ll dfs(ll u){
  if(vis[u]) return 0;
  vis[u] = true;

  ll ret = 1;
  for(auto v : adj[u])
    ret += dfs(v);
  return ret;
}

ll fexp(ll a, ll b){
  ll ans = 1;
  while(b)
    if(b&1) ans = (ans*a)%k, b--;
    else a = (a*a)%k, b/=2;
  return ans;
}

int main(){
  cin.tie(0), ios_base::sync_with_stdio(false);
  cin >> n >> m >> k;

  for(ll i = 0; i < m; i++){
    ll a, b;
    cin >> a >> b;
    adj[a].pb(b);
    adj[b].pb(a);
  }

  vector<ll> v;
  for(ll i = 1; i <= n; i++){
    ll amt = dfs(i);
    if(amt > 0) v.pb(amt);
  }
  if(v.size() == 1) return cout << 1%k << endl, 0;
  ll ans = fexp(n, v.size() - 2);
  for(auto x : v)
    ans = (ans*x)%k;

  cout << ans << endl;
}
