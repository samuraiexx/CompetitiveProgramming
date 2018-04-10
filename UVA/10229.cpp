#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " << 
typedef long long ll;
ll mod = 1e9 + 7;
const ll N = 2;
ll tmp[N][N];

void cp(ll a[N][N], ll b[N][N]){
  for(ll i = 0; i < 2; i++)
    for(ll j = 0; j < 2; j++)
      b[i][j] = a[i][j];
}

void mult(ll a[N][N], ll b[N][N]){
  for(ll i = 0; i < 2; i++)
    for(ll j = 0; j < 2; j++){
      tmp[i][j] = 0;
      for(ll k = 0; k < 2; k++)
        tmp[i][j] = (tmp[i][j] + a[i][k]*b[k][j])%mod;
    }
  cp(tmp, a);
}

void print(ll a[N][N]){
  for(ll i = 0; i < 2; i++){
    for(ll j = 0; j < 2; j++)
      cout << a[i][j] << ' ';
    cout << endl;
  }
  cout << endl;
}

void fexp(ll a[N][N], ll b){
  ll ans[N][N];

  for(ll i = 0; i < 2; i++)
    for(ll j = 0; j < 2; j++)
      ans[i][j] = (i == j);

  while(b){
    if(b&1) mult(ans, a);
    mult(a, a), b /= 2;
  }
  cp(ans, a);
}

int main(){
  ll n, m;
  while(cin >> n >> m){
  if(n == 0) { cout << 0 << endl; continue; }
  ll a[N][N] = {{1, 1},
                {1, 0}};

  mod = (1 << m);

  fexp(a, n - 1);

  cout << a[0][0] << endl;
  }
}
