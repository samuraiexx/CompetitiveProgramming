#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll p = 1e9 + 7;
ll fexp(ll a, ll b){
  ll pot = 1;
  while(b)
    if(b%2) pot = (pot * a)%p, b--;
    else a = (a*a)%p, b/=2;

  return pot;
}

ll disc_log(ll a, ll b){
  ll n = sqrt(p) + 2;
  map<ll, ll> qval;
  for(ll i = 0; i < n; i++)
    qval[(fexp(a, i)*b)%p] = i;
  for(ll i = 1; i <= n; i++){
    ll pval = fexp(a, (i*n)%p);
    if(qval.count(pval)) return n*i - qval[pval];
  }
  return -1;
}

int main(){
  ll x0, a, b, x;
  cin >> p >> x0 >> a >> b >> x;
  if(x == x0) return cout << 0 << endl, 0;
  if(a == 0)
    if(x == b) return cout << 1 << endl, 0;
    else return cout << "NIE" << endl, 0;
  if(a == 1)
    if(b == 0) return cout << "NIE" << endl, 0;
    else return cout << (((x + (p - x0))%p)*fexp(b, p - 2))%p << endl, 0;

  ll div = (((x0*a)%p + b)%p + (p - x0))%p;
  ll v = ((((x*a)%p + b)%p + (p - x))%p*fexp(div, p - 2))%p;

  if(v != -1) cout << disc_log(a, v) << endl;
  else cout << "NIE" << endl;
  return 0;
}
