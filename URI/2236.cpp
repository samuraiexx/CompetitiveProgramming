#include<bits/stdc++.h>
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " <<
using namespace std;
const int N = 5e4 + 5;
int mn[N];
int nxt[N];
vector<int> st[4*N];

vector<int> g[N];

void build(int n, int l, int r){
  if(l == r){ st[n].push_back(mn[l]); return; }

  int mid = (l + r)/2;
  build(2*n, l, mid);
  build(2*n + 1, mid + 1, r);

  st[n].resize(r - l + 1);
  merge(st[2*n].begin(), st[2*n].end(),
        st[2*n + 1].begin(), st[2*n + 1].end(), st[n].begin());
}

int query(int n, int l, int r, int i, int j, int x){
  if(r < i or j < l) return 0;
  if(i <= l and r <= j) return upper_bound(st[n].begin(), st[n].end(), x) - st[n].begin();

  int mid = (l + r)/2;
  return query(2*n, l, mid, i, j, x) + query(2*n + 1, mid + 1, r, i, j, x);
}

void dfs(int u, int r) {
  if (mn[u]) return;
  mn[u] = r;
  for(int v : g[u]) dfs(v, r);
}

int main(){
  cin.tie(0), ios_base::sync_with_stdio(false);

  int n, q;
  cin >> n >> q;
  for(int i = 1, x; i <= n; i++)
    cin >> nxt[i], g[nxt[i]].push_back(i);

  for(int i = 1; i <= n; i++)
    dfs(i, i);

  build(1, 1, n);

  while(q--){
    int l, r;
    cin >> l >> r;

    int i = 1, j = n;
    while(i != j){
      int mid = (i + j + 1)/2;
      int x = query(1, 1, n, l, r, mid);

      if(2*x <= r - l + 1) i = mid;
      else j = mid - 1;
    }

    int val = query(1, 1, n, l, r, i);
     

    i = 1, j = n;
    while(i != j){
      int mid = (i + j)/2;
      int x = query(1, 1, n, l, r, mid);

      if(2*x < r - l + 1) i = mid + 1;
      else j = mid;
    }

    int val2 = query(1, 1, n, l, r, i);

    //db((r - l + 1) - val2 _ val);

    if((r - l + 1) - val2 > val)
      val = val2;

    i = 1, j = n;
    while(i != j){
      int mid = (i + j)/2;
      int x = query(1, 1, n, l, r, mid);

      if(x < val) i = mid + 1;
      else j = mid;
    }

    cout << i << '\n';
  }
}
