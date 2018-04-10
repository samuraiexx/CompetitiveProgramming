#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " << 
typedef long long ll;
const ll N = 1e3 + 5;
ll v1[N], v2[N];

ll err(ll x, ll y){
  return (x-y)*(x-y);
}

int main(){
  ll n, k1, k2;
  cin >> n >> k1 >> k2;
  for(ll i = 0; i < n; i++)
    cin >> v1[i];
  for(ll i = 0; i < n; i++)
    cin >> v2[i];

  for(ll i = 0; i < k1; i++){
    ll mx = -1, p;
    for(ll i = 0; i < n; i++){
      ll e = err(v1[i], v2[i]);
      if(e > mx) mx = e, p = i;
    }
    if(v1[p] > v2[p]) v1[p]--;
    else v1[p]++;
  }

  for(ll i = 0; i < k2; i++){
    ll mx = -1, p;
    for(ll i = 0; i < n; i++){
      ll e = err(v1[i], v2[i]);
      if(e > mx) mx = e, p = i;
    }
    if(v2[p] > v1[p]) v2[p]--;
    else v2[p]++;
  }

  ll ans = 0;
  for(ll i = 0; i < n; i++)
    ans += err(v1[i], v2[i]);
  cout << ans << endl;
}

