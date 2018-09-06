#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " << 
typedef long long ll;
const int INF = 0x3f3f3f3f;
const int N = 1e3 + 5;
int dp[N][N];
pair<int, int> v[N];

int main(){
  int n;
  cin >> n;

  for(int i = 0; i < n; i++)
    cin >> v[i].nd >> v[i].st;

  sort(v, v + n);

  memset(dp, 0x3f, sizeof dp);

  if(v[0].st >= v[0].nd)
    dp[0][1] = v[0].nd;
  dp[0][0] = 0;

  for(int i = 1; i < n; i++){
    dp[i][0] = 0;
    for(int j = 1; j < n; j++){
      dp[i][j] = dp[i - 1][j];
      if(v[i].st < v[i].nd) continue;

      int p = dp[i - 1][j - 1] + v[i].nd;
      if(p <= v[i].st)
        dp[i][j] = min(dp[i][j], p);
    }
  }

  int ans = 0;
  for(int i = 0; i < n; i++){
    if(dp[n - 1][i] < INF) ans = i;
  }

  cout << ans << endl;
}
