#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " << 
typedef long long ll;
const ll mod = 1e9 + 9;

ll fexp(ll a, ll b){
  ll ans = 1;
  a = a%mod, b = b%(mod - 1);
  while(b)
    if(b&1) b--, ans = (ans * a)%mod;
    else b/=2, a = (a * a)%mod;
  return ans;
}

int main(){
  ll n, a, b, k;
  cin >> n >> a >> b >> k;
  n++;
  string s;
  cin >> s;

  ll z = (b*fexp(a, mod - 2))%mod;
  ll zk = fexp(z, k);

  ll ans = 0;
  for(ll i = 0; i < s.size(); i++){
    char c = s[i];
    ll x = 1;
    if(c == '-') x = mod - 1;

    x = (x*fexp(z, i))%mod;
    ans = (ans + x)%mod;
  }
  ans = (ans*fexp(a, n - 1))%mod;
  ans = (ans*(fexp(z, n) - 1 + mod))%mod;
  ans = (ans*fexp(zk - 1, mod - 2))%mod;
  cout << ans << endl;
}
