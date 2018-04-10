#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " << 
typedef long long ll;
const ll N = 1e5 + 5;
ll g[N];
ll mn[N];
ll c[N];

int main(){
  ll n, k, m;
  memset(mn, 0x3f, sizeof mn);
  map<string, ll> mp;
  cin >> n >> k >> m;

  for(ll i = 1; i <= n; i++){
    string s;
    cin >> s;
    mp[s] = i;
  }

  for(ll i = 1; i <= n; i++) cin >> c[i];

  for(ll i = 0; i < k; i++){
    ll n;
    cin >> n;
    for(ll j = 0, x; j < n; j++)
      cin >> x, g[x] = i, mn[i] = min(mn[i], c[x]);
  }

  ll ans = 0;
  for(ll i = 0; i < m; i++){
    string s;
    cin >> s;
    ll x = mp[s];
    ans += mn[g[x]];
  }
  cout << ans << endl;
}
