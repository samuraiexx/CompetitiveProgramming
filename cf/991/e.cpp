#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " << 
typedef long long ll;
ll fac[20];

ll cnt[10];

vector<ll> v;
vector<ll> cnt2;

ll comb(ll i){
  if(i == v.size()){
    ll t = 0;
    for(auto x : cnt2)
      t += x;

    ll s = fac[t];
    for(ll i = 0; i < v.size(); i++)
      s /= fac[cnt2[i]];

    if(v[0] == 0){
      ll z = fac[t - 1];
      for(ll i = 1; i < v.size(); i++)
        z /= fac[cnt2[i]];
      z /= fac[cnt2[0] - 1];

      s -= z;
    }

    return s;
  }

  ll mx = cnt2[i];
  ll ans = 0;

  for(ll j = 1; j <= mx; j++)
    cnt2[i] = j, ans += comb(i + 1);

  return ans;
}

int main(){
  ll n;
  cin >> n;

  fac[0] = 1;
  for(ll i = 1; i < 20; i++)
    fac[i] = fac[i - 1]*i;

  while(n)
    cnt[n%10]++,  n /= 10;

  for(ll i = 0; i < 10; i++)
    if(cnt[i] > 0)
      v.push_back(i), cnt2.push_back(cnt[i]);

  cout << comb(0) << endl;
}
