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

struct Per{
  int b, f;
  ll d;
  bool operator<(Per p) const {
    return b != p.b ? b > p.b : f < p.f; 
  }
}per[N];
ll st[4*N];

void update(int n, int l, int r, int i, ll val){
  if(l == r){
    st[n] = max(st[n], val);
  }else{
    int mid = (l + r)/2;

    if(i <= mid) update(2*n, l, mid, i, val);
    else update(2*n + 1, mid + 1, r, i, val);

    st[n] = max(st[2*n], st[2*n + 1]);
  }
}

ll query(int n, int l, int r, int i, int j){
  if(i > r or j < l) return 0;
  if(i <= l and r <= j) return st[n];
  int mid = (l + r)/2;
  return max(query(2*n, l, mid, i, j),
             query(2*n + 1, mid + 1, r, i, j));
}


int main(){
  ios_base::sync_with_stdio(false), cin.tie(0);

  int n;
  cin >> n;

  vector<int> fort;
  map<pair<int, int>, int> dif;
  for(int i = 0; i < n; i++){
    cin >> per[i].b >> per[i].f >> per[i].d;

    pair<int, int> p = {per[i].b, per[i].f};

    if(dif.count(p)) per[dif[p]].d += per[i].d, i--, n--;
    else dif[p] = i, fort.pb(per[i].f);
  }

  sort(per, per + n);
  sort(fort.begin(), fort.end());
  for(int i = 0; i < n; i++){
    Per p = per[i];
    int pos = lower_bound(fort.begin(), fort.end(), p.f) - fort.begin() + 1;

    ll mx = query(1, 1, n, pos + 1, INF);
    update(1, 1, n, pos, mx + p.d);
  }

  cout << query(1, 1, n, 0, INF) << '\n';
}
