#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " << 
typedef long long ll;
const ll N = 1e5 + 5;
tuple<ll, ll, ll> val[N];

int main(){
  cin.tie(0), ios_base::sync_with_stdio(false);

  ll n;
  cin >> n;

  ll x1, x2;
  cin >> x1 >> x2;

  for(ll i = 0; i < n; i++){
    ll k, b;
    cin >> k >> b;

    val[i] = {k*x1 + b, k*x2 + b, i};
  }

  sort(val, val + n);
  for(ll i = 0; i < n; i++){
    ll v1, v2, id;
    tie(v1, v2, id) = val[i];
    val[i] = {v2, v1, i};
  }

  stable_sort(val, val + n);

  bool ok = false;
  for(ll i = 0; i < n; i++){
    ll v1, v2, id;
    tie(v1, v2, id) = val[i];

    ok |= id != i;
  }

  cout << (ok ? "YES" : "NO") << endl;
}
