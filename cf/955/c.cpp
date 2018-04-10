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

ll bs(ll x, ll b){
  ll l = 1, r = 1e9;
  if(b > 2) r = 1e6;
  if(b > 5) r = 1e3;

  while(l != r){
    ll mid = (l + r)/2;
    if(fexp(mid, b) > x) r = mid;
    else l = mid + 1;
  }
  return max(0ll, l - 2);
}

int main(){
  cin.tie(0), ios_base::sync_with_stdio(false);
  ll q;
  cin >> q;
  while(q--){
    ll l, r;
    cin >> l >> r;
    ll ans = 0;
    for(int i = 2; i <= 63; i++){
      ans -= (bs(r, i) - bs(l - 1, i))*mobius(i);
      if(i == 2) db(l _ r _ ans);
    }
    if(l == 1) ans++;

    cout << ans << '\n';
  }
}
