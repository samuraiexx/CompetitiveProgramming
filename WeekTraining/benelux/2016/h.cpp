#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl;
#define _ << ", " << 
vector<ll> divs;

map<pair<ll, ll>, vector<ll>> dp;

vector<ll> exp(ll i, ll n){
  //db(i _ n);
  auto p = make_pair(i, n);
  vector<ll> t1, t2, ret;

  if(dp.count(p)) return dp[p];
  if(n == 1) return dp[p] = ret;
  if(i == divs.size()) return vector<ll>({-1});

  ll amt = 0;

  t1 = exp(i + 1, n);
  while(n%divs[i] == 0) t2.pb(divs[i]), amt++, n/=divs[i];
  if(!amt) return dp[p] = t1;
  ret = exp(i + 1, n);
  if(ret.size() and ret[0] == -1) return dp[p] = t1;

  for(auto x : ret) t2.pb(x);

  if(t1.size() and t1[0] == -1) return dp[p] = t2;

  return dp[p] = (t1.size() < t2.size() ? t1 : t2);
}

int main(){
  ll b, n;
  vector<ll> dig;
  cin >> b >> n;
  for(ll i = b - 1; i >= 2; i--)
    if(n%i  == 0) divs.pb(i);

  db(divs.size());
  auto v = exp(0, n);
  if(v[0] == -1) return cout << "impossible" << endl, 0;
  
  ll ac = 1;
  ll ans = 0;
  for(auto x : v) ans += x*ac, ac = b*ac;
  cout << ans << endl;
}
