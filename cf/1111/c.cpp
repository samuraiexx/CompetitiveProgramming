#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " << 
typedef long long ll;
const ll N = 1e5 + 5;
ll v[N];
ll n, k, a, b;

ll ans(ll l, ll r){
  ll amt = upper_bound(v, v + k, r) - lower_bound(v, v + k, l);
  if(amt == 0) return a;
  if(l == r) return b*amt;

  ll mid = (l + r)/2;
  return min(b*amt*(r - l + 1), ans(l, mid) + ans(mid + 1, r));
}

int main(){
  cin.tie(0), ios_base::sync_with_stdio(false);
  cin >> n >> k >> a >> b;
  for(ll i = 0; i < k; i++)
    cin >> v[i];

  sort(v, v + k);

  cout << ans(1, 1ll << n) << '\n';
}
