#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl;
#define _ << ", " << 
typedef long long ll;
const int N = 1e5 + 5;
const int INF = 0x3f3f3f3f;
int n, c, q;

set<pair<int, int>> col[N];
ll amt[N];
int st[4*N];

void build(int n, int l, int r){
  if(l == r) { st[n] = 1; return; }
  int mid = (l + r)/2;
  build(2*n, l, mid), build(2*n + 1, mid + 1, r);
}

void push(int n, int l, int r){
  if(st[n] and l != r){
    st[2*n] = st[2*n + 1] = st[n];
    st[n] = 0;
  }
}

void update(int n, int l, int r, int i, int j, int val){
  push(n, l, r);
  if(r < i or l > j) return;
  if(i <= l and r <= j) { st[n] = val; push(n, l, r); return; }
  int mid = (l + r)/2;
  update(2*n, l, mid, i, j, val);
  update(2*n + 1, mid + 1, r, i, j, val);
}

int query(int n, int l, int r, int i){
  push(n, l, r);
  if(l == r) return st[n];
  int mid = (l + r)/2;
  if(i <= mid) return query(2*n, l, mid, i);
  else return query(2*n + 1, mid + 1, r, i);
}

void rem(int l, int r){
  if(l > r) return;
  int c = query(1, 0, n - 1, l);
  auto it = col[c].upper_bound({l, INF});
  it--;

  int r2 = r;
  r = min(r, it->second);
  int l2 = r + 1;

  amt[c] -= r - l + 1;
  if(it->first != l) col[c].insert({it->first, l - 1});
  if(it->second != r) col[c].insert({r + 1, it->second});
  col[c].erase(it);

  rem(l2, r2);
}

void add(int l, int r, int c){
  update(1, 0, n -1, l, r, c);
  amt[c] += r - l + 1;

  auto itr = col[c].upper_bound({l, INF});
  auto itl = itr;
  if(itl != col[c].begin()) itl--;

  if(itl != col[c].end() and itl->second + 1 == l)
    l = itl->first, col[c].erase(itl);

  if(itr != col[c].end() and itr->first - 1 == r)
    r = itr->second, col[c].erase(itr);
  col[c].insert({l, r});

}

int main(){
  cin.tie(0), ios_base::sync_with_stdio(false);

  cin >> n >> c >> q;

  build(1, 0, n - 1);
  col[1].insert({0, n - 1});
  amt[1] = n;

  for(int i = 0; i < q; i++){
    ll p, x, a, b;
    cin >> p >> x >> a >> b;
    int m1 = (a + amt[p]*amt[p])%n;
    int m2 = (a + (amt[p] + b)*(amt[p] + b))%n;

    int l = min(m1, m2), r = max(m1, m2);
    rem(l, r);
    add(l, r, x);
  }

  ll ans = 0;
  for(int i = 1; i <= c; i++)
    ans = max(ans, amt[i]);

  cout << ans << '\n';
}
