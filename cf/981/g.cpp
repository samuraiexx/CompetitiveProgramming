#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " << 
typedef long long ll;
const int N = 2e5 + 5;
const int mod = 998244353;

struct Query{
  int t, l, r, x;
} qry[N];

set<pair<int, int>> has[N];
vector<int> dif[N];

ll st[4*N]; // ans = a*st + b
ll a[4*N];
ll b[4*N];

void push(int n, int l, int r){
  st[n] = (a[n]*st[n] + b[n]*(r - l + 1))%mod;

  if(l != r){
    a[2*n] = (a[2*n]*a[n])%mod;
    b[2*n] = (b[2*n]*a[n] + b[n])%mod;

    a[2*n + 1] = (a[2*n + 1]*a[n])%mod;
    b[2*n + 1] = (b[2*n + 1]*a[n] + b[n])%mod;
  }

  a[n] = 1, b[n] = 0;
}

void update(int n, int l, int r, int i, int j, ll val, bool mult){
  if(j < i) return;
  push(n, l, r);
  if(i > r or j < l) return;
  if(i <= l and r <= j) { 
    if(mult) a[n] = (a[n]*val)%mod;
    else b[n] = (b[n] + val)%mod;
    push(n, l, r);
  } else {
    int mid = (l + r)/2;
    update(2*n, l, mid, i, j, val, mult);
    update(2*n + 1, mid + 1, r, i, j, val, mult);

    st[n] = (st[2*n] + st[2*n + 1])%mod;
  }
}

ll query(int n, int l, int r, int i, int j){
  push(n , l, r);
  if(i > r or j < l) return ll();
  if(i <= l and r <= j) return st[n];

  int mid = (l + r)/2;
  return (query(2*n, l, mid, i, j) +
          query(2*n + 1, mid + 1, r, i, j))%mod;
}

void build(int n, int l, int r){
  st[n] = 0, a[n] = 1, b[n] = 0;

  if(l != r){
    int mid = (l + r)/2;
    build(2*n, l, mid);
    build(2*n + 1, mid + 1, r);
  }
}

int main(){
  cin.tie(0), ios_base::sync_with_stdio(false);

  int n, q;
  cin >> n >> q;

  build(1, 1, n);

  for(int i = 0; i < q; i++){
    cin >> qry[i].t >> qry[i].l >> qry[i].r;
    if(qry[i].t == 1){
      cin >> qry[i].x;
      dif[qry[i].x].pb(qry[i].l);
      dif[qry[i].x].pb(qry[i].r);
    }
  }

  for(int i = 1; i <= n; i++){
    sort(dif[i].begin(), dif[i].end());
    has[i].insert({0, 0}), has[i].insert({n + 1, n + 1});

    for(auto it = dif[i].begin(); it != dif[i].end(); it++){
      has[i].insert({*it, *it});

      auto nxt = it; nxt++;
      if(nxt == dif[i].end() or *nxt - *it <= 1) continue;
      has[i].insert({*it + 1, *nxt - 1});
    }
  }

  for(int i = 0; i < q; i++){
    auto &q = qry[i];
    if(q.t == 1){
      auto it = has[q.x].lower_bound({q.l, -1}); 
      while(q.l <= q.r){
        update(1, 1, n, q.l, min(it->st - 1, q.r), 2, true);

        int r = it->nd + 1;

        if(it->nd <= q.r){
          update(1, 1, n, it->st, it->nd, 1, false);
          auto it2 = it;
          it++;
          has[q.x].erase(it2);
        }

        q.l = r;
      }
    } else
      cout << query(1, 1, n, q.l, q.r) << '\n';
  }
}
