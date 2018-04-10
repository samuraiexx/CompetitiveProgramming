#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " << 
typedef long long ll;
ll mod = 1e9 + 7;
const ll N = 55;
ll a[N][N], tmp[N][N];
ll n, m, k;

void cp(ll a[N][N], ll b[N][N]){
  for(ll i = 0; i < m; i++)
    for(ll j = 0; j < m; j++)
      b[i][j] = a[i][j];
}

void mult(ll a[N][N], ll b[N][N]){
  for(ll i = 0; i < m; i++)
    for(ll j = 0; j < m; j++){
      tmp[i][j] = 0;
      for(ll k = 0; k < m; k++)
        tmp[i][j] = (tmp[i][j] + a[i][k]*b[k][j])%mod;
    }
  cp(tmp, a);
}

void prll(ll a[N][N]){
  for(ll i = 0; i < m; i++){
    for(ll j = 0; j < m; j++)
      cout << a[i][j] << ' ';
    cout << endl;
  }
  cout << endl;
}

void fexp(ll a[N][N], ll b){
  ll ans[N][N];

  for(ll i = 0; i < m; i++)
    for(ll j = 0; j < m; j++)
      ans[i][j] = (i == j);

  while(b){
    if(b&1) mult(ans, a);
    mult(a, a), b /= 2;
  }
  cp(ans, a);
}

int main(){
  cin >> n >> m >> k;
  for(ll i = 0; i < m; i++)
    for(ll j = 0; j < m; j++) a[i][j] = 1;

  for(ll i = 0; i < k; i++) {
  char x, y;
    cin >> x >> y;
    if(x >= 'a') x -= 'a';
    else x = x - 'A' + 26;
    if(y >= 'a') y -= 'a';
    else y = y - 'A' + 26;
    a[x][y] = 0;
  }

  fexp(a, n - 1);
  ll ans = 0;
  for(ll i = 0; i < m; i++)
    for(ll j = 0; j < m; j++)
      ans = (ans + a[i][j])%mod;

  cout << ans << endl;
}
