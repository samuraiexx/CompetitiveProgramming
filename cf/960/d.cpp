#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " << 
typedef long long ll;
map<ll, ll> ns, ts;

ll lv(ll x){
  return 63 - __builtin_clzll(x);
}

ll rot(ll x, ll k){
  ll b = (1ll << lv(x));
  x -= b;
  x = (x + k + b)%b;
  return x + b;
}

int main(){
  //db(rot(5, -3));
  ll q;
  cin >> q;
  while(q--){
    ll t;
    cin >> t;

    if(t == 1){
      ll x;
      ll k;
      cin >> x >> k;
      ll n = lv(x);
      ll mod = (1ll << n);

      k = (k + mod)%mod;
      ns[n] = (ns[n] + k)%mod;

    } else if(t == 2){
      ll x;
      ll k;
      cin >> x >> k;
      ll n = lv(x);
      ll mod = (1ll << n);

      k = (k + mod)%mod;
      ts[n] = (ts[n] + k)%mod;
    } else {
      ll x;
      cin >> x;

      cout << x << ' ';
      x = rot(x, ns[lv(x)]);
      x = rot(x, ts[lv(x)]);
      x /= 2;

      while(x){
       // db(x);
        ll n = lv(x);
        if(ns.count(n)) cout << rot(x, -ns[n]) << ' ';
        else cout << x << ' ';
        if(ts.count(n)) x = rot(x, ts[n]);
        x /= 2;
      }
      cout << endl;
    }
  }

}
