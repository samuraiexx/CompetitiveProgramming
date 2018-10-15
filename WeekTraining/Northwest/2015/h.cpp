#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " << 
typedef long long ll;
const int N = 5e3 + 5;
const int M = 25;
const int O = 105;
int s[M];
int dp[N][O];

int main(){
  cin.tie(0), ios_base::sync_with_stdio(false);
  int t;
  cin >> t;
  while(t--){
    memset(dp, -1, sizeof dp);

    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++)
      cin >> s[i];

    for(int i = 0; i < m; i++)
      dp[s[i]][0] = s[i];

    for(int i = 1; i < O; i++){
      for(int k = 0; k < n; k++){
        if(dp[k][i - 1] != -1)
          for(int j = 0; j < m; j++){
            if(k + (i + 1)*s[j] >= N) continue;
            int &x = dp[k + (i + 1)*s[j]][i];
            x = max(x, dp[k][i - 1] + s[j]);
          }
      }
    }

    int ans = -1;
    for(int i = 0; i < O; i++)
      ans = max(ans, dp[n][i]);

    cout << ans << '\n';
  }
}
