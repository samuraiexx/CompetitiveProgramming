#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define st first
#define nd second
const ll N = 1e5;
const ll M = 1e9 + 5;

int main(){
  ll n;
  cin.tie(0), ios_base::sync_with_stdio(false);
  map<ll, ll> sqr;
  for(int i = 1; i*i < M; i++) sqr[i*i] = i;
  cin >> n;
  for(ll i = 0; i < n; i++){
      ll ans = 0;
      ll ans2;
      ll x;
      cin >> x;
      for(auto p : sqr){
        int a = p.first;
        if(sqr.count(x + a)){
          ans = sqr[x + a];
          for(int i = 2; i < ans; i++) if(ans/i == p.second) ans2 = p.second;
        }
      }
      if(ans and ans2) cout << ans << ' ' << ans << endl;
      else cout << -1 << endl;
  }
}
