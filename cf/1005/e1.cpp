#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " << 
typedef long long ll;
const ll N = 2e5 + 5;
ll v[N];
ll cnt[N];

int main(){
  ll n, m;
  cin >> n >> m;
  ll x = -1;
  for(ll i = 0; i < n; i++){
    cin >> v[i];
    if(v[i] == m) x = i;
    else if(v[i] < m) cnt[i] = -1;
    else cnt[i] = 1;
  }

  if(x == -1) cout << 0 << endl, 0;


  map<ll, ll> mp;
  ll ans = 1;
  mp[0]++;

  for(ll i = x + 1; i < n; i++){
    cnt[i] += cnt[i - 1], mp[cnt[i]]++;

    if(cnt[i] == 0 or cnt[i] == 1) ans++;
  }

  for(ll i = x - 1; i >= 0; i--){
    cnt[i] += cnt[i + 1];

    ans += mp[1 - cnt[i]];
    ans += mp[-cnt[i]];
  }

  cout << ans << endl;

}
