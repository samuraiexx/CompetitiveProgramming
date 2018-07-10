#include<bits/stdc++.h>
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " << 

typedef long long ll;
using namespace std;
const int N = 3e5 + 5;

ll m[2][2];
ll st[4*N];
pair<ll, ll> lz[4*N];
ll v[N];
ll mod = 1e9 + 9;

ll fibv[N][2][2];

pair<ll, ll> operator+(pair<ll, ll> a, pair<ll, ll> b){
  return {(a.st + b.st)%mod, (a.nd + b.nd)%mod };
}

void mult(ll a[2][2], ll b[2][2]){
  ll tmp[2][2];

  for(int i = 0; i < 2; i++)
    for(int j = 0; j < 2; j++){
      tmp[i][j] = 0;
      for(int k = 0; k < 2; k++)
        tmp[i][j] = (tmp[i][j] + a[i][k]*b[k][j])%mod;
    }

  for(int i = 0; i < 2; i++)
    for(int j = 0; j < 2; j++)
      a[i][j] = tmp[i][j];
}

pair<ll, ll> fib(ll f0, ll f1, int p){
  auto &ans = fibv[p];

  ll y1 = (ans[0][0]*f0 + ans[0][1]*f1)%mod;
  ll y2 = (ans[1][0]*f0 + ans[1][1]*f1)%mod;

  return {y1, y2};
}

ll getSum(ll f0, ll f1, int p){
  return (fib(f0, f1, p + 2).st - f1 + mod)%mod;
}

void build(int n, int l, int r){
  if(l == r){ st[n] = v[l]; return; }
  int mid = (l + r)/2;
  build(2*n, l, mid);
  build(2*n + 1, mid + 1, r);

  st[n] = (st[2*n] + st[2*n + 1])%mod;
}

void push(int n, int l, int r){
  if(lz[n].st == 0 and lz[n].nd == 0) return;
  ll sum = getSum(lz[n].st, lz[n].nd, r - l);;
  st[n] = (st[n] + sum)%mod;

  if(l != r){
    int mid = (l + r)/2;
    ll a, b;
    tie(a, b) = fib(lz[n].st, lz[n].nd, mid + 1 - l);
    
    lz[2*n] = lz[2*n] + lz[n];
    lz[2*n + 1] = lz[2*n + 1] + make_pair(a, b);
  }
  lz[n] = {0, 0};
}

void update(int n, int l, int r, int i, int j, int a, int b){
  push(n, l, r);
  if(i > r or j < l) return;
  if(i <= l and r <= j) {
    tie(a, b) = fib(a, b, l - i);
    lz[n] = lz[n] + make_pair(a, b);
    push(n, l, r);
    return;
  }

  int mid = (l + r)/2;

  update(2*n, l, mid, i, j, a, b);
  update(2*n + 1, mid + 1, r, i, j, a, b);

  st[n] = (st[2*n] + st[2*n + 1])%mod;
}

ll query(int n, int l, int r, int i, int j){
  push(n, l, r);
  if(i > r or j < l) return 0;
  if(i <= l and r <= j) return st[n];

  int mid = (l + r)/2;
  return (query(2*n, l, mid, i, j) + query(2*n + 1, mid + 1, r, i, j))%mod;
}


int main(){
  int n, m;
  cin >> n >> m;
  for(int i = 1; i <= n; i++)
    cin >> v[i];

  ll a[2][2] = {{0, 1}, 
                {1, 1}};

  fibv[0][0][0] = 1;
  fibv[0][0][1] = 0;
  fibv[0][1][0] = 0;
  fibv[0][1][1] = 1;

  for(int i = 1; i < N; i++){
    for(int j = 0; j < 2; j++)
      for(int k = 0; k < 2; k++)
        fibv[i][j][k] = fibv[i - 1][j][k];

    mult(fibv[i], a);
  }

  build(1, 1, n);

  for(int i = 0; i < m; i++){
    int t, l , r;
    cin >> t >> l >> r;
    if(t == 1)
      update(1, 1, n, l, r, 1, 1);
    else
      cout << query(1, 1, n, l, r) << '\n';

    //for(int i = 1; i <= n; i++)
      //db(i _ query(1, 1, n, i, i));
  }

}
