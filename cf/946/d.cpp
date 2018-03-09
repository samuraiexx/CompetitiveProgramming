#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " << 
const int N = 505;
const int INF = 0x3f3f3f3f;
int bst[N][N];
int dp[N][N]; //dia i, gastando j = horas na uni
int r[N], l[N];

int n, m, k;

int main(){
  cin >> n >> m >> k;

  memset(bst, 0x3f, sizeof bst);
  memset(dp, 0x3f, sizeof dp);
  for(int i = 0; i < m; i++)
    dp[0][i] = 0;

  for(int i = 0; i < n; i++){
    string s;
    cin >> s;

    int cnt = 0;
    for(int i = 0; i < m; i++){
      l[i] = cnt;
      if(s[i] == '1') cnt++; 
    }

    cnt = 0;
    for(int i = m - 1; i >= 0; i--){
      r[i] = cnt;
      if(s[i] == '1') cnt++;
    }

    for(int j = 0; j < m; j++)
      for(int k = j; k < m; k++)
        bst[i][l[j] + r[k]] = min(bst[i][l[j] + r[k]], k - j + 1);

    bst[i][cnt] = 0;
  }

  /*for(int i = 0; i < n; i++){
    for(int j = 0; j <= m; j++)
      cout << bst[i][j] << ' ';
    cout << endl;
  }*/

  for(int i = 0; i <= k; i++)
    dp[0][i] = bst[0][i];

  for(int i = 1; i < n; i++)
    for(int j = 0; j <= k; j++)
      for(int k = 0; k <= j; k++)
        dp[i][j] = min(dp[i][j], dp[i - 1][j - k] + bst[i][k]);

  int ans = INF;
  for(int i = 0; i <= k; i++)
    ans = min(ans, dp[n - 1][i]);

  cout << ans << endl;
}
