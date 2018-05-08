#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int st0[4*N];
int st1[4*N];
int st2[4*N];
int lz[4*N];

void push(int n, int l, int r){
  lz[n] = lz[n]%3;
  if(!lz[n]) return;

  for(int i = 0; i < lz[n]; i++)
    swap(st0[n], st1[n]), swap(st0[n], st2[n]);

  if(l != r) lz[2*n] += lz[n], lz[2*n + 1] += lz[n];

  lz[n] = 0;
}

void update(int n, int l, int r, int i, int j){
  push(n, l, r);
  if(j < l or i > r) return;
  if(i <= l and r <= j) { lz[n]++; push(n, l, r); return; }

  int mid = (l + r)/2;
  update(2*n, l, mid, i, j);
  update(2*n + 1, mid + 1, r, i, j);
  st0[n] = st0[2*n] + st0[2*n + 1];
  st1[n] = st1[2*n] + st1[2*n + 1];
  st2[n] = st2[2*n] + st2[2*n + 1];
}

int query(int n, int l, int r, int i, int j){
  push(n, l, r);
  if(j < l or i > r) return 0;
  if(i <= l and r <= j) return st0[n];
  int mid = (l + r)/2;
  return query(2*n, l, mid, i, j) + query(2*n + 1, mid + 1, r, i, j);
}

void build(int n, int l, int r){
  if(l == r){ st0[n] = 1; return; }

  int mid = (l + r)/2;
  build(2*n, l, mid);
  build(2*n + 1, mid + 1, r);
  st0[n] = st0[2*n] + st0[2*n + 1];
}

int main(){
  int n, q;
  cin >> n >> q;
  build(1, 0, n - 1);


  for(int i = 0; i < q; i++){
    int t, a, b;
    cin >> t >> a >> b;
    if(t == 0) update(1, 0, n - 1, a, b);
    else cout << query(1, 0, n - 1, a, b) << endl;
  }
}
