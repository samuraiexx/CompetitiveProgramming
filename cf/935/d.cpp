#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define st first
#define nd second

ll MOD = 1e9 + 7;

ll fexp(ll a, ll b, ll m = MOD) {
  ll ret = 1;
  while(b){
    if(b%2) ret = (ret*a)%m, b--;
    else a = (a*a)%m, b /= 2;
  }
  return ret;
}

int main(){
  ll n, m;
  vector<ll> s1, s2;
  cin >> n >> m;
  for(ll i = 0, a; i < n; i++) cin >> a, s1.pb(a);
  for(ll i = 0, a; i < n; i++) cin >> a, s2.pb(a);

  ll overm = fexp(m, MOD-2);

  ll acc = 1, ans = 0;
  bool allz = 1;
  for(ll i = 0; i < n; i++){
    if(s1[i] == s2[i] and s1[i] == 0) continue;
    allz = 0;
    
    if(s1[i] == s2[i]) continue;

    if(s1[i] == 0) ans = (ans + (acc*(overm*(m - s2[i]))%MOD)%MOD)%MOD,
                   acc = (acc*overm)%MOD;
    else if(s2[i] == 0) ans = (ans + (acc*(overm*(s1[i] - 1))%MOD)%MOD)%MOD,
                   acc = (acc*overm)%MOD;
    else if(s1[i] > s2[i]) { ans = (ans + acc)%MOD; break; }
    else if(s1[i] < s2[i]) break;
  }
  if(allz) cout << (fexp(2, MOD-2) + (MOD - fexp(fexp(m, MOD-2), n))%MOD)%MOD << endl;
  else cout << ans << endl;
}
