#include <bits/stdc++.h>
using namespace std;
 
#define st first
#define nd second
#define mp make_pair
#define pb push_back
#define cl(x, v) memset((x), (v), sizeof(x))
 
#define db(x) cerr << #x << " == " << x << endl
#define dbs(x) cerr << x << endl
#define _ << ", " <<
 
typedef long long ll;
typedef long double ld;
 
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
 
const ld EPS = 1e-9, PI = acos(-1.);
const ll INF = 1e18 + 2, MOD = 1e9+7;
const int N = 2e5+5;
const long long MAX = 1e18;
 
set<pair<long long, long long> > s;
 
int n;
ll v[N];
ll ans;
 
void remove(ll l, ll r) {
  if(l > r or s.empty()) return;
  auto it = s.upper_bound({l, INF});
  if(it == s.begin()) return remove(it->st, r);
  auto it2 = it;

  it--;
  if(l > it->nd){
    if(it2 != s.end()) remove(it2->st, r);
    return;
  }

  if(l == it->st)
    if(it->nd <= r) l = it->nd + 1, s.erase(it), remove(l, r);
    else s.insert({r + 1, it->nd}), s.erase(it);
  else{
    s.insert({it->st, l - 1});
    s.insert({l, it->nd});
    s.erase(it);
    remove(l, r);
  }
}

int main() {
  cin.tie(0), ios_base::sync_with_stdio(false);

  s.insert(mp(1, MAX));

  cin >> n;

  for(int i = 0; i < n; i++) {
    int q, m;
    cin >> q >> m;
    for(int i = 0; i < m; i++) cin >> v[i];

    if(q == 1) {
      sort(v, v+m);
      remove(1, v[0]-1);
      remove(v[m-1]+1, MAX);
      for(int i = 1; i < m; i++) remove(v[i-1]+1, v[i]-1);
    }
    else {
      for(int i = 0; i < m; i++) remove(v[i], v[i]);
    }
  }

  for(auto p: s) {
    ans += (p.nd - p.st + 1);
  }

  cout << ans << '\n';

  return 0;
}
