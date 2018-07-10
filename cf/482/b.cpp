#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int st[4*N];
int lz[4*N];

void push(int n, int l, int r){
  if(!lz[n]) return;
  st[n] = st[n]|lz[n];
  if(l != r){
    lz[2*n] |= lz[n];
    lz[2*n + 1] |= lz[n];
  }

  lz[n] = 0;
}

void update(int n, int l, int r, int i, int j, int val){
  push(n, l, r);
  if(j < l or r < i) return;
  if(i <= l and r <= j) { lz[n] |= val; push(n, l, r); return; }
  int mid = (l + r)/2;

  update(2*n, l, mid, i, j, val);
  update(2*n + 1, mid + 1, r, i, j, val);

  st[n] = st[2*n]&st[2*n + 1];
}

int query(int n, int l, int r, int i, int j){
  push(n, l, r);
  if(j < l or r < i) return (1 << 30) - 1;
  if(i <= l and r <= j) return st[n];
  int mid = (l + r)/2;

  return query(2*n, l, mid, i, j) &
         query(2*n + 1, mid + 1, r, i, j);
}

tuple<int, int, int> t[N];

int main(){
  int n, m;
  cin >> n >> m;

  for(int i = 0; i < m; i++){
    int l, r, q;
    cin >> l >> r >> q;
    t[i] = {l, r, q};

    update(1, 1, n, l, r, q); 
  }

  for(int i = 0; i < m; i++){
    int l, r, q;
    tie(l, r, q) = t[i];

    if(query(1, 1, n, l, r) != q) return cout << "NO" << endl, 0;
  }

  cout << "YES" << endl;

  for(int i = 1; i <= n; i++)
    cout << query(1, 1, n, i, i) << " \n"[i == n];
}
