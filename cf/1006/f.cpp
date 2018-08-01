#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " << 
typedef long long ll;
const int N = 22;
int n, m;

bool vis[N][N];

ll mt[N][N];
map<ll, ll> ans[N][N];

ll dpf(int i, int j, ll x){
  if(i > n or j > m) return 0;
  if(vis[i][j]) return ans[i][j][x];

  ll ret = dpf(i + 1, j, x^mt[i][j]) + dpf(i, j + 1, x^mt[i][j]);
  return ret;
}

int main(){
  ll k;
  cin >> n >> m >> k;

  for(int i = 1; i <= n; i++)
    for(int j = 1; j <= m; j++)
      cin >> mt[i][j];

  ans[n][m][mt[n][m]]++;
  vis[n][m] = true;

  for(int i = n; i > 0; i--){
    for(int j = m; j > 0; j--){
      if(i + j < min(n, m)) continue;
      vis[i][j] = true;
      for(auto p : ans[i + 1][j])
        ans[i][j][p.st^mt[i][j]] += p.nd;
      for(auto p : ans[i][j + 1])
        ans[i][j][p.st^mt[i][j]] += p.nd;

      ans[i - 1][j].clear();
    }
  }

  cout << dpf(1, 1, k) << endl;

}
