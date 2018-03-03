#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define st first
#define nd second
typedef long long ll;
const ll N = 3e5 + 5;
ll el[N];
ll id[N];

int main(){
  ll n, q;
  cin >> n >> q;
  for(ll i = 1; i <= n; i++)
    cin >> el[i];

  for(ll i = 0; i < q; i++){
    ll l, r;
    ll a = 0, b , c;
    cin >> l >> r;
    ll range = min(100ll, r - l + 1);
    for(ll i = l; i < l + range; i++)
      id[i] = i;

    sort(id + l, id + l + range, [] (ll a, ll b) { return el[a] < el[b]; });
    for(ll i = l; i < l + range; i++)
      if(el[id[i]] + el[id[i + 1]] > el[id[i + 2]])
        a = id[i], b = id[i + 1], c = id[i + 2];

    if(a) cout << a << ' ' << b << ' ' << c << endl;
    else cout << -1 << endl;
  }
}
