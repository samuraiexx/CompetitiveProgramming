#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " << 

typedef long long ll;
const int N = 3e5 + 5;;
ll bit[N];
int need[N], ans[N];
bool ok[N];

vector<int> own[N];
tuple<int, int, int> ms[N];

int n, m, k;
int pnt;

ll query(int x){
  ll ans = 0;
  for(int i = x; i > 0; i-=i&-i)
    ans += bit[i];

  return ans;
}

void add(int l, int r, ll amt){
  for(int i = l; i < N; i+=i&-i)
    bit[i] += amt;

  for(int i = r + 1; i < N; i+=i&-i)
    bit[i] -= amt;
}

void cicAdd(int i, bool sub = false){
  int l, r, amt;
  tie(l, r, amt) = ms[i];

  if(sub) amt = -amt;

  if(l <= r) add(l, r, amt);
  else add(1, r, amt), add(l, m, amt);
}

void pbs(int l, int r, vector<int> &v){
  int mid = (l + r)/2;
  while(pnt < mid) cicAdd(++pnt);
  while(pnt > mid) cicAdd(pnt--, true);

  vector<int> lv, rv;
  for(auto st : v){
    ll sum = 0;
    for(auto sec : own[st]){
      sum += query(sec);
      if(sum > 1e9) sum = 1e9;
    }

    if(sum >= need[st]){
      lv.push_back(st);
      ans[st] = mid;
      ok[st] = true;
    }
    else rv.push_back(st);
  }

  if(l == r) return;
  pbs(l, mid, lv);
  pbs(mid + 1, r, rv);
}

int main(){
  cin >> n >> m;

  vector<int> st;

  for(int i = 1; i <= m; i++){
    int station;
    cin >> station;
    own[station].pb(i);
  }

  for(int i = 1; i <= n; i++)
    cin >> need[i], st.pb(i);

  cin >> k;
  for(int i = 1; i <= k; i++){
    int l, r, amt;
    cin >> l >> r >> amt;
    ms[i] = {l, r, amt};
  }

  pbs(1, k, st);
  for(int i = 1; i <= n; i++){
    if(ok[i]) cout << ans[i] << '\n';
    else cout << "NIE\n";
  }
}
