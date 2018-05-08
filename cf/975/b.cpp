#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " << 
typedef long long ll;
const ll N = 15;
ll v[N], tmp[N];

int main(){
  ll ans = 0;
  for(ll i = 0; i < 14; i++) cin >> v[i];
  for(ll i = 0; i < 14; i++) if(v[i]){
    ll x = v[i]/14, y = v[i]%14;
    ll tans = 0;

    for(ll j = 0; j < 14; j++)
      if(j != i) tmp[j] = v[j] + x;
      else tmp[j] = x;

    for(ll j = 0; j < y; j++)
      tmp[(i + j + 1)%14]++;

    for(ll i = 0; i < 14; i++)
      if(tmp[i]%2 == 0) tans+= tmp[i]; 
    ans = max(ans, tans);

  }
  cout << ans << endl;
}
