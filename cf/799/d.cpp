#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " << 
typedef long long ll;
const int N = 1e5 + 5;
const int M = 17;
const int INF = 0x3f3f3f3f;
int v[N];
int a, b, h, w, n;

vector<pair<pair<int, int>>, int> inc, dec;

int st[4*N];

int query(int p, int l, int r, int i, int j) {
  if (r < i or l > j) return INF;
  if (l >= i and r <= j) return st[p];
  return min(query(2*p, l, (l+r)/2, i, j),
             query(2*p+1, (l+r)/2+1, r, i, j));
}

void update(int p, int l, int r, int i, int v) {
  if(l == r){ st[i] = v; return; }
  int mid = (l + r)/2;
  if(i <= mid) update(2*p, l , mid, i, v);
  else update(2*p + 1, mid + 1, r, i, v);

  st[n] = min(st[2*p], st[2*p + 1]);
}

int ans = INF;

void bt(int i, pair<int, int> sz){
  if(sz.st >= a and sz.nd >= b){
    ans = max(ans, i); return;
  }
  if(i == M){ inc.pb({sz, i}); return; }

  if(sz.st < a) bt(i + 1, {sz.st*v[i], sz.nd});
  if(sz.nd < b) bt(i + 1, {sz.st, sz.nd*v[i]});
}

void bt2(int i, pair<int, int> sz){
  if(i == 2*M){ dec[i].pb({sz, i}); return; }

  if(sz.st > 0) bt2(i + 1, {(sz.st + v[M + i] - 1)/v[M + i], sz.nd});
  if(sz.nd > 0) bt2(i + 1, {sz.st, (sz.nd + v[M + i] - 1)/v[M + i]});
}

int main(){
  cin >> a >> b >> h >> w >> n;

  for(int i = 0; i < n; i++)
    cin >> v[i];
  sort(v, v + n);

  bt(0, {h, w});
  if(ans < INF) return cout << ans << endl, 0;
  bt2(0, {a, b});

  sort(inc.begin(), inc.end());
  sort(dec.begin(), dec.end());

  int i = 0;
  for(auto p : inc){
    while(p.st.st < dec[i].st.st)
      update(1, 1, n, dec[i].st.nd, dec[i].nd);

    ans = min(ans, query(1, 1, n, 0, p.st.nd) + p.nd);
  }

  cout << ans << endl;
}
