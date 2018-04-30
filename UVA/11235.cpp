#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " << 
typedef long long ll;
const int N = 1e5 + 5;
int n;

int v[N];
int st[4*N];

int freq(int x, int l, int r){
  l = max((int)(lower_bound(v, v + n, x) - v), l);
  r = min((int)(upper_bound(v, v + n, x) - v), r + 1);
  return r - l;
}

void build(int n, int l, int r){
  if(l == r) {st[n] = 1; return;}
  int mid = (l + r)/2;
  build(2*n, l, mid);
  build(2*n + 1, mid + 1, r);
  st[n] = max({st[2*n], st[2*n + 1], freq(v[mid], l, r)});
}

int query(int n, int l, int r, int i, int j){
  if(j < l or i > r) return 0;
  if(i <= l and j >= r) return st[n];

  int mid = (l + r)/2;

  int ans = query(2*n, l, mid, i, j);
  ans = max(ans, query(2*n + 1, mid + 1, r, i, j));
  ans = max(ans, freq(v[mid], i, j));

  //db(n _ l _ r _ i _ j _ ans);
  return ans;
}

int main(){
  int q;
  while(cin >> n >> q){
    for(int i = 0; i < n; i++) cin >> v[i];

    build(1, 0, n - 1);
    while(q--){
      int l, r;
      cin >> l >> r;
      cout << query(1, 0, n - 1, l - 1, r - 1) << endl; 
    }
  }
}
