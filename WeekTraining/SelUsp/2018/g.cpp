#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " << 
typedef long long ll;
const int N = 2e5 + 5;
const int INF = 1e9 + 5;

pair<int, int> ran[N], st[4*N];

void build(int n, int l, int r){
  if(l == r) st[n] = ran[l];
  else{
    int mid = (l + r)/2;
    build(2*n, l, mid);
    build(2*n + 1, mid + 1, r);

    st[n].st = max(st[2*n].st, st[2*n + 1].st);
    st[n].nd = min(st[2*n].nd, st[2*n + 1].nd);
  }
}

void update(int n, int l, int r, int i, pair<int, int> val){
  if(l == r){
    st[n] = val;
  } else {
    int mid = (l + r)/2;
    if(i <= mid) update(2*n, l, mid, i, val);
    else update(2*n + 1, mid + 1, r, i, val);

    st[n].st = max(st[2*n].st, st[2*n + 1].st);
    st[n].nd = min(st[2*n].nd, st[2*n + 1].nd);
  }
}

pair<int, int> query(int n, int l, int r, int i, int j){
  if(i > r or j < l) return {-INF, INF};
  if(i <= l and r <= j) return st[n];
  int mid = (l + r)/2;

  auto i1 = query(2*n, l, mid, i, j);
  auto i2 = query(2*n + 1, mid + 1, r, i, j);

  return {max(i1.st, i2.st), min(i1.nd, i2.nd)};
}

int main(){
  cin.tie(0), ios_base::sync_with_stdio(false);

  int n, q;
  cin >> n >> q;
  for(int i = 1; i <= n; i++)
    cin >> ran[i].st >> ran[i].nd;

  build(1, 1, n);

  for(int i = 0; i < q; i++){
    char c;
    cin >> c;
    if(c == '?'){
      int l, r;
      cin >> l >> r;

      auto p = query(1, 1, n, l, r);
      cout << max(0, p.nd - p.st + 1) << '\n';
    }else{
      int i, l, r;
      cin >> i >> l >> r;

      update(1, 1, n, i, {l, r});
    }
  }
}
