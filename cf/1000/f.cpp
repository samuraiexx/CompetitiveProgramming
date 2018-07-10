#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " << 
typedef long long ll;
const int N = 2e7 + 5;
const int INF = 0x3f3f3f3f;

int sz = 1;

int lc[N];
int rc[N];
int rt[N];
pair<int, int> st[N];

int lst[N];
int v[N];

int update(int n, int l, int r, int i, int val){
  int node = sz++;
  if(l == r) { st[node] = {val, i}; return node; }

  int mid = (l + r)/2;
  if(i <= mid) lc[node] = update(lc[n], l, mid, i, val), rc[node] = rc[n];
  else         lc[node] = lc[n], rc[node] = update(rc[n], mid + 1, r, i, val);

  st[node] =  min(st[lc[node]], st[rc[node]]);

  return node;
}

pair<int, int> query(int n, int l, int r, int i, int j){
  if(j < l or i > r) return {INF, 0};
  if(i <= l and r <= j) return st[n];

  int mid = (l + r)/2;

  auto ql = query(lc[n], l, mid, i, j);
  auto qr = query(rc[n], mid + 1, r, i, j);
  return min(ql, qr);
}

int main(){
  int n;
  cin >> n;

  st[0] = {INF, 0};
  for(int i = 1; i <= n; i++){
    cin >> v[i];

    rt[2*i] = update(rt[2*i - 1], 1, n, lst[v[i]], INF);
    rt[2*i + 1] = update(rt[2*i], 1, n, i, lst[v[i]]);
    lst[v[i]] = i;
  }


  int q;
  cin >> q;
  for(int i = 0; i < q; i++){
    int a, b;
    cin >> a >> b;

    auto p = query(rt[2*b + 1], 1, n, a, n);
    if(p.st < a) cout << v[p.nd] << '\n';
    else cout << 0 << '\n';
  }
}
