#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " << 
typedef long long ll;
typedef unsigned long long ull;
ll fat[25];
ull pot[25];
ll dp[25][5];

ll amt(ull mx, int nz){
  if(nz == 0 or mx == 0) return 1;
  if(mx < 10)
    if(nz > 0) return mx + 1;
    else return 1;

  int cnt = 0;
  while(mx >= pot[cnt + 1]) cnt++;

  ll ans = dp[cnt][nz];
  ans += amt(mx - (mx/pot[cnt])*pot[cnt], nz - 1);
  ans += (mx/pot[cnt] - 1)*dp[cnt][nz - 1];

  return ans;
}

int main(){
  fat[0] = 1;
  pot[0] = 1;
  for(int i = 1; i <= 20; i++)
    fat[i] = i * fat[i - 1],
    pot[i] = 10 * pot[i - 1];

  dp[0][0] = dp[0][1] = dp[0][2] = dp[0][3] = 1;

  for(int i = 1; i <= 18; i++){
    dp[i][0] = 1;
    for(int j = 1; j <= 3; j++)
      dp[i][j] = 9*dp[i - 1][j - 1] + dp[i - 1][j];
  }

  int t;
  cin >> t;

  while(t--){
    ll l, r;
    cin >> l >> r;

    cout << amt(r, 3) - amt(l - 1, 3) << endl;

  }
}
