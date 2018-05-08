#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " << 
typedef long long ll;
const ll N = 1e5 + 5, M = 1e3 + 5;
ll w[N];
map<ll, ll> f;

int main(){
  ll T;
  cin >> T;
  for(ll t = 1; t <= T; t++){
    ll n, ans = 1;
    cin >> n;

    f.clear();
    for(ll i = 0; i < n; i++) cin >> w[i];

    for(ll i = 0; i < n; i++){
      auto f2 = f;
      f[w[i]] = 1;

      for(auto p : f2)
        if(p.st <= 6*w[i]){
          f[p.st + w[i]] = max(f[p.st + w[i]], 1 + p.nd);
          ans = max(ans, f[p.st + w[i]]);
        }
        else break;
    }
    cout << "Case #" << t << ": ";
    cout << ans << endl;
  }
}
