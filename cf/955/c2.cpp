#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " << 
typedef long long ll;
ll INF = 0x3f3f3f3f3f3f3f3f;

ll mobius(ll n){
  ll p = 0;
  ll tmp = n;
  for(ll i = 2; i*i <= n; i++)
    if(n%i == 0){
      n /= i;
      p++;
      if(n%i == 0) return 0;
    }
  return p&1 ? 1 : -1;
}

ll fexp(ll a, ll b){
  ll ans = 1;
  while(b){
    if(b&1){
      if(a > INF/ans) return INF;
      ans *= a;
      b--;
    }
    if(a > INF/a and b) return INF;
    a *= a, b /= 2;
  }
  return ans;
}

ll sroot(ll x){
  ll l = 1, r = 1e9;
  while(l != r){
    ll mid = (l + r)/2;
    if(mid*mid > x) r = mid;
    else l = mid + 1;
  }
  return l - 1;
}

vector<ll> v;
set<ll> divs;

int main(){
  cin.tie(0), ios_base::sync_with_stdio(false);
  for(ll j = 2; j <= 1e6; j++)
    for(ll i = 3; i <= 61; i++){
      ll x = fexp(j, i);
      if(x > 1e18) break;
      ll r = sroot(x);
      if(x != r*r) divs.insert(x);
    }

  for(auto x : divs)
    v.pb(x);
      
  ll q;
  cin >> q;
  while(q--){
    ll l, r;
    cin >> l >> r;
    ll ans = sroot(r) - sroot(l - 1);
    ans += upper_bound(v.begin(), v.end(), r) - lower_bound(v.begin(), v.end(), l);

    cout << ans << '\n';
  }
}
