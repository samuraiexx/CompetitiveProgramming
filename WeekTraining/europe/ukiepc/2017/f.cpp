#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " << 
typedef long long ll;
const int N = 405;
double dp[N][N];
bool vis[N][N];

double dpf(int n, int k){
  if(k == 0) return 0;
  if(vis[n][k]) return dp[n][k];
  
  vis[n][k] = true;

  if(n != 0) dp[n][k] = 0.5*(1 + dpf(n - 1, k - 1) + dpf(n, k - 1));
  else dp[n][k] = 0.5*(-1 + dpf(n + 1, k - 1) + dpf(n, k - 1));

  return dp[n][k];
}

int main(){
  int n, k;
  cin >> n >> k;

  printf("%.12lf\n", dpf(n, k));
}
