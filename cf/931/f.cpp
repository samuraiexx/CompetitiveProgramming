#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " == " << x << endl
#define _ << ", " << 
const ll N = 1e5 + 5;
ll lr[N], rl[N];
ll dp[N], lis[N], lis2[N];

int main(){
  ll n, m;
  cin >> n >> m;
  for(ll i = 0, l, r; i < n; i++)
    cin >> l >> r, lr[l]++, lr[r + 1]--, rl[r]++, rl[l - 1]--;

  for(ll i = 1; i <= m; i++)
    lr[i] += lr[i - 1];
  for(ll i = m - 1; i > 0; i--)
    rl[i] += rl[i + 1];

  for(ll i = 1; i <= m/2; i++)
    swap(rl[i], rl[m - i + 1]);

  memset(dp, 63, sizeof dp);
  for (ll i=1; i<=m; ++i) {
    ll j = upper_bound(dp, dp+lis[i - 1], lr[i]) - dp;
    dp[j] = min(dp[j], lr[i]);
    lis[i] = max(lis[i - 1], j+1);
  }

  memset(dp, 63, sizeof dp);
  for (ll i=1; i<=m; ++i) {
    ll j = upper_bound(dp, dp+lis2[i - 1], rl[i]) - dp;
    dp[j] = min(dp[j], rl[i]);
    lis2[i] = max(lis2[i - 1], j+1);
  }

  for(ll i = 1; i <= m/2; i++)
    swap(lis2[i], lis2[m - i + 1]);

  ll ans = 0;
  for(ll i = 0; i <= m; i++)
    ans = max(ans, lis[i] + lis2[i] - 1);

  cout << ans << endl;
}
