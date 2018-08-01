#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " << 
typedef long long ll;
const int N = 1e5 + 5;
const int MOD = 1e9 + 7;
ll dp[55][N];

int main(){
  int t, mn, mx;
  cin >> t >> mn >> mx;

  for(int i = mn; i <= mx; i++)
    dp[t][i] = 1;

  for(int i = t - 1; i > 0; i--)
    for(int j = mn; j <= mx; j++)
      dp[i][j] = (dp[i + 1][j - 1] + dp[i + 1][j + 1])%MOD;

  ll ans = 0;
  for(int i = mn; i <= mx; i++)
    ans = (ans + dp[1][i])%MOD;

  cout << ans << endl;
}
