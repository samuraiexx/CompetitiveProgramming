#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll mod;

ll mult(ll a, ll b, ll n = mod){
  if(a == 0 or b == 0) return 0;

  ll ans = 0;

  while(b)
    if(b&1) ans = (ans + a)%n, b--;
    else a = (2*a)%n, b /= 2;

  return ans;
}

ll fexp(ll a, ll b, ll n){
  ll ans = 1;
  while(b)
    if(b&1) ans = mult(ans, a, n), b--;
    else a = mult(a, a, n), b /= 2;

  return ans;
}


bool miller(ll a, ll n) {
  if (a >= n) return 1;
  ll s = 0, d = n-1;
  while (d%2 == 0 and d) d >>= 1, s++;
  ll x = fexp(a, d, n);
  if (x == 1 or x == n-1) return 1;
  for (int r = 0; r < s; r++, x = mult(x,x,n)) {
    if (x == 1) return 0;
    if (x == n-1) return 1;
  }
  return 0;
}

bool isprime(ll n) {
  int base[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};
  for (int i = 0; i < 12; ++i) if (!miller(base[i], n)) return 0;
  return 1;
}

ll pollard_rho(){
  ll c = 1;

  while(1){
    ll x = 2, y = 2;
    while(1){
      x = (mult(x, x) + c)%mod;
      y = (mult(y, y) + c)%mod;
      y = (mult(y, y) + c)%mod;
      ll d = __gcd(abs(x - y + mod), mod);
      if(d == mod) break;
      else if(d > 1) return d;
    }
    c++;
  }
}

int main(){
  ll n;
  while(cin >> n, n){
    vector<ll> ans, fac;
    fac.push_back(n);

    cout << n << " = ";

    while(fac.size()){
      ll x;
      mod = fac.back();
      fac.pop_back();

      if(isprime(mod))
        ans.push_back(mod);
      else
        x = pollard_rho(), fac.push_back(x), fac.push_back(mod/x);
    }


    sort(ans.begin(), ans.end());
    for(int i = 0; i < 2; i++)
      cout << ans[i] << " x ";
    cout << ans.back() << endl;
  }
}
