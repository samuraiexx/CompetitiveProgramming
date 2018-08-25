#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " << 
typedef long long ll;
const int N = 1e5 + 5;
vector<int> vc[N], vd[N];
pair<int, int> stc[4*N], stdi[4*N];


vector<pair<int, int>> coin, diam;

pair<int, int> getMax(pair<int, int> p1, pair<int, int> p2){
  vector<int> v;
  v.pb(p1.st), v.pb(p1.nd);
  v.pb(p2.st), v.pb(p2.nd);
  sort(v.begin(), v.end(), greater<int>());

  return {v[0], v[1]};
}

void build(int n, int l, int r){
  if(l == r){
    vc[l].pb(0), vc[l].pb(0);
    vd[l].pb(0), vd[l].pb(0);

    sort(vc[l].begin(), vc[l].end(), greater<int>());
    sort(vd[l].begin(), vd[l].end(), greater<int>());

    stc[n] = {vc[l][0], vc[l][1]};
    stdi[n] = {vd[l][0], vd[l][1]};
    return;
  }
  int mid = (l + r)/2;
  build(2*n, l, mid);
  build(2*n + 1, mid + 1, r);

  stc[n] = getMax(stc[2*n], stc[2*n + 1]);
  stdi[n] = getMax(stdi[2*n], stdi[2*n + 1]);
}

pair<int, int> query(int n, int l, int r, int j, pair<int, int> *st){
  if(j < l) return {0, 0};
  if(r <= j) return st[n];
  int mid = (l + r)/2;

  return getMax(query(2*n, l, mid, j, st), query(2*n + 1, mid + 1, r, j, st));
}


int main(){
  int n, c, d;
  cin >> n >> c >> d;

  int mxc = 0, mxd = 0;
  int ans = 0;

  for(int i = 0; i < n; i++){
    int b, p;
    char t;
    cin >> b >> p >> t;

    if(t == 'C'){
      if(p <= c) mxc = max(mxc, b);
      vc[p].pb(b);

      coin.push_back({b, p});
    } else {
      if(p <= d) mxd = max(mxd, b);
      vd[p].pb(b);

      diam.push_back({b, p});
    }
  }

  if(mxc > 0 and mxd > 0)
    ans = mxc + mxd;

  n = 1e5;
  build(1, 1, n);

  for(auto p : coin){
    auto x = query(1, 1, n, c - p.nd, stc);
    int b;

    if(x.st == p.st and c - p.nd >= p.nd)
      b = x.nd;
    else b = x.st;

    if(b > 0) ans = max(ans, b + p.st);
  }

  for(auto p : diam){
    auto x = query(1, 1, n, d - p.nd, stdi);
    int b;

    if(x.st == p.st and d - p.nd >= p.nd)
      b = x.nd;
    else b = x.st;

    if(b > 0) ans = max(ans, b + p.st);
  }

  cout << ans << endl;
}
