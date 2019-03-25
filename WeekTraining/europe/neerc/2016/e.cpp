#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " << 
typedef long long ll;
const ll N = 1e5 + 5;
pair<ll, ll> v[N];

int main(){
  cin.tie(0), ios_base::sync_with_stdio(false);
  freopen("expect.in", "r", stdin);
  freopen("expect.out", "w", stdout);

  map<ll, ll> amt;
  ll n, q;
  cin >> n >> q;

  ll sum = 0;
  ll lst = 0;
  for(ll i = 0; i < n; i++) {
    char c;
    ll t, k;
    cin >> c >> t >> k;

    if(sum < 0) amt[sum] += t - lst;
    lst = t;

    if(c == '+') sum += k;
    else sum -= k;
  }
  if(sum < 0) amt[sum] = -1;

  for(ll i = 0; i < q; i++){
    ll b;
    cin >> b;
    v[i] = {-b, i};
  }
  sort(v, v + q);

  auto it = amt.begin();
  ll ans = 0;
  sum = 0;
  lst = 0;
  for(ll i = 0; i < q; i++){
    ll b = v[i].st;

    if(ans >= 0) ans += sum*(b - lst);
    lst = b;
    while(it != amt.end() and ans >= 0 and it->st < b) {
      ll x = it->st;
      ll y = it->nd;
      sum += it->nd;
      ans += it->nd*(b - it->st);
    
      if(y == -1) ans = -1;
      it++;
    }

    v[i] = {v[i].nd, ans};
  }
  sort(v, v + q);

  for(ll i = 0; i < q; i++){
    if(v[i].nd == -1) cout << "INFINITY\n";
    else cout << v[i].nd << '\n';
  }
}
