#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " << 
typedef long long ll;

int main(){
  ll n, l;
  cin >> n >> l;

  ll mmc = 1;
  for(int i = 0; i < n; i++){
    ll x;
    cin >> x;
    mmc = mmc*x/__gcd(mmc, x);
  }

  ll ans = 1;
  ll mx = mmc;
  for(ll i = 2; i <= l; i++){
    ll mmc2 = mmc*i/__gcd(mmc, i);
    if(mmc2 > mx && mmc2 <= l)
      ans = i, mx = mmc2;
  }

  cout << ans << endl;
}
