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
  cin >> n;
  n--;
  ll ans = 0;
  ll lz = __builtin_clzll(n);
  db(lz);
  for(int i = 0; i < 64 - lz - 1; i++){
    ll n = (1ll << i);
    db(n);
    ans += (1 + n)*n/2;
    db((1 + n)*n/2);
  }
  ans += (1ll << 64 - lz - 1);
  n -= (1ll << 64 - lz - 1);
  db(n);
  ans += (1 + n)*n/2;
  
  cout << ans << endl;
}
