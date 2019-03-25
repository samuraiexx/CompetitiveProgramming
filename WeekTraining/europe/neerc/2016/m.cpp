#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " << 
typedef long long ll;
const int N = 1e5 + 5;
const int INF = 0x3f3f3f3f;
int f[N];
int lg[N];
int sz[N];

struct St {
  vector<pair<int, int>> st;
  vector<int> lz;
  void build(int n, int l, int r, int x) {
    if(l == r){
      int pos = l + (x - 1)*(1 << lg(l));
      int dist = f[pos] > 0 ? lg(l) : INF;
      st[n] = {dist, pos};
      return;
    }
    int mid = (l + r)/2;
    build(2*n, l, mid, x);
    build(2*n + 1, mid + 1, r, x);
    st[n] = min(st[2*n], st[2*n + 1]);
  }

  st(int n, int x):st(n + 1), lz(n + 1) {
    build(1, 1, n, x);
  }

  void push(int n, int l, int r){
    if(!lz[n]) return;

    if(l != r){ lz[2*n] += lz[n]; lz[2*n + 1] += lz[n]; }
    st[n].st += lz[n];
    lz[n] = 0;
  }
  
  void update(int n, int l, int r, int i, int j, int val){
    push(n, l, r);
    if(i > r or j < l) return;
    if(i <= l and r <= j) { lz[n] = val; push(n, l, r); return; }
    int mid = (l + r)/2;
    update(2*n, l, mid, i, j, val);
    update(2*n + 1, mid + 1, r, i, j, val);
    st[n] = min(st[2*n], st[2*n + 1]);
  }

  pair<int, int> query(int n, int l, int r, int i, int j){
    if(i > r or j < l) return {INF, INF};
    if(i <= l and r <= j) return s[n];

    int mid = (l + r)/2;
    return min(query(2*n, l, mid, i, j), query(2*n + 1, mid + 1, r, i, j));
  }
};

int dfs(int n, int mx) {
  if(n > mx) return 0;
  sz[n] = dfs(2*n, mx) + dfs(2*n + 1, mx) + 1;
  return sz[n];
}

int main(){
  cin.tie(0), ios_base::sync_with_stdio(false);

  for(int i = 2; i < N; i++)
    lg[i] = 1 + lg[i/2];

  int n, m;
  cin >> n >> m;
  dfs(1, n);
  for(int i = 1; i <= n; i++)
    cin >> f[i];

  vector<St> st;

  for(int i = 1; i <= n; i++)
    st.emplace_back(sz[i], i);

  while(m--) {
    int p;
    cin >> p;
  }
}
