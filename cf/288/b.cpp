#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " << 
typedef long long ll;
const int N = 1e3 + 5;
const ll MOD = 1e9 + 7;
int n, k;
ll ans2;

int p[9];
int vis[9];

ll fexp(ll a, ll b, ll m = MOD) {
  ll r=1;
  for (a %= m; b; b>>=1, a=(a*a)%m) if (b&1) r=(r*a)%m;
  return r;
}

bool dfs(int x){
  if(x == 1) return true;
  if(vis[x] != -1) return vis[x];
  vis[x] = 0;
  return vis[x] = dfs(p[x]);
}

void bt(int i){
  if(i == k + 1) {
    memset(vis, -1, sizeof vis);
    bool can = true;
    for(int i = 2; i <= k; i++)
      can &= dfs(i);
    ans2 += can;
    return;
  }
  for(int j = 1; j <= k; j++)
    p[i] = j, bt(i + 1);
}

int main(){
  cin >> n >> k;

  ll ans = (k*fexp(n - k, n - k))%MOD;

  if(k > 1) bt(2);
  else ans2 = 1;

  cout << (ans*ans2)%MOD << endl;
}
