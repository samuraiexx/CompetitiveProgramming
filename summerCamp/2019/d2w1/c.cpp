#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " << 
typedef long long ll;
const ll INF = 0x3f3f3f3f3f3f3f3f;
const int N = 2e3 + 5;
ll dp[N][N];
pair<ll, ll> v[N];
ll pt[N], pp[N];

int main(){
  int n, t;
  cin >> n >> t;

  memset(dp, 0x3f, sizeof dp);

  for(int i = 1, t, p; i <= n; i++)
    cin >> t >> p, v[i] = {t, p};

  sort(v + 1, v + n + 1);

  for(int i = 1; i <= n; i++){
    pt[i] = pt[i - 1] + v[i].st;
    pp[i] = pp[i - 1] + v[i].nd;
  }

  reverse(v + 1, v + n + 1);

  dp[0][0] = 0;
  for(int i = 1; i <= n; i++){
    for(int j = 0; j <= t; j++){
      ll w = j - v[i].st;
      dp[i][j] = dp[i - 1][j];
      if(w >= 0) dp[i][j] = min(dp[i][j], dp[i - 1][w] + v[i].nd);
    }
  }

  v[0] = {INF, 0};

  ll ans = INF;
  for(int i = 0; i <= n; i++){
    ll T = t - pt[n - i];
    ll dt = v[i].st - 1;
    if(T <= 0) continue;

    for(int j = max(0ll, T - dt); j <= T; j++)
      ans = min(ans, pp[n - i] + dp[i][j]);
  }

  cout << ans << endl;
}
