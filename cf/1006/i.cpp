#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " << 
typedef long long ll;
const int N = 200 + 5;
const int M = 3e6 + 5;

int n, m, q;

vector<pair<int, int>> xy[N*N];

int cnt;
int st[M], lc[M], rc[M];
int version[(int)2e3 + 5];

int addy(int u, int l, int r, int y){
  int n = ++cnt;
  if(l == r) st[n] = st[u] + 1;
  else{
    lc[n] = lc[u], rc[n] = rc[u];
    int mid = (l + r)/2;

    if(y > mid) rc[n] = addy(rc[u], mid + 1, r, y);
    else lc[n] = addy(lc[u], l, mid, y);

    st[n] = st[lc[n]] + st[rc[n]];
  }

  return n;
}

int add(int u, int l, int r, int x, int y){
  int node = ++cnt;
  st[node] = addy(st[u], 1, n, y);

  if(l != r){
    lc[node] = lc[u], rc[node] = rc[u];

    int mid = (l + r)/2;
    if(x > mid) rc[node] = add(rc[u], mid + 1, r, x, y);
    else lc[node] = add(lc[u], l, mid, x, y);
  }

  return node;
}

int queryy(int u, int l, int r, int c, int d){
  if(!u or d < l or c > r) return 0;
  if(c <= l and r <= d)
    return st[u];

  int mid = (l + r)/2;
  return queryy(lc[u], l, mid, c, d) + 
    queryy(rc[u], mid + 1, r, c, d);
}

int query(int u, int l, int r, int a, int b, int c, int d){
  if(!u or b < l or a > r) return 0;
  if(a <= l and r <= b)
    return queryy(st[u], 1, n, c, d);

  int mid = (l + r)/2;
  int ql =  query(lc[u], l, mid, a, b, c, d);
  int qr = query(rc[u], mid + 1, r, a, b, c, d);

  return ql + qr;
}


int main(){
  freopen("important.in", "r", stdin);
  int T;
  cin >> T;
  for(int t = 1; t <= T; t++){
    cout << "Case " << t << ":\n";

    for(int i = 1; i <= 2e3; i++)
      xy[i].clear();

    cin >> n >> m >> q;
    for(int i = 1; i <= n; i++){
      for(int j = 1; j <= m; j++){
        int x;
        cin >> x;

        xy[x].push_back({i, j});
      }
    }

    vector<int> root;
    root.pb(0);

    for(int i = 1; i <= 2e3; i++){
      for(auto p : xy[i]){
        root.push_back(add(root.back(), 1, m, p.nd, p.st));
      }
      version[i] = root.back();
    }

    for(int k = 0; k < q; k++){
      int a, b, c, d;
      cin >> a >> b >> c >> d;

      int i = 1, j = 2e3;
      while(i != j){
        int mid = (i + j)/2;
        if(query(version[mid], 1, m, b, d, a, c) > (c - a + 1)*(d - b + 1)/2)
          j = mid;
        else i = mid + 1;
      }

      cout << i << '\n';
    }

    for(int i = 1; i <= cnt; i++)
      st[i] = lc[i] = rc[i] = 0;
    cnt = 0;
  }
}
