#include<bits/stdc++.h>
#define pb push_back
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " << 

typedef long long ll;
using namespace std;
const ll N = 1e5 + 5;

vector<ll> adj[N];
ll pos[N], neg[N];
ll v[N];

void dfs(ll n, ll f){
  for(auto x : adj[n])
    if(x != f){
      dfs(x, n);
      neg[n] = max(neg[n], neg[x]);
      pos[n] = max(pos[n], pos[x]);
   }
  ll d = v[n] + pos[n] - neg[n];
  if(d > 0)
    neg[n] += d;
  else pos[n] -= d;
  //db(n _ f _ pos[n] _ neg[n]);
}

int main(){
  ll n;
  cin >> n;

  for(ll i = 0; i < n - 1; i ++){
    ll a, b;
    cin >> a >> b;
    adj[a].pb(b), adj[b].pb(a);
  }

  for(ll i = 1; i <= n; i++)
    cin >> v[i];

  dfs(1, 0);
  cout << neg[1] + pos[1] << endl;
}
