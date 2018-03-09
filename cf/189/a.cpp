#include<bits/stdc++.h>
using namespace std;
const int N = 4e3 + 5;
const int INF = 0x3f3f3f3f;
int n, it[3];
int dp[3][N];
bool vis[3][N];

int dpf(int i, int p){
  if(p < 0 or i < 0) return -INF;
  if(p == 0) return 0;
  if(vis[i][p]) return dp[i][p];
  vis[i][p] = 1;
  return dp[i][p] = max(dpf(i - 1, p), 1 + dpf(i, p - it[i]));
}

int main(){
  cin >> n >> it[0] >> it[1] >> it[2];
  for(int i = 0; i < 3; i++)
    for(int j = 0; j < N; j++) dp[i][j] = -INF;

  cout << dpf(2, n) << endl;
}
