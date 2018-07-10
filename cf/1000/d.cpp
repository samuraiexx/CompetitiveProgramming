#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " << 
typedef long long ll;
const ll N = 1e3 + 5;
const ll mod = 998244353;

ll fac[N], ifac[N];
ll ans[N];
ll v[N];

ll fexp(ll a, ll b){
  ll ans = 1;
  while(b)
    if(b&1) b--, ans = (ans * a)%mod;
    else b/=2, a = (a*a)%mod;

  return ans;
}

int main(){
  fac[0] = ifac[0] = 1;
  ll sum = 0;
  
  for(ll i = 1; i < N; i++)
    fac[i] = (fac[i - 1]*i)%mod,
    ifac[i] = fexp(fac[i], mod - 2);

  ll n;
  cin >> n;

  for(ll i = 0; i < n; i++)
    cin >> v[i];

  for(ll i = 0; i < n; i++){
    if(v[i] > 0){
      for(ll j = i + v[i]; j < n; j++){
        ll starti = (1 + sum)%mod;
        ll endj = (fac[j - i - 1]*((ifac[j - i - v[i]]*ifac[v[i] - 1])%mod))%mod;
        ans[j] = (ans[j] + (starti*endj)%mod)%mod;
      }
    }

    sum = (sum + ans[i])%mod;
  }


  cout << sum << endl;
}
