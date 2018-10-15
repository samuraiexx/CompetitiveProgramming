#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " << 
typedef long long ll;
const int N = 35;
char g[N][N];
bool p[N][N];
ll dp[N][N];

int main(){
  cin.tie(0), ios_base::sync_with_stdio(false);

  int n, m;
  scanf("%d %d", &n, &m);

  for(int i = 0; i <= n + 1; i++)
    p[i][0] = p[i][m + 1] = true;

  for(int i = 0; i <= m + 1; i++)
    p[0][i] = p[n + 2][i] = true;

  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= m; j++){
      scanf(" %c", &g[i][j]);
      //cin >> g[i][j];

      if(g[i][j] == 'R')
        for(int k = i + 1; k <= n + 1; k++)
          for(int l = j; l <= m; l++)
            p[k][l] = true;

      if(g[i][j] == 'B')
        for(int k = i; k > 0; k--)
          for(int l = j; l > 0; l--)
            p[k][l] = true;
    }
  }

  for(int i = 1; i <= n; i++)
    for(int j = 1; j <= m; j++)
      if(g[i][j] == 'R')
        for(int k = i; k <= n; k++)
          for(int l = j; l <= m; l++)
            if(g[k][l] == 'B') return cout << 0 << '\n', 0;

  for(int i = 1; i <= n; i++)
    dp[i][m] = !p[i][m];

  for(int j = m; j > 0; j--)
    for(int i = 1; i <= n + 1; i++)
      for(int k = i; k <= n + 1; k++)
        if(!p[k][j - 1])
          dp[k][j - 1] += dp[i][j];

  ll ans = 0;

  for(int i = 1; i <= n + 1; i++)
    ans += dp[i][1];

  cout << ans << '\n';
}
