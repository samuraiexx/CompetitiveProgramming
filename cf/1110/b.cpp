#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " << 
typedef long long ll;
const ll N = 1e5 + 5;
const ll INF = 0x3f3f3f3f3f3f3f3f;
ll v[N], d[N];

int main(){
  cin.tie(0), ios_base::sync_with_stdio(false);
  ll n, m, k;
  cin >> n >> m >> k;
  for(ll i = 0; i < n; i++)
    cin >> v[i];

  for(ll i = 1; i < n; i++)
    d[i - 1] = v[i] - v[i - 1] - 1;
  sort(d, d + n - 1);

  ll x = n;
  ll ans = n;
  for(ll i = 0; i < n - 1 and x > k; i++)
    ans += d[i], x--;

  cout << ans << endl;
}
