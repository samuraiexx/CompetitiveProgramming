#include<bits/stdc++.h>
#define st first
#define nd second
typedef long long ll;
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;
int sieve[N];

int dp[N][21];
bool vis[N][21];

ll fexp(ll a, int b){
  ll ans = 1;
  while(b)
    if(b&1) ans = (ans * a)%MOD, b--;
    else a = (a*a)%MOD, b/=2;
  return ans;
}

int dpf(int sz, int fac){
  if(vis[sz][fac]) return dp[sz][fac];
  if(fac == 0) return 1;
  if(sz <= 0) return 0;

  vis[sz][fac] = true;
  dp[sz][fac] = (dpf(sz, fac - 1) + dpf(sz - 1, fac))%MOD;

  return dp[sz][fac];
}

int main(){
  ios_base::sync_with_stdio(false), cin.tie(0);
  for(int i = 2; i < N; i++)
    if(!sieve[i])
      for(int j = i; j < N; j+=i)
        sieve[j] = i;

  int q;
  cin >> q;

  while(q--){
    int x, y;
    cin >> x >> y;
    map<int, int> fac;
    while(x > 1)
      fac[sieve[x]]++, x = x/sieve[x];

    ll ans = 1;
    for(auto p : fac)
      ans = (ans * dpf(y, p.nd))%MOD;
    ans = (ans * fexp(2, y - 1))%MOD;

    cout << ans << '\n';
  }
}
