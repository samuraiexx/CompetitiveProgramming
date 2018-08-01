#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " <<
typedef long long ll;
const int N = 1e5 + 5;
int st[4*N][9];
int lz[4*N];

int qry[9];

void push(int n, int l, int r){
  lz[n] = lz[n]%9;
  if(lz[n]){
    for(int i = 0; i < lz[n]; i++){
      int tmp = st[n][8];
      for(int i = 8; i > 0; i--){
        st[n][i] = st[n][i - 1];
      }
      st[n][0] = tmp;
    }
    if(l != r)
      lz[2*n] += lz[n], lz[2*n + 1] += lz[n];
    lz[n] = 0;
  }
}

void build(int n, int l, int r){
  st[n][1] = r - l + 1;
  if(l != r){
    int mid = (l + r)/2;
    build(2*n, l, mid),
      build(2*n + 1, mid + 1, r);
  }
}

void update(int n, int l, int r, int i, int j, int f){
  push(n, l, r);
  if(i > r or j < l) return;
  if(i <= l and r <= j){ lz[n] += f; push(n, l, r); }
  else{
    int mid = (l + r)/2;
    update(2*n, l, mid, i, j, f);
    update(2*n + 1, mid + 1, r, i, j, f);
    for(int i = 0; i < 9; i++)
      st[n][i] = st[2*n][i] + st[2*n + 1][i];
  }
}

void query(int n, int l, int r, int i, int j){
  push(n, l, r);
  if(i > r or j < l) return;
  if(i <= l and r <= j){
    for(int i = 0; i < 9; i++)
      qry[i] += st[n][i];
  }else{
    int mid = (l + r)/2;
    query(2*n, l, mid, i, j);
    query(2*n + 1, mid + 1, r, i, j);
  }
}

int query2(int n, int l, int r, int i){
  push(n, l, r);
  if(l == r){
    for(int i = 0; i < 9; i++)
      if(st[n][i]) return i;
  }
  int mid = (l + r)/2;
  return i > mid ? query2(2*n + 1, mid + 1, r, i) :
    query2(2*n, l, mid, i);
}

int main(){
  int n, q;
  cin >> n >> q;

  build(1, 0, n - 1);

  while(q--){
    int a, b;
    cin >> a >> b;

    for(int i = 0; i < 9; i++)
      qry[i] = 0;

    query(1, 0, n - 1, a, b);

    int f = 0, mx = 0;
    for(int i = 0; i < 9; i++){
      if(qry[i] >= mx) f = i, mx = qry[i];
    }

    update(1, 0, n - 1, a, b, f);
  }

  for(int i = 0; i < n; i++)
    cout << query2(1, 0, n - 1, i) << '\n';
}
