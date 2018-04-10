#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " << 
typedef long long ll;
const int N = 1e3 + 5;
int dp[N][N];
int v[N];

int dpf(int i, int j){
  if(i > j) return 0;
  if(dp[i][j]) return dp[i][j];
  int ret;

  if(v[i + 1] >= v[j]) ret = dpf(i + 2, j) + v[i];
  else ret = dpf(i + 1, j - 1) + v[i];

  if(v[i] >= v[j - 1]) ret = max(ret, dpf(i + 1, j - 1) + v[j]);
  else ret = max(ret, dpf(i, j - 2) + v[j]);
  return dp[i][j] = ret;
}

int main(){
  int n;
  int cnt = 0;
  while(cin >> n, n){
    cnt++;
    memset(dp, 0, sizeof dp);
    memset(v, 0, sizeof v);
    int sum = 0;
    for(int i = 0; i < n; i++)
      cin >> v[i], sum += v[i];
    
    cout << "In game " << cnt << ", the greedy strategy might lose by as many as ";
    cout << 2*dpf(0, n - 1) - sum << " points." << endl;
  }
}
