#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " << 
typedef long long ll;
const int N = 5e3 + 5;
const int INF = 0x3f3f3f3f;
int n;
int h[N];
int dp[N][N], dp2[N][N];
bool vis[N][N], vis2[N][N];

int dpf(int psz, int amt);
int dp2f(int psz, int amt);

int dp2f(int psz, int amt){
  if(amt > (psz + 1)/2) return INF;
  if(amt == 0) return 0;
  if(psz == 0) return INF;
  if(vis2[psz][amt]) return dp2[psz][amt];

  vis2[psz][amt] = true;

  int d = h[psz - 1] - h[psz - 2] + 1;
  if(d < 0) d = 0;

  dp2[psz][amt] = min(dpf(psz - 1, amt) + d, dp2f(psz - 1, amt));
  return dp2[psz][amt];
}

int dpf(int psz, int amt){
  if(amt > (psz + 1)/2) return INF;
  if(amt == 0) return 0;
  if(psz == 0) return INF;
  if(vis[psz][amt]) return dp[psz][amt];

  vis[psz][amt] = true;

  int d = h[psz - 2] - min(h[psz - 1], h[psz - 3]) + 1;
  if(d < 0) d = 0;

  int d2 = h[psz - 2] - h[psz - 1] + 1;
  if(d2 < 0) d2 = 0;

  dp[psz][amt] = min(dpf(psz - 2, amt - 1) + d, dp2f(psz - 2, amt - 1) + d2);
  return dp[psz][amt];
}

int main(){
  cin >> n;
  for(int i = 0; i < n; i++)
    cin >> h[i];
  h[n] = -INF;

  for(int i = 1; i <= (n + 1)/2; i++)
    cout << dp2f(n + 1, i) << ' ';
  cout << endl;
}
