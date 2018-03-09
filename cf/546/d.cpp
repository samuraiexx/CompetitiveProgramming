#include<bits/stdc++.h>
using namespace std;
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " << 

typedef long long ll;
const ll N = 5e6 + 5;
ll criv[N];
ll cnt[N];

int main(){
  cin.tie(0), ios_base::sync_with_stdio(0);
  ll t;

  for(ll i = 2; i*i < N; i++)
    if(!criv[i])
      for(ll j = i; j < N; j+=i) criv[j] = i;

  for(ll i = 2; i < N; i++){
    ll x = i;
    while(x > 1){
      cnt[i]++;
      if(criv[x]) x /= criv[x];
      else x = 1;
    }
    cnt[i] += cnt[i - 1];
  }

  cin >> t;
  while(t--){
    ll a, b;
    cin >> a >> b;
    cout << cnt[a] - cnt[b] << '\n';
  }
}
