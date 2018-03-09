#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll mod = 1e9 + 7;

ll fexp(ll a, ll b){
  ll e = 1;
  while(b){
    if(b&1) e = (e * a)%mod;
    a = (a * a)%mod, b/=2;
  }
  return e;
}

int main(){
  cin.tie(0), ios_base::sync_with_stdio(0);
  ll d;
  cin >> d;
  if(d == 0) return cout << 1 << endl, 0;

  ll x = fexp(2, 2*d - 1);
  ll y = fexp(2, d - 1);
  ll z = (y*2)%mod;
  cout << (x - y + z + mod)%mod << '\n';
}
