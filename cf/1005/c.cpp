#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " << 
typedef long long ll;

int main(){
  ll n;
  map<ll, ll> el;
  cin >> n;
  for(ll i = 0; i < n; i++){
    ll x; 
    cin >> x;
    el[x]++;
  }
  ll ans = 0;

  for(auto p : el){
    ll x = p.st;
    bool ok = false;
    for(ll i = 0; i < 32; i++){
      ll y = (1 << i) - x;
      if(el.count(y) and (y != x or p.nd > 1)){
        ok = true;
      }
    }

    if(!ok) ans += p.nd;
  }

  cout << ans << endl;
}
