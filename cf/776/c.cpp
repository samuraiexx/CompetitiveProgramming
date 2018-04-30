#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " << 
typedef long long ll;
const ll N = 1e5 + 5;

int main(){
  ll n, k;
  cin >> n >> k;

  vector<ll> pot;
  ll p = 1;
  if(abs(k) > 1){
    while(abs(p) <= (long long)1e16){
      pot.push_back(p);
      p = p*(long long)k;
    }
  } else {
    pot.push_back(1);
    if(k == -1) pot.push_back(-1);
  }

  map<ll, ll> prev;
  prev[0] = 1;
  ll ans = 0;

  ll sum = 0;
  for(ll i = 0; i < n; i++){
    ll x;
    cin >> x;
    sum += x;

    for(auto x : pot)
      if(prev.count(sum - x))
        ans += prev[sum - x];

    prev[sum]++;
  }

  cout << ans << endl;
}
