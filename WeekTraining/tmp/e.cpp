#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " << 
typedef long long ll;
const int N = 455;
int c[N][N];
int dp[N][N];

int main(){
  cin.tie(0), ios_base::sync_with_stdio(false);
  int n, k;
  cin >> n >> k;

  for(int j = 0; j <= n; j++)
    for(int i = j + 1; i <= n; i++)
      c[i][j] = c[i - 1][j] + i/(j + 1);

  vector<int> inter;

  int sz = 0;
  int mx = 0;

  for(int i = 0; i < n; i++){
    char c;
    cin >> c;
    if(c == '1') sz++, mx++;
    else if(sz > 0) inter.pb(sz), sz = 0;
  }
  if(sz > 0) inter.pb(sz);

  sort(inter.begin(), inter.end(), greater<int>());

  n = inter.size();

  for(int i = 0; i < n; i++){
    for(int j = 0; j <= mx; j++){
      dp[i][j] = dp[i - 1][0] + c[inter[i]][j];
      for(int k = 1; k <= j; k++)
        dp[i][j] = min(dp[i][j], dp[i - 1][k] + c[inter[i]][j - k]);
    }
  }

  for(int i = 0; i <= mx; i++){
    if(dp[n - 1][i] <= k)
      return cout << i << '\n', 0;
  }
}
